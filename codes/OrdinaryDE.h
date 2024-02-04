/*   
     the aim is to implement multi-linear methods for the solution of equation types:
     \frac{d}{dt} y(t) = F(y,t)  
*/
class Euler{
    public:
       static const int Nw = 2;
       constexpr static double CorrectorWeighs[Nw] = {0.5,0.5};
       constexpr static double PredictorWeighs[Nw] = {0.0,1.0};
};


class FourPoints {
    public:
    static const int Nw = 4;
    constexpr static double CorrectorWeighs[Nw] =  {+3.0/+8.0, +19.0/+24.0, -5.0/+24.0 , +1.0/+24.0};
    constexpr static double PredictorWeighs[Nw] =  {+55.0/+24.0, -59.0/+24.0, +37.0/+24, -9.0/+24.0}; 
};

template <typename METHOD, typename FUNC>
class SolvePredictorCorrector{        
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
           m_y[METHOD::Nw-1] = m_y0;
           m_iSteps = METHOD::Nw-1;
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