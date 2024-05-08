#include "basecomponent.hpp"


template <typename INTEGRATOR>
struct Resistor : public BaseComponent {
    public:
    Resistor(){
        this->g_eq = 1.0/this->params["C"];
    }
    inline void integrate(){
           // do nothing
    }
    private:
     INTEGRATOR integrator;

};