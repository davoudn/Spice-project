#include "BaseComponent.hpp"
#include "Utility.hpp"

#include <cstdint>
#include <string>
#include <map>
#include <vector>
#include <armadillo>


class BaseCircuit {
public:
	template<typename INTEGRATOR>
	void Init(std::vector<DParams> argcomponents);
	void Solve_it();
	void Solve();
private:
   /*
     here we construct a map/invmap to index nodes and components, thus we could 
	 translate the results into the original SPICE naming.
   */
    DMap<std::string> ComponentsMap, NodesMap;

	/*
	*/
	std::vector<BaseComponent*> Components;
	DMat<int>   ConnectivityTable;
	std::vector<int> VoltageSourceMap, CurrentSourceMap;
public:	
	// a x = z
	arma::Mat<double> A;
	arma::Col<double> Z;
	arma::Col<double> X;
	
	uint32_t NumNodes = 0; // number of nodes minus datum
	uint32_t NumVolatgeSourses = 0; // number voltage sources
	uint32_t nDim = 0;
	uint32_t MaxIterations = 0;
private:
	void CalcDim();
	void MakeAll();
	void Allocate();
	void populate();
	void integrate();
};
