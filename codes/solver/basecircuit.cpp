#include "circuit.hpp"


void BaseCircuit::Init(std::vector<BaseComponent*> _elements) {}

void BaseCircuit::Allocate() {
	//
	nNodes = 0;
	vsMap = std::vector <int> (elements.size(), -1);
	for (int id{0}; id < elements.size(); id++){
				if (elements[id]->type == "VS"){
					vsMap[id] = (nNodes + nVsourses);
					nVsourses++;
			}
	nDim = nNodes + nVsourses;
	a = std::vector< std::vector<double> >(nDim, std::vector<double>(nDim, 0.0));
	x = std::vector<double>(nDim, 0.0);
	z = std::vector<double>(nDim, 0.0);
	//
    }
}

void BaseCircuit:: MakeAll(){
	// making A matrix
	double _gdiag{ 0.0 }, _gtmp{ 0.0 };
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		_gdiag = 0.0;
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			_gtmp = 0.0;
			for (auto id : table[n1][n2]) {
				if (elements[id]->type == "R")
					_gtmp += 1.0 / elements[id]->params["R"];
			}
			_gdiag += _gtmp;
			if (n1 != n2)
				a[n1][n2] = -_gtmp;
		}
		a[n1][n1] = _gdiag;
	}


	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto id : table[n1][n2]    ) {
				  if (elements[id]->type == "VS" && elements[id]->t1.nodeId == n1) {
					a[n1][vsMap[id]] = elements[id]->t1.signe;
				   	a[vsMap[id]][n1] = elements[id]->t1.signe;
			      }
			      if (elements[id]->type == "VS" && elements[id]->t2.nodeId == n1) {
					a[n1][vsMap[id]] = elements[id]->t2.signe;
					a[vsMap[id]][n1] = elements[id]->t2.signe;
				  }
				  
			}
		}
	}
	// the end of A matrix construction block

	// z matrix construction
	double _itmp{0.0};
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto id : table[n1][n2]) {
				//
				if (elements[id]->type == "IS" && elements[id]->t1.nodeId == n1) {
					_itmp += elements[id]->params["I"] * elements[id]->t1.signe;
				}
				if (elements[id]->type == "IS" && elements[id]->t2.nodeId == n1) {
					_itmp += elements[id]->params["I"] * elements[id]->t2.signe;
				}
				//
				if (elements[id]->type == "VS") {
					z[vsMap[id]] = elements[id]->params["V"];
				}
			}
		}
		z[n1] = -_itmp;
		_itmp = 0.0;
	}

	return;
}

