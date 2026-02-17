#include "Integrators.hpp"

#include <cmath>

      Weights<DIETHELM>::Weights(){}
      Weights<DIETHELM>::Weights(double _alpha, double _h){
       Init(_alpha, _h);
      }
      void Weights<DIETHELM>::Init(double _alpha, double _h){
           m_alpha = _alpha;
           m_h = _h;
      }
       double Weights<DIETHELM>::corrector (int k, int j) {
            auto tmp=0.0;
            if(j==0)
               tmp = std::pow(k,m_alpha+1.0) - (k-m_alpha) * std::pow(k+1.0,m_alpha);
            if ( j>0 && j<k+1 )
               tmp = std::pow(k-j+2.0, m_alpha+1) + std::pow(k-j,m_alpha+1) - 2.0*std::pow(k-j+1,m_alpha+1);
            if ( j==k+1)
               tmp = 1.0;
        return tmp * std::pow(m_h,m_alpha)/(m_alpha * (m_alpha+1.0));
       }
       double Weights<DIETHELM>::predictor (int k, int j) {
           return  std::pow(m_h,m_alpha) * ( std::pow(k+1-j,m_alpha) - std::pow(k-j,m_alpha) )/m_alpha;
       }

