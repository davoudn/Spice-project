#pragma once 

#include "ComplexComponent.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"
#include "Utility.hpp"

#include<cmath>

struct Resistor;
struct CurrentSource;

template <typename INTEGRATOR>
struct CPE: public ComplexComponent {
    public:
    CPE(DParams argparams, map_ptr_t argnodemap);
    
    void Integrate() override;
    void SetupComponent() override;
    bool CheckComponent() override;
    double c_ = 0.0, alpha_ = 0.0 , gamma_ = 0.0, inv_gamma_ = 0.0, v0_ = 0.0, del_tau_ = 0.0;

    private:
        INTEGRATOR integrator_;
};

template <typename INTEGRATOR>
CPE<INTEGRATOR>::CPE(DParams argparams, map_ptr_t argnodemap):ComplexComponent(argparams, argnodemap)
{
              alpha_     = this->params_.Get<float>("Alpha");
              c_         = this->params_.Get<float>("C");
              v0_        = this->params_.Get<float>("V0");
              del_tau_   = this->params_.Get<float>("DelT");
              gamma_     = std::tgamma(alpha_);
              inv_gamma_ = 1.0/std::tgamma(alpha_);
              integrator_.Init(alpha_, del_tau_);
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::Integrate()  
{
           double sum{0.0};
           int k = this->currents_.size();
           for (int i{0}; i < k; i++){
                sum += this->currents_[i] * integrator_.corrector(i,k);
           }
           current_cs->current_ = - v0_ * gamma_ * c_ / integrator_.corrector(k,k) - sum / integrator_.corrector(k,k) ;
           resistor_eq->g_ = gamma_ * c_ / integrator_.corrector(1,1);
}

/// @brief 
/// @tparam INTEGRATOR 
template <typename INTEGRATOR>
void CPE<INTEGRATOR>::SetupComponent()
{
        this->voltages_.clear();
        this->currents_.clear();
        return;
}

template <typename INTEGRATOR>
bool CPE<INTEGRATOR>::CheckComponent(){
        return true;
}
