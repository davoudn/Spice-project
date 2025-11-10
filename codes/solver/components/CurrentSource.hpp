#pragma once
#include "BaseComponent.hpp"

struct CurrentSource : public BaseComponent {
    public:
    CurrentSource(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
        Current   = argparams.get<double>("Current");
    }
    
    double_t Current = 0.f;
    

};