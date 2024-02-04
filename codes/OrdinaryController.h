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
  double m_h, m_delta;
  SimpleDerivative(double _h):m_h(_h), m_delta(1.0/_h){}
  constexpr static double m_W[2] = {+1.0,-1.0};
  static const int m_N = 2;
};

  struct SimpleIntegral{
  double m_h, m_delta;
  SimpleIntegral(double _h):m_h(_h), m_delta(_h){}
  constexpr static double m_W[2] = {+0.5,+0.5};
  static const int m_N = 2;
};

 struct FourPointDerivative{
  double m_h, m_delta;
  FourPointDerivative(double _h):m_h(_h), m_delta(1.0/_h){}
  constexpr static double m_W[4] = {+11.0/6.0,-3.0,+3.0/2.0,-1.0/3.0};
  static const int    m_N    =  4;
};

 struct FourPointIntegral{
  double m_h, m_delta;
  FourPointIntegral(double _h):m_h(_h), m_delta(_h){}
  constexpr static double m_W[4] = {+3.0/8.0, 19.0/24.0, -5.0/24.0, 1.0/24.0};
  static const int    m_N    =  4;
};
struct None{};
/* ------------------------------------------------------------- */


/*          operators i.e. differential or integral ops          */

typedef double(*FUNC)(double);
template <typename OPTYPE>
double Op(OPTYPE& _t, std::vector<double>& _e);

/* these two only one step operations !*/
template <>
double Op<None>(None& _t, std::vector<double>& _e){
           return 0.0; 
      }
template <typename OPTYPE>
double Op(OPTYPE& _t, std::vector<double>& _e){
           double tmp{0.0};
           for (int i=0; i < OPTYPE::m_N; i++){
               tmp += _t.m_W[i]*_e[_t.m_N-1-i];
           }
           return tmp * _t.m_delta; 
      }
template <typename OPTYPE>     
double Op(OPTYPE& _t, FUNC _e, double x){
           double tmp{0.0};
           for (int i=0; i < _t.m_N; i++){
               tmp += _t.m_W[i]*_e(x-i*_t.m_h);
           }
           return tmp * _t.m_delta; 
      }

template <typename OPTYPE>
typename std::enable_if<is_Integral<OPTYPE>::value,double>::type
     Integral(OPTYPE& _t,FUNC _e, double x1, double x2){
           int N=(x2-x1)/_t.m_h;
           double integral{0.0};
           for (int k=0; k<N; ++k){
               integral+=Op(_t,_e,x1+k*_t.m_h);
           }
           return integral; 
      }
/* ------------- controller ----------------*/
template <typename OP1, typename OP2>
struct Controller{
    OP1 m_DO;
    OP2 m_IO;
    double  m_P, m_I, m_D, m_h;
    int m_N;
    // temps
    double tmp_DO, tmp_IO;
    //
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
        return m_D*Op(m_D,error) + m_I*Op(m_IO,error) + m_P*error[m_N-1];
     }

     double opSTM(std::vector<double>& _e){
           tmp_DO=0.0;
           tmp_IO=0.0;
           for (int i=0; i < m_DO.m_N; i++){
               tmp_IO += m_IO.m_W[i]*_e[m_N-1-i];
               tmp_DO += m_DO.m_W[i]*_e[m_N-1-i];
           }

           return m_DO.m_delta* m_D * tmp_DO + m_IO.m_delta * m_I * tmp_IO + m_P*_e[m_N-1]; 
     }
};
