/* -----------------------List of oproximate differentioal and integral operators---------------------------- */
  struct SimpleDerivative{
  static const double m_W[2] = {-1.0,1.0};
  static const int m_N = 2;
  static double step(double _h){
         return 1.0/_h;
  }
};

  struct SimpleIntegral{
  static const double m_W[2] = {0.5,0.5};
  static const int m_N = 2;
  static double step(double _h){
         return _h;
  }
};

 struct FourPointDerivative{
  static const double m_W[4] = {0.3334,-1.5,-3.0,11.0/6.0};
  static const int    m_N    =  4;
  static double step(double _h){
         return 1.0/_h;
  }
};

/*           operators i.e. differential or integral ops          */
template <> 
class Operator<NULL>(){
  double m_h;
  public:
      DerivativeOperator(){}
      double operator (std::vector<double>& _e){
              return 0; 
      }
};

template <typename OPTYPE> 
class Operator(){
  double m_h;
  public:
      DerivativeOperator(double _h):m_h(OPTYPE::step(_h)){}
      double operator (std::vector<double>& _e){
           double tmp{0.0};
           for (int i=0; i < op_t::m_N; i++){
               tmp += OPTYPE::m_Weight[i]*_e[OPTYPE::m_N-i-1];
           }
           tmp *= m_h;
           return tmp; 
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
    Controler(double _h, std::vector<double>&& _params):m_DO(_h), m_IO(_h)
                                                      , m_P(_params[0]), m_D(_params[1])
                                                      , m_I(_params[0]), m_h(_h)
                                                      {}

    Controller(double _h): m_DO(_h), m_IO(_h)
                          , m_P(0.0), m_D(0)
                          , m_I(0), m_h(_h)
                          {}
     
     void set_params(std::vector<double>& _params){
       m_P = _params[0]; 
       m_PI = _params[1]; 
       m_PD = _params[2];
     }
     double operator() (std::vector<double>& error){
        return m_D*m_DO(error) + m_I*m_IO(error) + m_P*error[m_N-1];
     }
};

