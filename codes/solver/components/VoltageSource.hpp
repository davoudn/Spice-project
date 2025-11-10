#pragma once

#include "BaseComponent.hpp"

struct VoltageSource : public BaseComponent {
    public:
    VoltageSource(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
        Voltage   = argparams.get<double>("Voltage");
    }

    double_t Voltage = 0.f;

};