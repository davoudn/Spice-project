#include "Utility.hpp"




 DParamsException::DParamsException(int argid, std::string argname):id(argid), name(argname)
     {

     }
    const char* DParamsException::what() const noexcept  
    {
      std::string ret_val;
      switch(id){
         case 0: {
            ret_val = std::string("DParamsException::what() : the parameted=r ") + name + std::string("not found");
            break;
         }
      }
      return ret_val.c_str();
    }   


DParams::DParams(data_t argdata):data(argdata)
{
}

template<>
std::string DParams::get<std::string>(std::string argpname)
{
      if (auto result = data.find(argpname); result == data.end()){
         throw DParamsException(0, argpname);
         return std::string();
      } else {
         return result->second;
      }
}

template<>
   float DParams::get(std::string argpname)
   {
      if (auto result = data.find(argpname); result == data.end()){
         return 0.0;
      } else {
         return std::stof(result->second);
      }
   }
   template<>
   double DParams::get(std::string argpname)
   {
      if (auto result = data.find(argpname); result == data.end()){
         return 0;
      } else {
         return std::stof(result->second);
      }
   }
   /* */
