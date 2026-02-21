#pragma once 
#include "ComplexComponent.hpp"
#include "Utility.hpp"
#include "Resistor.hpp"
#include "CurrentSource.hpp"


template <typename INTEGRATOR>
struct Capacitor : public ComplexComponent {
    public:
    Capacitor(DParams argparams, map_ptr_t argnodemap);
    
    void Integrate() override;
    void SetupComponent() override;
    bool CheckComponent() override;
    private:
        double c_    = 0.f;
        double v0_   = 0.f;

        INTEGRATOR integrator_;
        double initial_v_;
};


template <typename INTEGRATOR>
Capacitor<INTEGRATOR>::Capacitor(DParams argparams, map_ptr_t argnodemap):ComplexComponent(argparams, argnodemap)
{
              c_        = this->params_.Get<float>("C");
              v0_       = this->params_.Get<float>("V0");
              del_tau_     = this->params_.Get<float>("DelT");
}
template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::Integrate()  
{
           double tmp{0.0};
           for (int i{1}; i < integrator_.Nw; i++){
                tmp += currents_[it_last_ + 1 - i] * integrator_.CorrectorWeighs[i];
           }
           current_cs->current_ = -tmp / (this->del_tau_ * integrator_.CorrectorWeighs[0]) - resistor_eq->g_* this->voltages_[it_last_];
}

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::SetupComponent()
{
        this->voltages_.clear();
        this->currents_.clear();
        resistor_eq->g_ = c_/(this->del_tau_ * integrator_.CorrectorWeighs[0]);
        return;
}

template <typename INTEGRATOR>
bool Capacitor<INTEGRATOR>::CheckComponent()
{
        return true;
}
