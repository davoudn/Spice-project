#pragma once

#include "BaseComponent.hpp"
#include "Utility.hpp"

struct CurrentSource : public BaseComponent {
    public:
    CurrentSource(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap){
        current   = argparams.get<double>("Current");
    }
    
    double current = 0.f;
    virtual void Populate(double dv) override {
    }

};