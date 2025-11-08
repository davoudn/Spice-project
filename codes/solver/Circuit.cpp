#include "Circuit.hpp"
#include "Components.hpp"
#include "VoltageSource.hpp"
#include "Integrators.hpp"

template<typename INTEGRATOR>
void BaseCircuit::Init(std::vector<DParams> _Components) 
{
	//
     c = 0;
     for (auto& x: _Components) {
        if ( NodesMap.Add(x.params["PosNET"], c) ){
        	c++;
		}
		if ( NodesMap.Add(x.params["NegNET"], c) ){
			c++;
		}
     }
	//
     for (auto& x: _Components){
         Components.push_back( Components::Make<INTEGRATOR>(x, NodesMap));
     }

     //
     ConnectivityTable.resize(NodesMap.Size(), NodesMap.Size());
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
     nDim = VoltageSourceMap.size() + NodesMap.Size();
	 NumNodes = NodesMap.Size();
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
	for (int n1{ 0 }; n1 < NumNodes; n1++) {
		for (int n2{ 0 }; n2 < NumNodes; n2++) {
			int id = ConnectivityTable(n1, n2);
			if ( id > 0) {
				//
				if (Components[id]->Type != "VoltageSource"  && Components[id]->PosNET == n1) {
					itmp += Components[id]->Ieq;
				}
				if (Components[id]->Type != "VolatageSource" && Components[id]->NegNET == n1) {
					itmp -= Components[id]->Ieq;
				}
			}
		}
		Z(n1) = -itmp;
		itmp = 0.0;
	}
	for (int id=0; id < VoltageSourceMap.size(); id++){
		 Z(NumNodes + id) = static_cast<VoltageSource<Null>*>(Components[VoltageSourceMap[id]])->Voltage;
	}
    /*
     * ********************************************************************************
     * */
	return;
}

void BaseCircuit::Populate() 
{
	for (auto comp : Components) {
		auto dv = X[comp->PosNET] - X[comp->NegNET];
		comp->Populate(dv);
	}
}

void BaseCircuit::Integrate() 
{
	for (auto comp : Components) {
		comp->Integrate();
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
		Integrate();
		Solve_it();
		Populate();
	}

	return;
}
