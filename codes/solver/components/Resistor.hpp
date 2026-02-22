#pragma once 

#include "BaseComponent.hpp"
#include "Utility.hpp"

struct Resistor : public BaseComponent {
    public:
    Resistor(DParams argparams, map_ptr_t argnodemap);
    Resistor();

    
    void Populate(double dv) override;
        double g_ = 0.f;

};
