
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

void ComplexComponent::Integrate() 
{

}

void ComplexComponent::Populate(double dv) 
	{
		voltages_.push_back(dv);
		auto i = current_cs->current_ + dv * resistor_eq->g_;
		currents_.push_back(i);
	}