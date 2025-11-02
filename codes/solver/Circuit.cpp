#include "Circuit.hpp"
#include "Components.hpp"


template<typename INTEGRATOR>
void BaseCircuit::Init(std::vector<DummyStruct> _Components) 
{
     //	
     int c = 0;
     for (auto& x: _Components) {
        ComponentsMap.Add(x.params["Name"], c);    
        c++;	
     }
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
     ConnectivityTable.zeros(NodesMap.Size(), NodesMap.Size());
     for (auto& x: _Components) {
	     int Pos = NodesMap.Get(x.params["PosNET"]);
	     int Neg = NodesMap.Get(x.params["NegNET"]);
	     ConnectivityTable(Pos,Neg) = ComponentsMap.Get(x.params["Name"]);
     }
     //
     for (auto& x: _Components){
         Components.emplace( Components::Make<INTEGRATOR>(x));
     }
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


	for (int n1{ 0 }; n1 < NumNodes; n1++) {
		for (int n2{ 0 }; n2 < NumNodes; n2++) {
			int id = ConnectivityTable(n1, n2);
			if ( id > 0 ) {
				if (Components[id]->Type == "VolatageSource" && Components[id]->PosNET == n1) {
					A(n1, VoltageSourceMap[id]) = 1;
					A(VoltageSourceMap[id], n1) = 1;
				}
				if (Components[id]->Type == "VolatageSource" && Components[id]->NegNET == n1) {
					A(n1, VoltageSourceMap[id]) = -1;
					A(VoltageSourceMap[id], n1) = -1;
				}
			}
		}
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
				if (Components[id]->Type == "VoltageSource") {
					Z(VoltageSourceMap[id]) = Components[id]->Params.Get<float>("V");
				}
			}
		}
		Z(n1) = -itmp;
		itmp = 0.0;
	}
    /*
     * ********************************************************************************
     * */
	return;
}

void BaseCircuit::Populate() 
{
	for (auto comp : Components) {
		auto dv = X[comp.second->PosNET] - X[comp.second->NegNET];
		comp.second->Populate(dv);
	}
}

void BaseCircuit::Integrate() 
{
	for (auto comp : Components) {
		comp.second->Integrate();
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
