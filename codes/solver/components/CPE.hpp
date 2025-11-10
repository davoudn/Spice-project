#pragma once 

#include "ComplexComponent.hpp"
#include "Integrators.hpp"
struct Resistor;
struct CurrentSource;

template <typename INTEGRATOR>
struct CPE : public ComplexComponent {
    public:
    CPE(DParams argparams, DMap<std::string> argnodemap);
    
    void integrate() override;
    void setupComponent () override;
    bool checkComponent() override;
            double C = 0.0, Alpha = 0.0 , Gamma = 0.0, InvGamma = 0.0, V0 = 0.0, DelT = 0.0;

    private:
        Weights<INTEGRATOR> Integrator;
};

