#include "Utility.hpp"


DParams::DParams(data_t argdata):Data(argdata){
   }
   
   template<>
   float DParams::Get<float>(std::string argpname){
      auto result = Data.find(argpname);
      if (result == Data.end()){
         return 0.0;
      }
      return std::stof(result->second);
   }

   template<>
   std::string DParams::Get<std::string>(std::string argpname){
      auto result = Data.find(argpname);
      if (result == Data.end()){
         return std::string("");
      }
      return result->second;
   }

   template<>
   int DParams::Get<int>(std::string argpname)
   {
      auto result = Data.find(argpname);
      if (result == Data.end()){
         return 0;
      }
      return std::stoi(result->second);
   }



template <typename T>
bool DMap<T>::Add(T _Key, int _Id)
{
              
	      auto search0 = M.find(_Key); 
         auto search1 = InvM.find(_Id);

	      if (search0 != M.end() || search1 != InvM.end()){
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
template <typename T>
T DMap<T>::Get(int _Id)
{
	  if (auto search = InvM.find(_Id); search != InvM.end()){
	      return search->second;
   }
	  return T(0);  
}
       //
template <typename T>
int DMap<T>::Get(T _Key)
{
         if (auto search = M.find(_Key); search != M.end()){
              return search->second;
          }
          return -1;
}
       //
template <typename T>
int DMap<T>::Size()
{
	   if ( M.size() == InvM.size() ){
		   return M.size();
	   }
	   return 0;
}