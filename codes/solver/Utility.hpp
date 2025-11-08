#pragma once
#include <map>
#include <string>

template <typename T>
struct DMap{
       std::map<T, int> M;
       std::map<int, T> InvM;
       //
       bool Add(T _Key, int _Id);
       //
       T Get(int _Id);
       //
       int Get(T _Key);
       //
       int Size();
};


struct DParams {
   using data_t = std::map<std::string, std::string>;
   DParams() = delete;
   DParams(data_t _Data);
   
   template<typename T>
   T Get(std::string _PName);

   private:
   std::map<std::string, std::string> Data;
};

template <typename T>
struct DMat {
 DMat(){};
 using data_t = std::vetor < std::vector <T>>;

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