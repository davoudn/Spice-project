#pragma once
#include "Resistor.hpp"
#include "CurrentSource.hpp"
#include "Integrators.hpp"
#include <vector>

template <typename INTEGRATOR>
struct ComplexComponent : public BaseComponent {

ComplexComponent(DParams argarams, DMap<std::string> nodesmap):BaseComponent( argarams,  nodesmap){
        componentClass = ComponentClass::Complex;
}
 Resistor*  R;
 CurrentSource* I;
	virtual void integrate() {};
 protected:
   INTEGRATOR integrator;

};