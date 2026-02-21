#pragma once
#include <map>
#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <iostream>

enum class ComponentClass{
   Basic,
   Complex
};
enum class ComponentType {
   Resistor,
   Capacitor,
   Inductor,
   CPE,
   VoltageSource,
   CurrentSource
};

/*


*/

template <typename T>
struct DMap : public std::enable_shared_from_this<DMap<T>>
{
       std::map<T, int> M;
       std::map<int, T> InvM;
       //
       bool add(T _Key, int _Id);
       //
       T get(int _Id);
       //
       int get(T _Key);
       //
       int size();
};
template <typename T>
bool DMap<T>::add(T _Key, int _Id)
{
      std::cout << _Key;
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
T DMap<T>::get(int _Id)
{
	  if (auto search = InvM.find(_Id); search != InvM.end()){
	      return search->second;
     }
	  return T();  
}
       //
template <typename T>
int DMap<T>::get(T _Key)
{
         if (auto search = M.find(_Key); search != M.end()){
              return search->second;
          }
          return -1;
}
       //
template <typename T>
int DMap<T>::size()
{
	   if ( M.size() == InvM.size() ){
		   return M.size();
	   }
	   return 0;
}


/*

*/

class DParamsException : public std::exception{
   public:
DParamsException(int argid, std::string argname);
    const char* what() const noexcept override;     
    private:
    std::string name;
    int id = -1;
};

struct DParams 
{
   using data_t = std::map<std::string, std::string>;
   DParams() {};
   DParams(data_t argdata);
   
   
template<typename T>
   T get(std::string argpname);
   data_t& get_data(){
      return data;
   }
   private:
   data_t data;
};
/* */

   
   




template <typename T>
struct DMat {
 DMat(){};
 using data_t = std::vector < std::vector <T>>;

 data_t data;
 void resize(int n)
 {
   data.resize(n);
   for (int i=0; i <data.size(); i++){
      data[i].reize(n);
   }
 }

 int size(){
   return data.size();
 }

 void fill(T t){
   for (int i=0; i < data.size(); i++)
   {
      for (int j=0; j < data.size(); j++){
          data[i][j] = t;
      }
   }
 }

 T operator() (int n, int m) {
   return data[n][m];
 }
 
};

using map_t = DMap<std::string>;
using map_ptr_t = std::shared_ptr<map_t>;
