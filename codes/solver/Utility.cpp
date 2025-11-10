#include "Utility.hpp"


DParams::DParams(data_t argdata):data(argdata){
   }
   
   template<>
   float DParams::get<float>(std::string argpname){
      auto result = data.find(argpname);
      if (result == data.end()){
         return 0.0;
      }
      return std::stof(result->second);
   }

   template<>
   double DParams::get<double>(std::string argpname){
      auto result = data.find(argpname);
      if (result == data.end()){
         return 0.0;
      }
      return std::stof(result->second);
   }

   template<>
   std::string DParams::get<std::string>(std::string argpname){
      auto result = data.find(argpname);
      if (result == data.end()){
         return std::string("");
      }
      return result->second;
   }

   template<>
   int DParams::get<int>(std::string argpname)
   {
      auto result = data.find(argpname);
      if (result == data.end()){
         return 0;
      }
      return std::stoi(result->second);
   }



