#pragma once

#include "Utility.hpp"

#include <cstdint>
#include <string>
#include <map>
#include <vector>
#include <armadillo>

class BaseComponent;

class BaseCircuit {
public:
	void Init(std::vector<DParams>& argcomponents);
	void SolveIt();
	void Solve();
private:
   /*
     here we construct a map/invmap to index nodes and components, thus we could 
	 translate the results into the original SPICE naming.
   */
    map_ptr_t nodes_map_;

	/*
	*/
	std::vector<BaseComponent*> components_;
	DMat<int>   connectivity_table_;
	std::vector<int> voltage_source_map_, current_source_map_;
private:	
	// a x = z
	arma::Mat<double> a_;
	arma::Col<double> z_;
	arma::Col<double> x_;
	
	uint32_t num_nodes_ = 0; // number of nodes minus datum
	uint32_t num_voltage_sources_ = 0; // number voltage sources
	uint32_t n_dim_ = 0;
	uint32_t max_iterations_ = 1000; // Default max iterations
private:
	void CalcDim();
	void MakeAll();
	void Allocate();
	void Populate();
	void Integrate();
};
