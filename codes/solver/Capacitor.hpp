#include "BaseComponent.hpp"


template <typename INTEGRATOR>
struct Capacitor : public BaseComponent {
    public:
    Capacitor(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
              C        = this->Params.get<float>("C");
              V0       = this->Params.get<float>("V0");
              DelT     = this->Params.get<float>("DelT");
	      setupComponent();
    }
    
    void integrate() override;
    void setupComponent () override;
    bool checkComponent() override;
    private:
        double_t C = 0.f;
        double_t V0= 0.f;
        double_t DelT= 0.f;

        INTEGRATOR Integrator;
        double InitialV;
};

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::integrate ()  
{
           double tmp{0.0};
           for (int i{1}; i < Integrator.size(); i++){
                tmp += this->I[this->itLast + 1 - i] * Integrator.CorrectorWeighs[i];
           }
           this->Ieq = -tmp / (this->DelT * Integrator.CorrectorWeighs[0]) - Geq * this->V[ItLast];
}

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::setupComponent ()
{
        this->V.clear();
        this->I.clear();
        this->Geq = C/(this->DelT * Integrator.CorrectorWeighs[0]);
        return;
}

template <typename INTEGRATOR>
bool Capacitor<INTEGRATOR>:: checkComponent ()
{
        return true;
}
