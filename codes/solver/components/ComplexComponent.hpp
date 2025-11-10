#pragma once

#include "CurrentSource.hpp"
#include <vector>
class Resistor;
class CurrentSource;

struct ComplexComponent : public BaseComponent {

ComplexComponent(DParams argarams, DMap<std::string> nodesmap);
virtual ~ComplexComponent();
virtual void integrate();

Resistor*  R_eq = nullptr;
CurrentSource* I_cs = nullptr;
 
virtual void setupComponent (){};
virtual bool checkComponent (){return true;};
virtual void populate(double dv) override; 
	
};