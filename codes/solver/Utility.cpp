#include "Utility.hpp"

DParams::DParams(data_t argdata):data(argdata)
{
}

template<>
std::string DParams::get<std::string>(std::string argpname)
{
      if (auto result = data.find(argpname); result == data.end()){
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
