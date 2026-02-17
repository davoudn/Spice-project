#pragma once

#include "BaseComponent.hpp"
#include "Utility.hpp"

struct CurrentSource : public BaseComponent {
    public:
    CurrentSource(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap){
        Current   = argparams.get<double>("Current").value();
    }
    
    double Current = 0.f;
    

};