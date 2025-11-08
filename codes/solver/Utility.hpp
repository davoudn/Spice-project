#pragma once
#include <map>
#include <string>
#include <vector>

template <typename T>
struct DMap{
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


struct DParams {
   using data_t = std::map<std::string, std::string>;
   DParams() {};
   DParams(data_t argdata);
   
   template<typename T>
   T get(std::string argpname);

   private:
   std::map<std::string, std::string> data;
};

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