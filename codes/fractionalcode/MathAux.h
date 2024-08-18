#pragma once
#include <cmath>

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