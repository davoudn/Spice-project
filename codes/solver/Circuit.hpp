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
   /*
     here we construct a map/invmap to index nodes and components, thus we could 
	 translate the results into the original SPICE naming.
   */
    DMap ComponentsMap, NodesMap;

	/*
	*/
	std ::map<int, BaseComponent*> Components;
	arma::Mat<int> ConnectivityTable;
	arma::Mat<int> VoltageSourceMap;
public:	
	// a x = z
	arma::Mat<double> A;
	arma::Col<double> Z;
	arma::Col<double> X;
	
	int NumNodes = 0; // number of nodes minus datum
	int NumVolatgeSourses = 0; // number voltage sources
	int nDim = 0;
	int MaxIterations = 0;
private:
	void CalcDim();
	void MakeAll();
	void Allocate();
	void Populate();
	void Integrate();
};
