#include "basecomponent.hpp"


template <typename INTEGRATOR>
struct Resistor : public BaseComponent {
    public:
    Resistor(){
        this->g_eq = 1.0/this->params["R"];
    }
    inline void integrate() override {
           // do nothing
    }
    private:
     INTEGRATOR integrator;

};