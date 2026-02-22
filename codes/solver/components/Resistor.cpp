#include "Resistor.hpp"


Resistor::Resistor(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap)
{
    g_ = 1.0/argparams.Get<float>("Resistance");
}

Resistor::Resistor(){

}

    
void Resistor::Populate(double dv)   
{
    voltages_.push_back(dv);
		auto i =  dv * g_;
		currents_.push_back(i);
}
