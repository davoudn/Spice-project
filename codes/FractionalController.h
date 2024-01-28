#include <vector>
#include <cmath>

struct alpha {};
struct h{};
struct Ntail{};
// types of fractional operators
struct GL{};
struct Caputo{};
struct RL{};
//
template <>
struct FractioanlDervative<GL> {
    FractioanlDervative(){}
    FractioanlDervative(double _alpha, int _n, double _h){}
    
    double operator() (std::vector<double>& e) {
        double dummy{0.0};
        for (int i=0; i<m_N; i++)
            dummy += m_w[i] * e[m_N-1-i];
        return dummy*m_hinv;
    }    

    double operator() (std::vector<double>& e, int _last) {
        double dummy{0.0};
        for (int i=0; i<m_N; i++)
            dummy += m_w[i] * e[(m_N-i+_last)%m_N];
        return dummy*m_hinv;
    }    
};

template<typename P, typename T, typename U>
  void set(T& fo, U val);

template<>
  void set<alpha>(FO<GL>& fo, double val){
	 fo.m_alpha = val;
	 fo.m_hinv = 1.0/std::pow(fo.m_h,fo.m_alpha);
   fo.m_w[0]=1.0;
   for (int i=1; i<fo.m_N; i++)
       fo.m_w[i] =  (1.0-(fo.m_alpha+1)/i) * fo.m_w[i-1];
  }

template<>
  void set<Ntail>(FO<GL>& fo, int val){
	  fo.m_N= val;
    for (int i=1; i<fo.m_N; i++)
        fo.m_w[i] =  (1.0-(fo.m_alpha+1)/i) * fo.m_w[i-1];
  }

template<>
  void set<h>(FO<GL>& fo, double val){
	     fo.m_h=val;
	     fo.m_hinv = 1.0/std::pow(fo.m_h,fo.m_alpha);
  }

/*   ------------------------------------------------------------    */

template <typename OP1, typename OP2>
struct FractionalOrderControler{
    FractionalOperator<OP1> m_FOI;
    FractionalOperator<OP2> m_FOD;
    double  m_P, m_I, m_D;
    double m_h;
    int m_N;
    FractionalOrderControler(){}

     FractionalOrderControler(int _n, double _h, std::vector<double>&& _params):m_FOD(_params[0],_n,_h), m_FOI(_params[1],_n,_h)
                                                                              , m_P(_params[3]), m_PD(_params[4]), m_PI(_params[5]), m_N(_n), m_h(_h){}

     FractionalOrderControler(int _n, double _h):m_FOD(0.0,0.0,_n,_h), m_FOI(0.0,0.0,_n,_h)
                                               , m_P(0.0,_n), m_N(_n), m_h(_h){}

     void set_params(std::vector<double>& _params){
       set<alpha>(m_FOD, _params[0]); set<alpha>(m_FOI, _params[1]);
       m_P =  _params[2]; m_PI = _params[3]; m_PD = _params[4];
     }

     double operator() (std::vector<double>& error){
        return m_D*m_FOD(error) + m_I*m_FOI(error) + m_P(error);
     }
};
