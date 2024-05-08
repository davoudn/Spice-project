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
