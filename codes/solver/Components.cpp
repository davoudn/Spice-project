#include "Resistor.hpp"
#include "CPE.hpp"
#include "Capacitor.hpp"
#include "BaseComponent.hpp"
#include "VoltageSource.hpp"
#include "Utility.hpp"

namespace Components
 {

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




}