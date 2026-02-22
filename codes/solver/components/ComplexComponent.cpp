
#include "ComplexComponent.hpp"
#include "Resistor.hpp"
#include "CurrentSource.hpp"

ComplexComponent::ComplexComponent(DParams argarams, map_ptr_t nodesmap):BaseComponent( argarams,  nodesmap)
{
        componentClass = ComponentClass::Complex;
		resistor_eq = std::make_unique<Resistor>();
		current_cs = std::make_unique<CurrentSource>();
}
 
ComplexComponent::~ComplexComponent()
{
}

void ComplexComponent::Integrate() 
{

}


Resistor* ComplexComponent::GetEquivalentResistor()
{
   return resistor_eq.get();
}
CurrentSource* ComplexComponent::GetEquivalentCurrentSource()
{
      return current_cs.get();
}

void ComplexComponent::Populate(double dv) 
	{
		voltages_.push_back(dv);
		auto i = current_cs->current_ + dv * resistor_eq->g_;
		currents_.push_back(i);
	}