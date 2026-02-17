#include "Components.hpp"


#include <string>
#include <memory>


namespace Components
 {
BaseComponent* Make(DParams& argp, map_ptr_t nodesmap)
{
   if( argp.get<std::string>("Type").value() == "Capacitor" ){
		return new Capacitor<Weights<EULER>>( argp,  nodesmap);
	}

	if( argp.get<std::string>("Type").value() == "Resistor" ){
                return new Resistor( argp, nodesmap);
   }

	if( argp.get<std::string>("Type").value() == "CPE" ){
                return new CPE<Weights<DIETHELM>>( argp, nodesmap);
   }

	if( argp.get<std::string>("Type").value() == "Inductor" ){
                return new Capacitor<Weights<EULER>>( argp,  nodesmap);
   }

   if( argp.get<std::string>("Type").value() == "VoltageSource" ){
                return new VoltageSource( argp, nodesmap);
   }

   if( argp.get<std::string>("Type").value() == "CurrentSource" ){
                return new CurrentSource( argp, nodesmap);
   }
        return nullptr;
}




}