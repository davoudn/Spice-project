#include "Circuit.hpp"
#include ""

/*void BaseCircuit::CalcDim() {
	//
	nNodes = 0;
	vsMap = std::vector <int>(components.size(), -1);
	for (int id{ 0 }; id < components.size(); id++) {
		if (components[id]->type == "VS") {
			vsMap[id] = (nNodes + nVsourses);
			nVsourses++;
		}
		nDim = nNodes + nVsourses;
		return;
	}
}
*/

template<typename INTEGRATOR>
void BaseCircuit::Init(std::vector<DummyStruct> _Components) {
     //	
     int c = 0;
     for (auto& x: _Components) {
        ComponentsMap.Add(x["name"], c);    
        c++;	
     }
     //
     c = 0;
     for (auto& x: _Components) {
        if ( NodesMap.Add(x["PosNET"], c) ){
        	c++;
	}
	if ( NodesMap.Add(x["NegNET"], c) ){
		c++;
	}
     }
     //
     ConnectivityTable.zeros(NodesMap.Size(), NodesMap.Size());
     for (auto& x: _Components) {
	     int Pos = NodesMap.Get(x["PosNET"]);
	     int Neg = NodesMap.Get(x["NegNET"]);
	     ConnectivityTable[Pos][Neg] = ComponentsMap.Get(x["Name"]);
     }
     //
     for (auto& x: _Components){
         Components.Emplace( Make<INTEGRATOR>(x));
     }
     return;
}
//
void BaseCircuit::Allocate() {
	
		a.zeros(nDim, nDim); // arma
		x.zeros(nDim); // arma
		z.zeros(nDim);  // arma
		//
		return;
}

void BaseCircuit::MakeAll() {
	Allocate();
    /*                                                 
     *********************  making A matrix  ***************************
    */
	double _gdiag{ 0.0 }, _gtmp{ 0.0 };
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		_gdiag = 0.0;
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			_gtmp = 0.0;
			for (auto id : table[n1][n2]) {
				if (components[id]->Type != "VS" && components[id]->Type != "IS")
					_gtmp += components[id]->Geq;
			}
			_gdiag += _gtmp;
			if (n1 != n2)
				A[n1][n2] = -_gtmp;
		}
		A[n1][n1] = _gdiag;
	}


	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto id : table[n1][n2]) {
				if (components[id]->type == "VolatageSource" && components[id]->PosNET == n1) {
					A[n1][vsMap[id]] = 1;
					A[vsMap[id]][n1] = 1;
				}
				if (components[id]->type == "VolatageSource" && components[id]->NegNET == n1) {
					A[n1][vsMap[id]] = -1;
					A[vsMap[id]][n1] = -1;
				}

			}
		}
	}
    /* the end of A matrix construction block */
    /*
	************************** z matrix construction *****************************
    */
	double _itmp{ 0.0 };
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto id : table[n1][n2]) {
				//
				if (components[id]->type != "VoltageSource"  && components[id]->PosNET == n1) {
					_itmp += components[id]->i_eq;
				}
				if (components[id]->type != "VolatageSource" && components[id]->NegNET == n1) {
					_itmp -= components[id]->i_eq;
				}
				//
				if (components[id]->type == "VoltageSource") {
					z[vsMap[id]] = components[id]->params["V"];
				}
			}
		}
		z[n1] = -_itmp;
		_itmp = 0.0;
	}
    /*
     * ********************************************************************************
     * */
	return;
}

void BaseCircuit::Populate() {
	for (auto comp : components) {
		auto dv = x[comp->nodePos] - x[comp->nodeNeg];
		comp->Populate(dv);
	}
}

void BaseCircuit::Integrate() {
	for (auto comp : components) {
		comp->integrate();
	}
}
void BaseCircuit::Solve_it() {
	x = arma::Solve(A, z, solve_opts::refine);
	return;
}
void BaseCircuit::Solve() {

	for (int it; it < maxIteration; it++) {
		Integrate();
		Solve_it();
		Populate();
	}

	return;
}
