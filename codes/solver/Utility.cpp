#include "Utility.hpp"

DParams::DParams(data_t argdata):data(argdata)
{
}

template<>
std::optional<std::string> DParams::get<std::string>(std::string argpname)
{
      if (auto result = data.find(argpname); result == data.end()){
         return std::nullopt;
      } else {
         return result->second;
      }
}

template<>
   std::optional<float> DParams::get(std::string argpname)
   {
      if (auto result = data.find(argpname); result == data.end()){
         return std::nullopt;
      } else {
         return std::stof(result->second);
      }
   }
   template<>
   std::optional<double> DParams::get(std::string argpname)
   {
      if (auto result = data.find(argpname); result == data.end()){
         return std::nullopt;
      } else {
         return std::stof(result->second);
      }
   }
   /* */
