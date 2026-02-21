#include "Integrators.hpp"

#include <cmath>

      Weights<DIETHELM>::Weights(){}
      Weights<DIETHELM>::Weights(double _alpha, double _h){
       Init(_alpha, _h);
      }
      void Weights<DIETHELM>::Init(double _alpha, double _h){
           m_alpha_ = _alpha;
           m_h_ = _h;
      }
       double Weights<DIETHELM>::corrector (int k, int j) {
            auto tmp=0.0;
            if(j==0)
               tmp = std::pow(k,m_alpha_+1.0) - (k-m_alpha_) * std::pow(k+1.0,m_alpha_);
            if ( j>0 && j<k+1 )
               tmp = std::pow(k-j+2.0, m_alpha_+1) + std::pow(k-j,m_alpha_+1) - 2.0*std::pow(k-j+1,m_alpha_+1);
            if (j==k+1)
               tmp = 1.0;
        return tmp * std::pow(m_h_,m_alpha_)/(m_alpha_ * (m_alpha_+1.0));
       }
       double Weights<DIETHELM>::predictor (int k, int j) {
           return  std::pow(m_h_,m_alpha_) * ( std::pow(k+1-j,m_alpha_) - std::pow(k-j,m_alpha_) )/m_alpha_;
       }
