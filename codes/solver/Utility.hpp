#include <map>

struct DMap{
       std::map<std::string, int> M;
       std::map<int, std::string> InvM;
       //
       bool Add(std::string _Key, int _Id){
              
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
       std::string Get(int _Id){
	  if (auto search = InvM.find(_Id); search != InvM.end()){
	      return search->second;
          }
	  return std::string("");  
       }
       //
       int Get(std::string _Key){
           if (auto search = M.find(_Key); search != M.end()){
              return search->second;
          }
          return -1;
       }
       //
       int size(){
	   if ( M.size() != InvM.size() ){
		   return M.size();
	   }
	   return 0;
       }
};


struct DParams {
   using data_t = std::map<std::string, std::string>;
   DParams(){
   }

   DParams(data_t _Data):Data(_Data){
   }
   
   template<typename T>
   T Get(std::string _PName);

   template<>
   float Get<float>(std::string _PName){
      auto result = Data.find(_PName);
      if (result == Data.end()){
         return 0.0;
      }
      return std::stof(result->second);
   }

   template<>
   std::string Get<std::string>(std::string _PName){
      auto result = Data.find(_PName);
      if (result == Data.end()){
         return std::string("");
      }
      return result->second;
   }

   template<>
   int Get<int>(std::string _PName){
      auto result = Data.find(_PName);
      if (result == Data.end()){
         return 0;
      }
      return std::stoi(result->second);
   }

   private:
   std::map<std::string, std::string> Data;
};