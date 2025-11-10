#pragma once 

#include "BaseComponent.hpp"


struct Resistor : public BaseComponent {
    public:
    Resistor(DParams argparams, DMap<std::string> argnodemap);
    
    double G = 0.f;
    
    void populate(double dv) override;

};