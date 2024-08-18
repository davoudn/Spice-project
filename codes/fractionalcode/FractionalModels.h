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
#include "FractionalSolver.h"
#include "cvs.h"
#include "optim/optim.hpp"


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

