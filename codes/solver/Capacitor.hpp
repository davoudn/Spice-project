#include "basecomponent.hpp"


template <typename INTEGRATOR>
struct Capacitor : public BaseComponent {
    public:
    Capacitor(DummyStruct& _dummyStract){
    }
    
       
    void integrate();
    void SetupComponent (double _del_t);
    bool CheckComponent();
    private:
        INTEGRATOR integrator;
        double initialV;
};

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::integrate()  {
           double tmp{0.0};
           for (int i{1}; i < integrator::Nw; i++){
                tmp += this->I[this->it_last + 1 - i] * integrator::CorrectorWeighs[i];
           }
           this->i_eq = -tmp / (this->del_t * integrator::CorrectorWeighs[0]) - g_eq * this->V[it_last];
    }

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::SetupComponent (double _del_t){
        this->V.clear();
        this->I.clear();
        this->del_t = _del_t;
        this->g_eq = this->params["C"]/(this->del_t * integrator::CorrectorWeighs[0]);
        return;
    }

template <typename INTEGRATOR>
bool Capacitor<INTEGRATOR>:: CheckComponent (){
        return;
    }