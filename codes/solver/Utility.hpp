#pragma once
#include <map>
#include <string>

struct DMap{
       std::map<std::string, int> M;
       std::map<int, std::string> InvM;
       //
       bool Add(std::string _Key, int _Id);
       //
       std::string Get(int _Id);
       //
       int Get(std::string _Key);
       //
       int Size();
};


struct DParams {
   using data_t = std::map<std::string, std::string>;
   DParams();
   DParams(data_t _Data);
   
   template<typename T>
   T Get(std::string _PName);

   private:
   std::map<std::string, std::string> Data;
};