#pragma once

#include "BaseComponent.hpp"
#include "Utility.hpp"
struct VoltageSource : public BaseComponent {
    public:
    VoltageSource(DParams argparams, map_ptr_t argnodemap):BaseComponent(argparams, argnodemap){
        voltage_   = argparams.Get<double>("Voltage");
    }

    double_t voltage_ = 0.f;
	virtual void Populate(double dv) override {
    }
};
