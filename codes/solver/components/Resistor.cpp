#include "Resistor.hpp"


Resistor::Resistor(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap){
        if (argparams.get<float>("R")) {
          G = 1.0/argparams.get<float>("R").value();
        }
    }
    
    
void Resistor::populate(double dv)   
    {
    V.push_back(dv);
		auto i =  dv * G;
		I.push_back(i);
    }
