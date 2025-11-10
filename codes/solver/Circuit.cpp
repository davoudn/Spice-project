#include "Circuit.hpp"
#include "Components.hpp"
#include "VoltageSource.hpp"
#include "Integrators.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"
#include "Utility.hpp"
#include "ComplexComponent.hpp"
#include "Components.hpp"

template<typename INTEGRATOR>
void BaseCircuit::Init(std::vector<DParams> _Components) 
{
	//
     int c = 0;
     for (auto& x: _Components) {
        if ( NodesMap.add(x.get<std::string>("PosNET"), c) ){
        	c++;
		}
		if ( NodesMap.add(x.get<std::string>("NegNET"), c) ){
			c++;
		}
     }
	//
     for (auto& x: _Components){
         Components.push_back( Components::Make<INTEGRATOR>(x, NodesMap));
     }

     //
     ConnectivityTable.resize(NodesMap.size());
	 c = 0;
     for (auto& x: Components) {
	     int Pos = x->PosNET;
	     int Neg = x->NegNET;
	     ConnectivityTable(Pos, Neg) = c;
		 ConnectivityTable(Neg, Pos) = c;
		 c++;
     }
	 
     for (int it=0; it< Components.size(); it++ ){
         if (Components[it]->Type == "VoltageSource"){
			VoltageSourceMap.push_back(it);
		 }
     }
     for (int it=0; it< Components.size(); it++ ){
         if (Components[it]->Type == "CurrentSource" || Components[it]->componentClass == ComponentClass::Complex){
			CurrentSourceMap.push_back(it);
		 }
     }
	  
     nDim = VoltageSourceMap.size() + NodesMap.size();
	 NumNodes = NodesMap.size();
     return;
}
//
void BaseCircuit::Allocate() 
{
	
		A.zeros(nDim, nDim); // arma
		X.zeros(nDim); // arma
		Z.zeros(nDim);  // arma
		//
		return;
}

void BaseCircuit::MakeAll() 
{
	Allocate();
    /*                                                 
     *********************  making A matrix  ***************************
    */
	double gdiag{ 0.0 }, gtmp{ 0.0 };
	for (int it=0; it< Components.size(); it++ ){
         if (Components[it]->Type == "Resistor"){
		     // off diagonal
			 A(Components[it]->PosNET, Components[it]->NegNET) = -static_cast<Resistor*>(Components[it])->G;
			 // diagonal
			 A(Components[it]->PosNET, Components[it]->PosNET)+=  static_cast<Resistor*>(Components[it])->G;
			 A(Components[it]->NegNET, Components[it]->NegNET)+=  static_cast<Resistor*>(Components[it])->G;
		 }
		 else {
			if (Components[it]->componentClass==ComponentClass::Complex){
				auto cmp = Cast<ComplexComponent<Null>*>(Components[it]);
				A(cmp->PosNET, cmp->NegNET) = -cmp->G;
			 // diagonal
			 	A(cmp->PosNET, cmp->PosNET)+=  cmp->G;
			 	A(cmp->NegNET, cmp->NegNET)+=  cmp->G;
			}
		 }
     }
	/*
	for (int n1{ 0 }; n1 < NumNodes; n1++) {
		gdiag = 0.0;
		for (int n2{ 0 }; n2 < NumNodes; n2++) {
			gtmp = 0.0;
			int id = ConnectivityTable(n1, n2);
			if ( id > 0) {
				if (Components[id]->Type != "VoltageSource" && Components[id]->Type != "CurrentSource")
					gtmp += Components[id]->Geq;
			}
			gdiag += gtmp;
			if (n1 != n2)
				A(n1, n2) = -gtmp;
		}
		A(n1, n1) = gdiag;
	}
*/
    for (int id =0; id < VoltageSourceMap.size(); id++)
	{
					A(id + NumNodes, Components[VoltageSourceMap[id]]->PosNET) =+1;
					A(id + NumNodes, Components[VoltageSourceMap[id]]->NegNET) =-1;
					//
					A(Components[VoltageSourceMap[id]]->PosNET, id + NumNodes) =+1;
					A(Components[VoltageSourceMap[id]]->NegNET, id + NumNodes) =-1;
	}

    /* the end of A matrix construction block */
    /*
	************************** z matrix construction *****************************
    */
	double itmp{ 0.0 };
	for (int node{ 0 }; node < NumNodes; node++) 
	{
		for (int i{0}; i < CurrentSourceMap.size(); i++){
            int id = CurrentSourceMap[i];
			CurrentSource* I = nullptr;
			if (Components[id]->componentClass == ComponentClass::Basic) {
                I = static_cast<CurrentSource*>(Components[id]);
			}
			if (Components[id]->componentClass == ComponentClass::Complex) {
                I = Cast<ComplexComponent<Null>*>(Components[id])->I;
			}
			if (I){
				if ( Components[id]->PosNET == node ){
					itmp+= I->Current;
				}
				if ( Components[id]->NegNET == node ){
					itmp-= I->Current;
				}
			}
		}

		Z(node) = -itmp;
		itmp = 0.0;
	}
	for (int id=0; id < VoltageSourceMap.size(); id++){
		 Z(NumNodes + id) = static_cast<VoltageSource*>(Components[VoltageSourceMap[id]])->Voltage;
	}
    /*
     * ********************************************************************************
     * */
	return;
}

void BaseCircuit::populate() 
{
	for (auto comp : Components) {
		auto dv = X[comp->PosNET] - X[comp->NegNET];
		comp->populate(dv);
	}
}

void BaseCircuit::integrate() 
{
	for (auto comp : Components) {
		comp->integrate();
	}
}
void BaseCircuit::Solve_it() 
{
	X = arma::solve(A, Z);
	return;
}
void BaseCircuit::Solve() 
{

	for (int it=0; it < MaxIterations; it++) {
		integrate();
		Solve_it();
		populate();
	}

	return;
}
