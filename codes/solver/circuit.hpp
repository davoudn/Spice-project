#include <string>
#include <map>
#include <vector>
#include <armadillo>
#include "basecomponent.hpp"
//std::string simple_lib_function();

class BaseCircuit {
public:
	void Init(std::vector<BaseComponent*> _components);
	void Solve_it() {};
	void Solve();
private:
	std::vector<BaseComponent*> components;
	std::vector<std::vector<std::vector <int>>> table;
	std::map <std::string, double> params;
	std::vector <int>  vsMap;
public:
	//std::vector<double> x;
	//std::vector<double> z;
	arma::Vec<double> z;
	arma::Vec<double> x;
	arma::Mat<double> a;
//	std::vector< std::vector<double> > a;
	
	int nNodes; // number of nodes - datum
	int nVsourses; // number voltage sources
	int nDim;
	int maxIteration;
	// a x = z
private:
	void MakeAll();
	void Allocate();
	void Populate() ;
	void Integrate();
};