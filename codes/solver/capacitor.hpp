#include "basecomponent.hpp"


template <typename INTEGRATOR>
struct Capacitor : public BaseComponent {
    public:
    Capacitor(){
        this->g_eq = this->params["C"]/(this->del_t * integrator::CorrectorWeighs[0]);
    }
    inline void integrate() override {
           double tmp{0.0};
           for (int i{1}; i < integrator::Nw; i++){
                tmp += this->I[this->it_last + 1 - i] * integrator::CorrectorWeighs[i];
           }
           this->i_eq = -tmp / (this->del_t * integrator::CorrectorWeighs[0]) - g_eq * this->V[it_last];
    }
    private:
        INTEGRATOR integrator;
};