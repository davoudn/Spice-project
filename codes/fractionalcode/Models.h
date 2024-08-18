
#pragma once
#include <cmath>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>
#include <memory>
#include "cvs.h"
#include "optim/optim.hpp"

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


