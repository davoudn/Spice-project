#include "Components.hpp"


#include <string>
#include <memory>
#include <exception>

namespace Components
 {
     MakeError::MakeError(int argid, std::string argname):id(argid), name(argname)
     {

     }
    const char* MakeError::what() const noexcept  
    {
      std::string ret_val;
      switch(id){
         case 0: {
            ret_val = std::string("MakeError::what() : The component") + name + std::string("not found");
            break;
         }
      }
      return ret_val.c_str();
    }   

BaseComponent* Make(DParams& argp, map_ptr_t nodesmap)
{
   if( argp.get<std::string>("type") == "Capacitor" ){
		return new Capacitor<Weights<EULER>>( argp,  nodesmap);
	}

	if( argp.get<std::string>("type") == "Resistor" ){
                return new Resistor( argp, nodesmap);
   }

	if( argp.get<std::string>("type") == "CPE" ){
                return new CPE<Weights<DIETHELM>>( argp, nodesmap);
   }

	if( argp.get<std::string>("type") == "Inductor" ){
                return new Capacitor<Weights<EULER>>( argp,  nodesmap);
   }

   if( argp.get<std::string>("type") == "VoltageSource" ){
                return new VoltageSource( argp, nodesmap);
   }

   if( argp.get<std::string>("type") == "CurrentSource" ){
                return new CurrentSource( argp, nodesmap);
   }
   throw MakeError(0, argp.get<std::string>("Type")) ;

   return nullptr;
}




}