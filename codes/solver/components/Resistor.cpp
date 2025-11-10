#include "Resistor.hpp"


Resistor::Resistor(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
        G = 1.0/argparams.get<float>("R");
    }
    
    
void Resistor::populate(double dv)   
    {
    V.push_back(dv);
		auto i =  dv * G;
		I.push_back(i);
    }
