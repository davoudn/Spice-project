#pragma once

#include "BaseComponent.hpp"
#include "Utility.hpp"

struct CurrentSource : public BaseComponent {
    public:
    CurrentSource(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap){
        current_   = argparams.Get<double>("Current");
    }
    CurrentSource(){
        
    }

    double current_ = 0.f;
    virtual void Populate(double dv) override {
    }

};
