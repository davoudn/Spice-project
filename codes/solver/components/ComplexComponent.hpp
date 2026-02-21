#pragma once

#include "CurrentSource.hpp"
#include "Utility.hpp"
#include <vector>
class Resistor;
class CurrentSource;

struct ComplexComponent : public BaseComponent {

ComplexComponent(DParams argarams, map_ptr_t nodesmap);
virtual ~ComplexComponent();
virtual void Integrate();

Resistor*  resistor_eq = nullptr;
CurrentSource* current_cs = nullptr;
 
virtual void SetupComponent (){};
virtual bool CheckComponent (){return true;};
virtual void Populate(double dv) override; 
	
};