/*   
     the aim is to implement multi-linear methods for the solution of equation types:
     \frac{d^\alpha}{dt^\alpha} y(t) = F(y,t)  with 0<\alpha<1, the fractional derivative operator
      is the Caputo FOD.
*/
#include <cmath>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>

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
      std::vector<double> m_y, m_t;
      double m_alpha, m_h, m_y0, m_k,m_j, m_gamma, m_gammainv;
      int m_iSteps, m_NSteps;
      FUNC m_Func;
      METHOD m_weights;
      public:
        SolveFracPC(){}
        SolveFracPC(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0){
            Set( _h,  _NSteps,  _alpha,  _Func,  _y0);
      }

      void Set(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0){
           m_h=_h; m_NSteps=_NSteps; 
           m_y0=_y0; m_alpha=_alpha;
           m_weights= METHOD(_alpha, _h); m_k(0); 
           m_Func(_Func);  
           
           int n{0};
           m_t.resize(m_NSteps);
           std::generate(m_t.begin(), m_t.end(), [n = 0, this]() mutable { return n++ * this->m_h;});    
           m_y.resize(m_NSteps);
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
        while (m_k < m_NSteps-1){
            Predict();
      //      for (int i{0}; i <10; i++)
            Correct();
            m_k++;
        }
        return;
      }

      std::tuple<std::vector<double>, std::vector<double>> GetResult(){
          return {m_t, m_y};
      }

      void DumpResults(){
        std::fstream fo;
        fo.open("solver.dat", std::fstream::out);
        for (int i{0}; i < m_t.size();i++)
           fo << m_t[i] << " " << m_y[i] << "\n";
        fo.close();
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

struct DMitagLeffer{
    double a, b, alpha;
    int N;
    DMitagLeffer(int _N):N(_N){}
    void Set(double _a, double _b, double _alpha){
        a     = _a;
        b     = _b;
        alpha = _alpha;
    } 
    double operator() (double t){
        auto tmp {0.0};
        auto bt  {b*t};
        auto tn  {1.0};
        for (int nu {0}; nu < N; nu++){
            tmp += tn * 1.0/std::tgamma(nu * alpha + 1);
            tn *= bt;
        }
        return a * tmp;
    }
};

class Ohmic {
    public:
        Ohmic(double _R, double _C, double _Alpha, double _H, double _N, double _V0 ):R(_R), C(_C), Alpha(_Alpha), N(_N), V0(_V0), H(_H), MitagLeffer(200){
             Linear.Set(-R/C,0.0);
             Solver.Set(H, N, Alpha, Linear, V0);
             MitagLeffer.Set(1.0,1.0,_Alpha);
        }
        void Solve(bool IfDump){
            Solver.Solve();
            if (IfDump){
                auto _res = Solver.GetResult();
                std::vector<double> _mt(std::get<0>(_res).size(),0.0);
                for (int i{0};i < _mt.size(); i++){
                     _mt[i] = MitagLeffer(-std::pow(std::get<0>(_res)[i],Alpha));
                }

                std::fstream fo;
                fo.open("ohmic.dat", std::fstream::out);
                for (int i{0}; i < std::get<0>(_res).size();i++){
                      fo << std::get<0>(_res)[i] << " " << std::get<1>(_res)[i]  <<" "<< _mt[i] <<"\n";
                }
                fo.close();
            }
        }
    private:
        DLinear Linear;
        DMitagLeffer MitagLeffer;
        SolveFracPC<Weights<DIETHELM>, DLinear> Solver;
        double R, C, Alpha, V0, H;
        int N;
};

class Faradic {
    public:
        Faradic(double _A, double _B, double _C, double _Alpha, double _H, int _NSteps, double _V0 ):A(_A), B(_B), C(_C), Alpha(_Alpha), NSteps(_NSteps),
                                                                                                    V0(_V0), H(_H){
             Exp.Set(-A/C,B);
             Solver = SolveFracPC<Weights<DIETHELM>, DExp>(H, NSteps, Alpha, Exp, V0);
        }
        void Solve(){
            Solver.Solve();
        }
    private:
        DExp Exp;
        SolveFracPC<Weights<DIETHELM>, DExp> Solver;
        double A, B, C, Alpha, V0, H;
        int NSteps;
};

class Diffuse{};

