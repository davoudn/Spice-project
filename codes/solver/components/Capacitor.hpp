#pragma once 
#include "ComplexComponent.hpp"

struct Resistor;
struct CurrentSource;

template <typename INTEGRATOR>
struct Capacitor : public ComplexComponent {
    public:
    Capacitor(DParams argparams, DMap<std::string> argnodemap):ComplexComponent(argparams, argnodemap){
              C        = this->Params.get<float>("C");
              V0       = this->Params.get<float>("V0");
              DelT     = this->Params.get<float>("DelT");
    }
    
    void integrate() override;
    void setupComponent () override;
    bool checkComponent() override;
    private:
        double C    = 0.f;
        double V0   = 0.f;
        double DelT = 0.f;

        INTEGRATOR Integrator;
        double InitialV;
};

