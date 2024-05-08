#pragma once

#include <string>
#include <map>
#include <vector>
//std::string simple_lib_function();

namespace local {
	struct pair {
		pair(int _n1, int _n2):n1(_n1), n2(_n2) {}
		int n1, n2;
	};
}

struct Terminal {
	int nodeId;
	int signe;
};

struct SPICE {};
struct Element {
	Terminal t1, t2;
	std::string label, type;
	std::map<std::string, double> params;
};


class Circuit {
public:
	void Init(SPICE& spice);
private:
	std::vector<Element> elements;
	std::vector< std::vector < std::vector <int> > > table;
	std::vector< std::vector <int> > vsMap;
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