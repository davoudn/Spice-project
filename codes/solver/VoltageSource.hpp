#include "BaseComponent.hpp"

template <typename INTEGRATOR>
struct VoltageSource : public BaseComponent {
    public:
    VoltageSource(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
        this->Geq = 0;
        this->Ieq = 0;
    }
    inline void integrate() override {
           // do nothing
    }
    double_t Voltage = 0.f;
    private:
     INTEGRATOR integrator;

};