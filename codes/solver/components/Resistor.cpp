#include "Resistor.hpp"


Resistor::Resistor(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap)
{
          g = 1.0/argparams.get<float>("Resistance");
}
    
void Resistor::Populate(double dv)   
{
    voltages.push_back(dv);
		auto i =  dv * g;
		currents.push_back(i);
}
