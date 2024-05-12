#include <string>
#include <map>
#include <vector>
#include <armadillo>
#include "basecomponent.hpp"
//std::string simple_lib_function();

class BaseCircuit {
public:
	void Init(std::vector<DummyStruct> _components);
	void Solve_it() {};
	void Solve();
private:
	std::vector<BaseComponent*> components;
	std::vector<std::vector<std::vector <int>>> table;
	std::map <std::string, double> params;
	std::vector <int>  vsMap;
public:
	arma::Vec<double> z;
	arma::Vec<double> x;
	arma::Mat<double> a;
	
	int nNodes; // number of nodes minus datum
	int nVsourses; // number voltage sources
	int nDim;
	int maxIteration;
	// a x = z
private:
	void CalcDim();
	void MakeAll();
	void Allocate();
	void Populate() ;
	void Integrate();
};