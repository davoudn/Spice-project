#include <map>

struct Map{
       std::map<std::string, int> M;
       std::map<int, std::string> InvM;
       //
       bool Add(std::string _Key, int _Id){
              
	      auto search0 = M.find(_Key); 
              auto search1 = InvM.find(_Id);

	      if (search0 == M.end() || search1 == InvM.end()){
		 return false;
	      }

	       const auto [it0, success0] = M.Emplace(_Key, _Id);
	       const auto [it1, success1] = InvM.Emplace(_id, _Key);

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
