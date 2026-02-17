#pragma once 

#include "BaseComponent.hpp"
#include "../Utility.hpp"

struct Resistor : public BaseComponent {
    public:
    Resistor(DParams argparams, map_ptr_t argnodemap);
    
    double G = 0.f;
    
    void populate(double dv) override;

};