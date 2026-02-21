#include "Components.hpp"


#include <string>
#include <memory>
#include <exception>

namespace Components
 {
     MakeError::MakeError(int argid, std::string argname):id_(argid), name_(argname)
     {

     }
    const char* MakeError::what() const noexcept  
    {
      std::string ret_val;
      switch(id_){
         case 0: {
            ret_val = std::string("MakeError::what() : The component") + name_ + std::string("not found");
            break;
         }
      }
      return ret_val.c_str();
    }   

BaseComponent* Make(DParams& argp, map_ptr_t nodesmap)
{
   try {
      argp.Get<std::string>("type");
   } catch(DParamsException& e) {
      std::cout << e.what();
      exit(0);
   }

   if( argp.Get<std::string>("type") == "Capacitor" ){
		return new Capacitor<Weights<EULER>>( argp,  nodesmap);
	}

	if( argp.Get<std::string>("type") == "Resistor" ){
                return new Resistor( argp, nodesmap);
   }

	if( argp.Get<std::string>("type") == "CPE" ){
                return new CPE<Weights<DIETHELM>>( argp, nodesmap);
   }

	if( argp.Get<std::string>("type") == "Inductor" ){
                return new Capacitor<Weights<EULER>>( argp,  nodesmap);
   }

    if( argp.Get<std::string>("type") == "VoltageSource" ){
                return new VoltageSource( argp, nodesmap);
   }

    if( argp.Get<std::string>("type") == "CurrentSource" ){
                return new CurrentSource( argp, nodesmap);
   }
    throw MakeError(0, "Nonexistant component name. ") ;

    return nullptr;
}




}
