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
       std::map<T, int> m_;
       std::map<int, T> inv_m_;
       //
       bool Add(T _Key, int _Id);
       //
       T Get(int _Id);
       //
       int Get(T _Key);
       //
       int Size();
};
template <typename T>
bool DMap<T>::Add(T _Key, int _Id)
{
      std::cout << _Key;
	      auto search0 = m_.find(_Key); 
         auto search1 = inv_m_.find(_Id);

	      if (search0 != m_.end() || search1 != inv_m_.end()){
		      return false;
	      }
         
	       const auto [it0, success0] = m_.emplace(_Key, _Id);
	       const auto [it1, success1] = inv_m_.emplace(_Id, _Key);

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
	  if (auto search = inv_m_.find(_Id); search != inv_m_.end()){
	      return search->second;
     }
	  return T();  
}
       //
template <typename T>
int DMap<T>::Get(T _Key)
{
         if (auto search = m_.find(_Key); search != m_.end()){
              return search->second;
          }
          return -1;
}
       //
template <typename T>
int DMap<T>::Size()
{
	   if ( m_.size() == inv_m_.size() ){
		   return m_.size();
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
    std::string name_;
    int id_ = -1;
};

struct DParams 
{
   using data_t = std::map<std::string, std::string>;
   DParams() {};
   DParams(data_t argdata);
   
   
template<typename T>
   T Get(std::string argpname);
   data_t& GetData(){
      return data_;
   }
   private:
   data_t data_;
};
/* */

   

   

 

template <typename T>
struct DMat {
 DMat(){};
 using data_t = std::vector < std::vector <T>>;

 data_t data_;
 void Resize(int n)
 {
   data_.resize(n);
   for (int i=0; i <data_.size(); i++){
      data_[i].resize(n);
   }
 }

 int Size(){
   return data_.size();
 }

 void Fill(T t){
   for (int i=0; i < data_.size(); i++)
   {
      for (int j=0; j < data_.size(); j++){
          data_[i][j] = t;
      }
   }
 }

 T operator() (int n, int m) {
   return data_[n][m];
 }
 
};

using map_t = DMap<std::string>;
using map_ptr_t = std::shared_ptr<map_t>;
