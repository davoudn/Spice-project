#include "Resistor.hpp"
#include "CPE.hpp"
#include "Capacitor.hpp"
#include "BaseComponent.hpp"
#include "VoltageSource.hpp"
#include "Utility.hpp"


namespace Components {

template <typename INTEGRATOR>
BaseComponent* Make(DParams argp, DMap<std::string> nodesmap)
{
        if( argp.get<std::string>("Type") == "Capacitor" ){
		return new Capacitor<INTEGRATOR>( argp,  nodesmap);
	}

	if( argp.get<std::string>("Type") == "Resistor" ){
                return new Resistor( argp, nodesmap);
        }

	if( argp.get<std::string>("Type") == "CPE" ){
                return new CPE<INTEGRATOR>( argp, nodesmap);
        }

	if( argp.get<std::string>("Type") == "Inductor" ){
                return new Capacitor<INTEGRATOR>( argp,  nodesmap);
        }

        if( argp.get<std::string>("Type") == "VoltageSource" ){
                return new VoltageSource( argp, nodesmap);
        }
        if( argp.get<std::string>("Type") == "CurrentSource" ){
                return new CurrentSource( argp, nodesmap);
        }

        return nullptr;
}


template <typename T>
T Cast(BaseComponent* c){
        T t = nullptr;
        if (T::componentClass == ComponentClass::Basic) {
           t = dynamic_cast<T>(c);
        }
        if (T::componentClass == ComponentClass::Complex){
           auto t0 = dynamic_cast<ComplexComponent*>(c);
           if (t0){
                t = dynamic_cast<T>(t0);
           }
        }
        return t;
}

}