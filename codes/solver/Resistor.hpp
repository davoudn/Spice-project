#include "BaseComponent.hpp"


template <typename INTEGRATOR>
struct Resistor : public BaseComponent {
    public:
    Resistor(){
        this->Geq = 1.0/this->Params.Get<float>("R");
    }
    inline void integrate() override {
           // do nothing
    }
    private:
     INTEGRATOR integrator;

};