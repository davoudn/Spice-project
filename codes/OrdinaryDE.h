/*   
     the aim is to implement multi-linear methods for the solution of equation types:
     \frac{d}{dt} y(t) = F(y,t)  
*/
class Euler{
       static const int Nw = 2.0;
       static const double CorrectorWeighs[NW] = {0.5,0.5};
       static const double PredictorWeighs[NW] = {0.0,1.0};
};
template <typename METHOD, typename FUNC>
class SolvePredictorCorrector{         // P and C stand for predictor and corrector respectively.
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
      void Corrector(){
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