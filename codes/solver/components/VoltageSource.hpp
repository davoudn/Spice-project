#pragma once

#include "BaseComponent.hpp"
#include "Utility.hpp"
struct VoltageSource : public BaseComponent {
    public:
    VoltageSource(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap){
        Voltage   = argparams.get<double>("Voltage");
    }

    double_t Voltage = 0.f;
	virtual void Populate(double dv) override {
    }
};