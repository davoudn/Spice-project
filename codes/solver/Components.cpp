#include "Resistor.hpp"
#include "CPE.hpp"
#include "Capacitor.hpp"
#include "BaseComponent.hpp"
#include "VoltageSource.hpp"
#include "Utility.hpp"

namespace Components {

template <typename INTEGRATOR>
BaseComponent* Make(DParams p, DMap<std::string> nodesmap){

    if( _P["Type"] == "Capacitor" ){
		return new Capacitor<INTEGRATOR>(DParams p, DMap<std::string> nodesmap);
	}

	if( _P["Type"] == "Resistor" ){
                return new Resistor<INTEGRATOR>(DParams p, DMap<std::string> nodesmap);
        }

	if( _P["Type"] == "CPE" ){
                return new CPE<INTEGRATOR>(DParams p, DMap<std::string> nodesmap);
        }

	if( _P["Type"] == "Inductor" ){
                return new Capacitor<INTEGRATOR>(DParams p, DMap<std::string> nodesmap);
        }

    if( _P["Type"] == "VoltageSource" ){
                return new VoltageSource<INTEGRATOR>(DParams p, DMap<std::string> nodesmap);
        }

        return nullptr;
}


}