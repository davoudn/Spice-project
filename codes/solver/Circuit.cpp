#include "Circuit.hpp"
#include "Components.hpp"
#include "VoltageSource.hpp"
#include "Integrators.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"
#include "Utility.hpp"
#include "ComplexComponent.hpp"
#include "Components.hpp"
#include <cstdint>

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
	 
     for (uint32_t it=0; it< Components.size(); it++ ){
         if (Components[it]->Type == "VoltageSource"){
			VoltageSourceMap.push_back(it);
		 }
     }
     for (uint32_t it=0; it< Components.size(); it++ ){
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
	for (uint32_t it=0; it< Components.size(); it++ )
	{
		 Resistor* R = nullptr;
		 if (Components[it]->Type == "Resistor"){
			R = static_cast<Resistor*>(Components[it]);
		 }
		 if (Components[it]->componentClass == ComponentClass::Complex){
			R = Components::Cast<ComplexComponent>(Components[it])->R_eq;
		 }
         if (R){
		     // off diagonal
			 A(R->PosNET, R->NegNET) = -R->G;
			 A(R->NegNET, R->PosNET) = -R->G;
			 // diagonal
			 A(R->PosNET, R->PosNET)+=  R->G;
			 A(R->NegNET, R->NegNET)+=  R->G;
		 }
	}

    for (uint32_t id =0; id < VoltageSourceMap.size(); id++)
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
	for (uint32_t node{ 0 }; node < NumNodes; node++) 
	{
		for (uint32_t i{0}; i < CurrentSourceMap.size(); i++){
            int id = CurrentSourceMap[i]; 
			CurrentSource* I = nullptr;
			if (Components[id]->componentClass == ComponentClass::Basic) {
                I = static_cast<CurrentSource*>(Components[id]);
			}
			if (Components[id]->componentClass == ComponentClass::Complex) {
                I = Components::Cast<ComplexComponent>(Components[id])->I_cs;
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
	for (uint32_t id=0; id < VoltageSourceMap.size(); id++){
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
	for (auto base : Components) {
		if (base->componentClass == ComponentClass::Complex){
            auto comp = Components::Cast<ComplexComponent>(base);
			if (comp){
               	comp->integrate();
			}
		}
	}
}
void BaseCircuit::Solve_it() 
{
	X = arma::solve(A, Z);
	return;
}
void BaseCircuit::Solve() 
{

	for (uint32_t it=0; it < MaxIterations; it++) {
		integrate();
		Solve_it();
		populate();
	}

	return;
}
