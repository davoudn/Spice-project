#include <vector>
#include <type_traits>

struct SimpleDerivative;
struct SimpleIntegral;
struct FourPointDerivative;
struct FourPointIntegral;

/*                            */
template <typename T>
struct is_Integral{
        static const bool value = false;
};

template <>
struct is_Integral<SimpleIntegral>{
        static const bool value = true;
};
template <>
struct is_Integral<FourPointIntegral>{
        static const bool value = true;
};

/* -----------------------List of oproximate differentioal and integral operators---------------------------- */
  
  struct SimpleDerivative{
  constexpr static double m_W[2] = {+1.0,-1.0};
  static const int m_N = 2;
  static double step(double _h){
         return 1.0/_h;
  }
};

  struct SimpleIntegral{
  constexpr static double m_W[2] = {+0.5,+0.5};
  static const int m_N = 2;
  static double step(double _h){
         return _h;
  }
};

 struct FourPointDerivative{
  constexpr static double m_W[4] = {+11.0/6.0,-3.0,+3.0/2.0,-1.0/3.0};
  static const int    m_N    =  4;
  static double step(double _h){
         return 1.0/_h;
  }
};

 struct FourPointIntegral{
  constexpr static double m_W[4] = {+3.0/8.0,19.0/24.0, -5.0/24.0,1.0/24.0};
  static const int    m_N    =  4;
  static double step(double _h){
         return _h;
  }
};
/* ------------------------------------------------------------- */
struct None{};

/*          operators i.e. differential or integral ops          */

typedef double(*FUNC)(double);

template <typename OPTYPE> 
class Operator{
  double m_h,m_delta;
  double tmp;
  public:
      Operator(double _h):m_h(_h), m_delta(OPTYPE::step(_h)){}

double operator ()(std::vector<double>& _e){
           tmp= 0.0;
           for (int i=0; i < OPTYPE::m_N; i++){
               tmp += OPTYPE::m_W[i]*_e[OPTYPE::m_N-1-i];
           }
           return tmp * m_h; 
      }
double operator ()(FUNC _e, double x){
           double tmp{0.0};
           for (int i=0; i < OPTYPE::m_N; i++){
               tmp += OPTYPE::m_W[i]*_e(x-i*m_h);
           }
           return tmp * m_delta; 
      }
 //typename std::enable_if<is_Integral<OPTYPE>::value,double>::type 
 double operator ()(FUNC _e, double x1, double x2){
           int N=(x2-x1)/m_h;
           double integral{0.0};
           for (int k=0; k<N; ++k){
               integral+=(*this)(_e,x1+k*m_h);
           }
           return integral; 
      }
};
template <> 
class Operator<None>{
  double m_h;
  public:
      Operator(){}
      double operator ()(std::vector<double>& _e){
              return 0; 
      }
};
/* ------------- controller ----------------*/
template <typename OP1, typename OP2>
struct Controller{
    Operator<OP1> m_DO;
    Operator<OP2> m_IO;
    double  m_P, m_I, m_D, m_h;
    int m_N;
    Controller(){}
    Controller(double _h, std::vector<double>&& _params):m_DO(_h), m_IO(_h)
                                                      , m_P(_params[0]), m_D(_params[1])
                                                      , m_I(_params[0]), m_h(_h), m_N(OP1::m_N)
                                                      {}
    Controller(double _h): m_DO(_h), m_IO(_h)
                          , m_P(0.0), m_D(0)
                          , m_I(0), m_h(_h)
                          {}
     void set_params(std::vector<double>&& _params){
       m_P = _params[0]; 
       m_I = _params[1]; 
       m_D = _params[2];
     }
     double operator() (std::vector<double>& error){
        return m_D*m_DO(error) + m_I*m_IO(error) + m_P*error[m_N-1];
     }
};
