#pragma once 

#include "BaseComponent.hpp"
#include "../Utility.hpp"

struct Resistor : public BaseComponent {
    public:
    Resistor(DParams argparams, map_ptr_t argnodemap);
    
    double g = 0.f;
    
    void Populate(double dv) override;

};