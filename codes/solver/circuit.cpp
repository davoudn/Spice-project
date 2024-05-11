#include "circuit.hpp"

void BaseCircuit::CalcDim() {
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
void BaseCircuit::Init(std::vector<BaseComponent*> _elements) {
	CalcDim();
	return;
}
void BaseCircuit::Allocate() {
	
		a.zeros(nDim, nDim); // arma
		x.zeros(nDim); // arma
		z.zeros(nDim);  // arma
		//
		return;
}

void BaseCircuit::MakeAll() {
	Allocate();
    ///////////////////////////////////////////////////
	// making A matrix
    ///////////////////////////////////////////////////
	double _gdiag{ 0.0 }, _gtmp{ 0.0 };
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		_gdiag = 0.0;
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			_gtmp = 0.0;
			for (auto id : table[n1][n2]) {
				if (components[id]->type != "VS" && components[id]->type != "IS")
					_gtmp += components[id]->g_eq;
			}
			_gdiag += _gtmp;
			if (n1 != n2)
				a[n1][n2] = -_gtmp;
		}
		a[n1][n1] = _gdiag;
	}


	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto id : table[n1][n2]) {
				if (components[id]->type == "VS" && components[id]->nodePos == n1) {
					a[n1][vsMap[id]] = 1;
					a[vsMap[id]][n1] = 1;
				}
				if (components[id]->type == "VS" && components[id]->nodeNeg == n1) {
					a[n1][vsMap[id]] = -1;
					a[vsMap[id]][n1] = -1;
				}

			}
		}
	}
	// the end of A matrix construction block
    //////////////////////////////////////////////////////////////////
	// z matrix construction
    //////////////////////////////////////////////////////////////////
	double _itmp{ 0.0 };
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto id : table[n1][n2]) {
				//
				if (components[id]->type != "VS" && components[id]->nodePos == n1) {
					_itmp += components[id]->i_eq;
				}
				if (components[id]->type != "VS" && components[id]->nodeNeg == n1) {
					_itmp -= components[id]->i_eq;
				}
				//
				if (components[id]->type == "VS") {
					z[vsMap[id]] = components[id]->params["V"];
				}
			}
		}
		z[n1] = -_itmp;
		_itmp = 0.0;
	}
    /////////////////////////////////////////////////////////////////////
	return;
}

void BaseCircuit::Populate() {
	for (auto comp : components) {
		auto dv = x[comp->nodePos] - x[comp->nodePos];
		comp->Populate(dv);
	}
}

void BaseCircuit::Integrate() {
	for (auto comp : components) {
		comp->integrate();
	}
}
void::Solve_it() {
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
