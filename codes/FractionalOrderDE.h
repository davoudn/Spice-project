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
       operator() (int k, int j){
            auto tmp=0.0;
            if(j==0)
               tmp = std::pow(k,m_alpha+1.0) - (k-m_apha) * std::pow(k+1.0,m_alpha);
            if ( j>0 && j<k+1 )
               tmp = std::pow(k-j+2.0, m_alpha+1) + std::pow(k-j,m_alpha+1) - 2.0*std::pow(k-j+1,m_alpha+1);
            if ( j==k+1)
               tmp = 1.0;
        return tmp;                    
       }
};


// notice here we assume 0<\alpha<1

template <typename METHOD, typename FUNC>
class SolveFracPC{        
      std::vector<double> m_y, m_t;
      double m_h, m_NSteps, m_y0, m_yPredictor;
      int m_iSteps;
      FUNC m_Func;
      public:
      void SolvePredictorCorrector(double _h, int _NSteps, double _y0):m_h(_h), m_NSteps(_NSteps), m_y0(_y0){  
          int n{0};
           m_t.resize(m_NSteps);
           std::generate(m_t.begin(), m_t.end(), [n = 0, &m_h]() mutable { return n++ * m_h;});    
           m_y.resize(m_NSteps);
           m_y[0] = m_y0;
           m_iSteps = 1;
      }
      void Predict(){
           m_yPredictor=0.0;
           for (int iw=0; iw < METHOD::Nw, iw++){
               m_y[m_iStep+1] += METHOD::PredictorWeighs[iw] * m_Func(y[m_iStep-iw], m_t[m_iStep-iw]);
           }
           m_y[m_iStep+1] += m_y[m_iStep];
           return;
      }
      void Correct(){
           m_yCorrector=0.0;
           for (int iw=0; iw < METHOD::Nw, iw++){
               m_yCorrector += METHOD::CorrectorWeighs[iw] * m_Func(y[iStep+1-iw], m_t[iStep+1-iw]);
           }
           y[iStep+1] = y[iStep] + m_yCorrector;
           return;
      }
      void Solve(){
        m_iSteps=METHOD::Nw;
        while (m_iSteps<m_Nsteps){
            Predict();
            Correct();
            m_iSteps++;
        }
        return;
      }
};