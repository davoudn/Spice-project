#include <string>
#include <map>
#include <vector>
#include <armadillo>
#include "BaseComponent.hpp"
#include "Utility.hpp"

class BaseCircuit {
public:
	template<typename INTEGRATOR>
	void Init(std::vector<DummyStruct> _components);
	void Solve_it() {};
	void Solve();
private:
        Map ComponentsMap, NodesMap;
	std ::map<int, BaseComponent*> Components;
	arma::Mat<int> ConnectivityTable;
	arma::Mat<int> VoltageSourceMap;
public:
	arma::Vec<double> z;
	arma::Vec<double> x;
	arma::Mat<double> a;
	
	int NumNodes; // number of nodes minus datum
	int NumVolatgeSourses; // number voltage sources
	int nDim;
	int MaxIterations;
	// a x = z
private:
	void CalcDim();
	void MakeAll();
	void Allocate();
	void Populate();
	void Integrate();
};
