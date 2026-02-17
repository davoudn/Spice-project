
#include <cmath>



class DIETHELM{};
class EULER{};
class FOURPOINTS{};
class Null{};

template <typename T>
class Weights{};

template <>
class Weights<DIETHELM>{
    public:
      double m_alpha, m_h;
      Weights();
      Weights(double _alpha, double _h);
      void Init(double _alpha, double _h);
       double corrector (int k, int j);
       double predictor (int k, int j);
};


template <>
class Weights<EULER> {
    public:
       static const int Nw = 2;
       constexpr static double CorrectorWeighs[Nw] = {0.5,0.5};
       constexpr static double PredictorWeighs[Nw] = {0.0,1.0};
};


template <>
class Weights<FOURPOINTS> {
    public:
    static const int Nw = 4;
    constexpr static double CorrectorWeighs[Nw] =  {+3.0/+8.0, +19.0/+24.0, -5.0/+24.0 , +1.0/+24.0};
    constexpr static double PredictorWeighs[Nw] =  {+55.0/+24.0, -59.0/+24.0, +37.0/+24, -9.0/+24.0}; 
};


template <>
class Weights<Null>{
    public:
       static const int Nw = 0;
};