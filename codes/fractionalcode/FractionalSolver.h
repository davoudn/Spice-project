#pragma once
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>
#include <memory>
#include "MathAux.h"

template <typename T>
class Weights;
class DIETHELM{};

template <>
class Weights<DIETHELM>{
    public:
      double m_alpha, m_h;
      Weights(){}

      Weights(double _alpha, double _h):m_alpha(_alpha), m_h(_h){}
       double corrector (int k, int j) {
            auto tmp=0.0;
            if(j==0)
               tmp = std::pow(k,m_alpha+1.0) - (k-m_alpha) * std::pow(k+1.0,m_alpha);
            if ( j>0 && j<k+1 )
               tmp = std::pow(k-j+2.0, m_alpha+1) + std::pow(k-j,m_alpha+1) - 2.0*std::pow(k-j+1,m_alpha+1);
            if ( j==k+1)
               tmp = 1.0;
        return tmp * std::pow(m_h,m_alpha)/(m_alpha * (m_alpha+1.0));                    
       }
       double predictor (int k, int j) {
           return  std::pow(m_h,m_alpha) * ( std::pow(k+1-j,m_alpha) - std::pow(k-j,m_alpha) )/m_alpha;
       }
};


// notice here we assume 0<\alpha<1

template <typename METHOD, typename FUNC>
class SolveFracPC{        
      arma::vec  m_y;
      arma::vec  m_t;
      std::string Tag;
      double m_alpha, m_h, m_y0, m_k,m_j, m_gamma, m_gammainv;
      int m_iSteps, m_NSteps;
      FUNC m_Func;
      std::tuple<arma::vec, arma::vec> m_results;
      METHOD m_weights;
      int c;
      public:
        SolveFracPC(){}
        SolveFracPC(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0, std::string _Tag){
            Set( _h,  _NSteps,  _alpha,  _Func,  _y0, _Tag);
      }

      void Set(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0, std::string _Tag){
           m_h=_h; m_NSteps=_NSteps; 
           m_y0=_y0; m_alpha=_alpha;
           m_weights= METHOD(_alpha, _h); 
           m_k = 0; 
           m_Func = _Func;  
           Tag = _Tag;
           int n{0};
           m_t = arma::zeros(m_NSteps,1);
           std::generate(m_t.begin(), m_t.end(), [n = 0, this]() mutable { return n++ * this->m_h;});    
           m_y = arma::zeros(m_NSteps,1);
           m_y[0] = m_y0;
           m_k = 0;
           m_gammainv = 1.0/std::tgamma(m_alpha);
      }
      void Predict(){
        auto tmp {0.0};
           for (int m_j=0; m_j < m_k + 1; m_j++){
               tmp += m_weights.predictor(m_k,m_j) * m_Func(m_y[m_j]);
           }
           m_y[m_k+1] = m_y0 + tmp * m_gammainv;
           return;
      }

      void Correct(){
        auto tmp{0.0};
           for (int m_j=0; m_j <= m_k+1; m_j++){
               tmp += m_weights.corrector(m_k,m_j) * m_Func(m_y[m_j]);
           }
           m_y[m_k+1] = m_y0 + tmp * m_gammainv;
           return;
      }
      void Solve(){
        m_k=0;
        //c = 0;
        while (m_k < m_NSteps-1){
        //    if(c==100){
        //        std::cout <<"Solver Name: "<< Tag << ",  Iteration: " << m_k <<"\n";
        //    }
            Predict();
      //      for (int i{0}; i <10; i++)
            Correct();
            m_k++;
        //    c++;
        }
        m_results = std::tuple<arma::vec, arma::vec> {m_t, m_y};
        return;
      }

      std::shared_ptr<arma::vec> GetResult(int NSkip ){
          std::vector<double> t, y;
          for (int i{0}; i < m_t.size();i+=NSkip){
        //   t.push_back(m_t[i]);
           y.push_back(m_y[i]);
          }
          std::shared_ptr<arma::vec> x = std::make_shared<arma::vec>(y);
          return x;
      }

      void DumpResults(int NSkip){
        std::fstream fo;
        fo.open("solver.dat", std::fstream::out);
        for (int i{0}; i < m_t.size();i+=NSkip)
           fo << m_t[i] << " " << m_y[i] << "\n";
        fo.close();
      }
};

