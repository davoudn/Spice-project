#include "Utility.hpp"
#include <string>

DParams::DParams(){
   }

DParams::DParams(data_t _Data):Data(_Data){
   }
   
   template<>
   float DParams::Get<float>(std::string _PName){
      auto result = Data.find(_PName);
      if (result == Data.end()){
         return 0.0;
      }
      return std::stof(result->second);
   }

   template<>
   std::string DParams::Get<std::string>(std::string _PName){
      auto result = Data.find(_PName);
      if (result == Data.end()){
         return std::string("");
      }
      return result->second;
   }

   template<>
   int DParams::Get<int>(std::string _PName)
   {
      auto result = Data.find(_PName);
      if (result == Data.end()){
         return 0;
      }
      return std::stoi(result->second);
   }



bool DMap::Add(std::string _Key, int _Id)
{
              
	      auto search0 = M.find(_Key); 
         auto search1 = InvM.find(_Id);

	      if (search0 == M.end() || search1 == InvM.end()){
		      return false;
	      }

	       const auto [it0, success0] = M.emplace(_Key, _Id);
	       const auto [it1, success1] = InvM.emplace(_Id, _Key);

	       if( success0 &&  success1){ 
	          return true;
	       }
	       else{
		    return false;
	       }
}
       //
std::string DMap::Get(int _Id)
{
	  if (auto search = InvM.find(_Id); search != InvM.end()){
	      return search->second;
          }
	  return std::string("");  
}
       //
int DMap::Get(std::string _Key)
{
         if (auto search = M.find(_Key); search != M.end()){
              return search->second;
          }
          return -1;
}
       //
int DMap::Size()
{
	   if ( M.size() != InvM.size() ){
		   return M.size();
	   }
	   return 0;
}