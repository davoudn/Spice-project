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
#include <memory>
#include "cvs.h"
#include "optim/optim.hpp"


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
      arma::vec  m_y;
      arma::vec  m_t;
      std::string Tag;
      double m_alpha, m_h, m_y0, m_k,m_j, m_gamma, m_gammainv;
      int m_iSteps, m_NSteps;
      FUNC m_Func;
      std::tuple<arma::vec, arma::vec> m_results;
      METHOD m_weights;
      int c;
      public:
        SolveFracPC(){}
        SolveFracPC(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0, std::string _Tag){
            Set( _h,  _NSteps,  _alpha,  _Func,  _y0, _Tag);
      }

      void Set(double _h, int _NSteps, double _alpha, FUNC& _Func, double _y0, std::string _Tag){
           m_h=_h; m_NSteps=_NSteps; 
           m_y0=_y0; m_alpha=_alpha;
           m_weights= METHOD(_alpha, _h); 
           m_k = 0; 
           m_Func = _Func;  
           Tag = _Tag;
           int n{0};
           m_t = arma::zeros(m_NSteps,1);
           std::generate(m_t.begin(), m_t.end(), [n = 0, this]() mutable { return n++ * this->m_h;});    
           m_y = arma::zeros(m_NSteps,1);
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
        //c = 0;
        while (m_k < m_NSteps-1){
        //    if(c==100){
        //        std::cout <<"Solver Name: "<< Tag << ",  Iteration: " << m_k <<"\n";
        //    }
            Predict();
      //      for (int i{0}; i <10; i++)
            Correct();
            m_k++;
        //    c++;
        }
        m_results = std::tuple<arma::vec, arma::vec> {m_t, m_y};
        return;
      }

      std::shared_ptr<arma::vec> GetResult(int NSkip ){
          std::vector<double> t, y;
          for (int i{0}; i < m_t.size();i+=NSkip){
        //   t.push_back(m_t[i]);
           y.push_back(m_y[i]);
          }
          std::shared_ptr<arma::vec> x = std::make_shared<arma::vec>(y);
          return x;
      }

      void DumpResults(int NSkip){
        std::fstream fo;
        fo.open("solver.dat", std::fstream::out);
        for (int i{0}; i < m_t.size();i+=NSkip)
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
// Normal self discharge terms
struct FaradicOrdinary {
    FaradicOrdinary(double _A, double _B, double _C, double _V0):A(_A), B(_B), C(_C), V0(_V0){}
       double operator() (double t){
        return -(1.0/B) * std::log( std::exp(-B*V0) + t * A*B/C );
       }
    
    void Dump(int N, double dt){
        std::fstream fo("FaradicOrdinary.dat", std::fstream::out);
        for (int i{0}; i<N; i++){
            fo << i*dt << " " << (*this)(i*dt) << "\n";
        }
    }
       private:
       double A,B,C,V0;
};
struct OhmicOrdinary {
    OhmicOrdinary(double _R, double _C, double _V0):R(_R), C(_C), V0(_V0){}
       double operator() (double t){
        return V0*std::exp(-(1.0/R/C)* t);
       }

    void Dump(int N, double dt){
        std::fstream fo("OhmicOrdinary.dat", std::fstream::out);
        for (int i{0}; i<N; i++){
            fo << i*dt << " " << (*this)(i*dt) << "\n";
        }
    }
       private:
       double R,C,V0;
};

struct DiffuseOrdinary {
    DiffuseOrdinary(double _A, double _V0):A(_A), V0(_V0){}
       double operator() (double t){
        return V0 - A*std::pow(t,0.5);
       }
    void Dump(int N, double dt){
        std::fstream fo("FaradicNormal.dat", std::fstream::out);
        for (int i{0}; i<N; i++){
            fo << i*dt << " " << (*this)(i*dt) << "\n";
        }
    }
       private:
       double A,V0;
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
        Ohmic(double _R, double _C, double _Alpha, double _H, double _N, double _V0, std::string _Tag ):R(_R), C(_C), Alpha(_Alpha), N(_N), V0(_V0), H(_H), MitagLeffer(200){
             Linear.Set(-1.0/(R*C),0.0);
             Solver.Set(H, N, Alpha, Linear, V0, _Tag);
             MitagLeffer.Set(1.0,1.0,_Alpha);
        }
        void Solve(){
            Solver.Solve();
        }
        std::shared_ptr<arma::vec> GetResults(int NSkip){
            return Solver.GetResult(NSkip);
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
        Faradic(double _A, double _B, double _C, double _Alpha, double _H, int _NSteps, double _V0, std::string _Tag ):A(_A), B(_B), C(_C), Alpha(_Alpha), NSteps(_NSteps),
                                                                                                    V0(_V0), H(_H), Tag(_Tag){
             Exp.Set(-A/C,B);
             Solver = SolveFracPC<Weights<DIETHELM>, DExp>(H, NSteps, Alpha, Exp, V0, _Tag);
        }
        void Solve(){
            Solver.Solve();
        }
          std::shared_ptr<arma::vec> GetResults(int NSkip){
            return Solver.GetResult(NSkip);
        }
        void Dump(int NSkip){
            auto x = GetResults(NSkip);
            std::fstream fo(Tag+std::string(".dat"), std::fstream::out);
            for (int i{0}; i < x->n_rows; i++){
                fo<< i*NSkip*H << " " << (*x)(i) << "\n";
            }
        }
    private:
        DExp Exp;
        SolveFracPC<Weights<DIETHELM>, DExp> Solver;
        double A, B, C, Alpha, V0, H;
        int NSteps;
        std::string Tag;

};

class Diffuse{};

//
// Ackley function
struct FitData {

 FitData(std::string _file, std::string StepType, int CycleIndex, int DataPoints, int _NSubsteps):data(_file){
    Setup(StepType,CycleIndex,DataPoints, _NSubsteps);
    }
void Setup(std::string StepType, int CycleIndex, int DataPoints, int _NSubsteps){
    V = data.filter(StepType, CycleIndex, DataPoints)[1];
    t = data.filter(StepType, CycleIndex, DataPoints)[0];
    std::cout << "data size: " << t.size() << "\n";
    V0 = V[0];
    H  = (t[1] - t[0])/_NSubsteps;
    NSteps = t.size() * _NSubsteps;
    NSubsteps = _NSubsteps;
    }
    //
 double V0;
 cvsread_neware data;
 arma::vec t,V;
 int NSteps, NSubsteps;
 double H;
};
static FitData* opt_data = nullptr;

struct optordinary{
     //
  //  static Faradic _Faradic;
  //  static Ohmic   _Ohmic;
    //
    static void init(std::string _file, std::string StepType, int CycleIndex, int DataPoints, int _NSubsteps){
          opt_data = new FitData(  _file,   StepType,   CycleIndex,   DataPoints,   _NSubsteps);
    }
    //
 static double ObjectiveFunc(const arma::vec& p, arma::vec* grad_out, void* _data) {
     double _A = p[0], _B = p[1], _C = p[2], _R = p[3];

     
     double obj_val = 0.0;
     //
     return obj_val;
}

static int Optimmize(){
        // initial values:
    arma::vec x = arma::ones(6,1);
    //
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    bool success = optim::bfgs(x, ObjectiveFunc,nullptr);

    std::chrono::time_point<std::chrono::system_clock> end   = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    if (success) {
        std::cout << "de: ObjectiveFunc test completed successfully.\n"
                << "elapsed time: " << elapsed_seconds.count() << "s\n";
    } else {
        std::cout << "de: ObjectiveFunc test completed unsuccessfully." << std::endl;
    }

    arma::cout << "\nde: solution to ObjectiveFunc test:\n" << x << arma::endl;

    return 0;
 }
};


struct opt{
    //
  //  static Faradic _Faradic;
  //  static Ohmic   _Ohmic;
    //
    static void init(std::string _file, std::string StepType, int CycleIndex, int DataPoints, int _NSubsteps){
          opt_data = new FitData(  _file,   StepType,   CycleIndex,   DataPoints,   _NSubsteps);
    }
    //
 static double ObjectiveFunc(const arma::vec& p, arma::vec* grad_out, void* _data) {
     double _A = p[0], _B = p[1], _C = p[2], _Alpha = p[3]; // faradic params
     double _R = p[4];

     Faradic _Faradic(_A, _B, _C, _Alpha, opt_data->H, opt_data->NSteps, opt_data->V0, std::string("Faradic"));
     Ohmic   _Ohmic  (_R, _C    , _Alpha, opt_data->H, opt_data->NSteps, opt_data->V0, std::string("Ohmic"));
     //std::cout << opt_data->V0 << " " << opt_data->NSteps << " " << opt_data->H << "\n" ;
     //Ohmic ohmic(1.0,1.0,0.5, 0.01, 1000, opt_data->V0);

     _Faradic.Solve();
     _Ohmic.Solve();

     auto _FaradicResult = _Faradic.GetResults(opt_data->NSubsteps);
     auto _OhmicResult   =   _Ohmic.GetResults(opt_data->NSubsteps);

     for (int i{0}; i< _FaradicResult->n_rows; i++){
        std::cout << (*_FaradicResult)(i) << " " <<  (*_OhmicResult)(i) << " " << opt_data->V(i) << "\n";
     }
     auto tmp = *_FaradicResult - opt_data->V;
     double obj_val = arma::norm(tmp);
     //
     return obj_val;
}

static int Optimmize(){
        // initial values:
    arma::vec x = arma::ones(6,1);
    //
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    bool success = optim::bfgs(x, ObjectiveFunc,nullptr);

    std::chrono::time_point<std::chrono::system_clock> end   = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    if (success) {
        std::cout << "de: ObjectiveFunc test completed successfully.\n"
                << "elapsed time: " << elapsed_seconds.count() << "s\n";
    } else {
        std::cout << "de: ObjectiveFunc test completed unsuccessfully." << std::endl;
    }

    arma::cout << "\nde: solution to ObjectiveFunc test:\n" << x << arma::endl;

    return 0;
 }
};

