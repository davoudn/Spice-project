#include "Utility.hpp"




 DParamsException::DParamsException(int argid, std::string argname):id_(argid), name_(argname)
     {

     }
    const char* DParamsException::what() const noexcept  
    {
      std::string ret_val;
      switch(id_){
         case 0: {
            ret_val = std::string("DParamsException::what() : the parameted=r ") + name_ + std::string("not found");
            break;
         }
      }
      return ret_val.c_str();
    }   


DParams::DParams(data_t argdata):data_(argdata)
{
}

template<>
std::string DParams::Get<std::string>(std::string argpname)
{
      if (auto result = data_.find(argpname); result == data_.end()){
         throw DParamsException(0, argpname);
         return std::string();
      } else {
         return result->second;
      }
}

template<>
   float DParams::Get(std::string argpname)
   {
      if (auto result = data_.find(argpname); result == data_.end()){
         return 0.0;
      } else {
         return std::stof(result->second);
      }
   }
   template<>
   double DParams::Get(std::string argpname)
   {
      if (auto result = data_.find(argpname); result == data_.end()){
         return 0;
      } else {
         return std::stof(result->second);
      }
   }
   /* */
