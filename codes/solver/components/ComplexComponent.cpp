
#include "ComplexComponent.hpp"
#include "Resistor.hpp"
#include "CurrentSource.hpp"

ComplexComponent::ComplexComponent(DParams argarams, map_ptr_t nodesmap):BaseComponent( argarams,  nodesmap)
{
        componentClass = ComponentClass::Complex;
}
 
ComplexComponent::~ComplexComponent()
{
}

void ComplexComponent::integrate() 
{

}

void ComplexComponent::populate(double dv) 
	{
		V.push_back(dv);
		auto i = I_cs->Current + dv * R_eq->G;
		I.push_back(i);
	}