#pragma once

#include <string>
#include <map>
#include <vector>
#include "basecomponent.hpp"
//std::string simple_lib_function();

class BaseCircuit {
public:
	void Init(std::vector<BaseComponent*> _elements);
	void Solve(){};
private:
	std::vector<BaseComponent*> elements;
	std::vector< std::vector < std::vector <int> > > table;
	std::map <std::string, double> params;
	std::vector <int>  vsMap;
	std::vector<double> x;
	std::vector<double> z;
	std::vector< std::vector<double> > a;
	int nNodes; // number of nodes - datum
	int nVsourses; // number voltage sources
	int nDim;
	// a x = z
	void MakeAll();
	void Allocate();
};