
#include <cmath>

template <typename T>
class Weights;
class DIETHELM{};
class EULER{};
class FOURPOINTS{};

template <>
class Weights<DIETHELM>{
    public:
      double m_alpha, m_h;
      Weights(){}
      Weights(double _alpha, double _h){
        Init(_alpha, _h);

      }
      void Init(double _alpha, double _h){
           m_alpha = _alpha;
           m_h = _h;
      }
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



class Euler{
    public:
       static const int Nw = 2;
       constexpr static double CorrectorWeighs[Nw] = {0.5,0.5};
       constexpr static double PredictorWeighs[Nw] = {0.0,1.0};
};


class FourPoints {
    public:
    static const int Nw = 4;
    constexpr static double CorrectorWeighs[Nw] =  {+3.0/+8.0, +19.0/+24.0, -5.0/+24.0 , +1.0/+24.0};
    constexpr static double PredictorWeighs[Nw] =  {+55.0/+24.0, -59.0/+24.0, +37.0/+24, -9.0/+24.0}; 
};
