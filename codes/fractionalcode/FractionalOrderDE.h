/*   
     the aim is to implement multi-linear methods for the solution of equation types:
     \frac{d^\alpha}{dt^\alpha} y(t) = F(y,t)  with 0<\alpha<1, the fractional derivative operator
      is the Caputo FOD.
*/
#include <cmath>

template <typename T>
class Weights;
class DIETHELM{};

template <>
class Weights<DIETHELM>{
    public:
      double m_alpha;
      Weights(double _alpha):m_alpha(_alpha){}
       double corrector (int k, int j){
            auto tmp=0.0;
            if(j==0)
               tmp = std::pow(k,m_alpha+1.0) - (k-m_alpha) * std::pow(k+1.0,m_alpha);
            if ( j>0 && j<k+1 )
               tmp = std::pow(k-j+2.0, m_alpha+1) + std::pow(k-j,m_alpha+1) - 2.0*std::pow(k-j+1,m_alpha+1);
            if ( j==k+1)
               tmp = 1.0;
        return tmp;                    
       }
       double predictor (int k, int j){
           return  ( std::pow(k+1-j,m_alpha) - std::pow(k-j,m_alpha) )/m_alpha;
       }
};


// notice here we assume 0<\alpha<1

template <typename METHOD, typename FUNC>
class SolveFracPC{        
      std::vector<double> m_y, m_t;
      double m_h, m_NSteps, m_y0, m_k,m_j, m_gamma;
      int m_iSteps;
      FUNC m_Func;
      METHOD m_weights;
      public:
      void SolveFracPC(){}
      void SolveFracPC(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0):m_h(_h), m_NSteps(_NSteps),
       m_y0(_y0), m_alpha(_alpha), m_weights(_alpha), m_k(1), m_Func(_Func){  
          int n{0};
           m_t.resize(m_NSteps);
           std::generate(m_t.begin(), m_t.end(), [n = 0, &m_h]() mutable { return n++ * m_h;});    
           m_y.resize(m_NSteps);
           m_y[0] = m_y0;
           m_k = 0;
           m_gammainv = 1.0/std::tgamma(m_alpha);
      }
      void Predict(){
           for (int m_j=0; m_j < m_k, m_j++){
               m_y[m_k] += m_weights.predictor(m_k,m_j) * m_Func(m_y[m_j], m_t[m_j]);
           }
           m_y[m_k] = m_y0 + m_y[m_k] * m_gammainv;
           return;
      }
      void Correct(){
           for (int m_j=0; m_j < m_k, m_j++){
               m_y[m_k] += m_weights.corrector(m_k,m_j) * m_Func(m_y[m_j], m_t[m_j]);
           }
           m_y[m_k] = m_y0 + m_y[m_k] * m_gammainv;
           return;
      }
      void Solve(){
        m_k=1;
        while (m_k<m_Nsteps){
            Predict();
            Correct();
            m_k++;
        }
        return;
      }

      std::tuple<std::vector<double>, std::vector<double>> GetResult(){
          return std::tuple<std::vector<double>, std::vector<double>> {m_t, m_y};
      }
};

struct DLinear{
    double a, b;
    //DLinear(double _a, double _b):a(_a),b(_b){}
    void Set(double _a, double _b){
        a=_a;
        b=_b;
    }
double operator() (double t){
    return a * t + b;
}
};

struct DExp{
    double a, b;
   // DExp(double _a, double _b):a(_a),b(_b){}
    void Set(double _a, double _b){
        a=_a;
        b=_b;
    }
    double operator() (double t){
        return a * std::exp(b * t);
    }
};

struct DPow{
    double a, b;
    //DPow(double _a, double _b):a(_a),b(_b){}
    void Set(double _a, double _b){
        a=_a;
        b=_b;
    }   
    double operator() (double t){
        return a * std::pow(t, b);
    }
};


class Ohmic {
    public:
        Ohmic(double _R, double _C, double _Alpha, double _H, double _N, double _V0 ):R(_R), C(_C), Alpha(_Alpha), N(_N), V0(_V0), H(_H){
             Linear.Set(-R/C,0.0);
             Solver = SolveFracPC<Weights<DIETHELM>, DLinear>(H, N, Alpha, Linear, V0);
        }
        void Solve(){
            Solver.Solve();
        }
    private:
        DLinear Linear;
        SolveFracPC<Weights<DIETHELM>, DLinear> Solver;
        double R, C, Alpha, V0, H;
        int N;
};

class Faradic {
    public:
        Faradic(double _A, double _B, double _C, double _Alpha, double _H, double _N, double _V0 ):A(_A), B(_B), C(_C), Alpha(_Alpha), N(_N), V0(_V0), H(_H){
             Exp.Set(-A/C,B);
             Solver = SolveFracPC<Weights<DIETHELM>, DExp>(H, N, Alpha, Exp, V0);
        }
        void Solve(){
            Solver.Solve();
        }
    private:
        DExp Exp;
        SolveFracPC<Weights<DIETHELM>, DExp> Solver;
        double A, B, C, Alpha, V0, H;
        int N;
};

class Diffuse{

};