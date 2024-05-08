#include "circuit.hpp"


void BaseCircuit::Init(std::vector<BaseComponent*> _elements) {}

void BaseCircuit::Allocate() {
	//
	nNodes = elements.size();
	vsMap = std::vector< std::vector <int> >(nNodes, std::vector <int>(nNodes,0));
	for (auto el: elements){
				if (el->type == "VS"){
					vsMap[el->t1.nodeId][el->t2.nodeId] = (nNodes + nVsourses);
					vsMap[el->t2.nodeId][el->t1.nodeId] = (nNodes + nVsourses);
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
			for (auto el : table[n1][n2]) {
				if (elements[el]->type == "R")
					_gtmp += 1.0 / el->params["R"];
			}
			_gdiag += _gtmp;
			if (n1 != n2)
				a[n1][n2] = -_gtmp;
		}
		a[n1][n1] = _gdiag;
	}


	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto el : table[n1][n2]    ) {
				  if (elements[el]->type == "VS" && elements[el]->t1.nodeId == n1) {
					a[n1][vsMap[el]] = elements[el]->t1.signe;
				   	a[vsMap[el]][n1] = elements[el]->t1.signe;
			      }
			      if (elements[el]->type == "VS" && elements[el]->t2.nodeId == n1) {
					a[n1][vsMap[el]] = elements[el]->t2.signe;
					a[vsMap[el]][n1] = elements[el]->t2.signe;
				  }
				  
			}
		}
	}
	// the end of A matrix construction block

	// z matrix construction
	double _itmp{0.0};
	for (int n1{ 0 }; n1 < nNodes; n1++) {
		for (int n2{ 0 }; n2 < nNodes; n2++) {
			for (auto el : table[n1][n2]) {
				//
				if (elements[el]->type == "IS" && elements[el]->t1.nodeId == n1) {
					_itmp += elements[el]->params["I"] * elements[el]->t1.signe;
				}
				if (elements[el]->type == "IS" && elements[el]->t2.nodeId == n1) {
					_itmp += elements[el]->params["I"] * elements[el]->t2.signe;
				}
				//
				if (elements[el]->type == "VS") {
					z[vsMap[el]] = elements[el]->params["V"];
				}
			}
		}
		z[n1] = -_itmp;
		_itmp = 0.0;
	}

	return;
}

