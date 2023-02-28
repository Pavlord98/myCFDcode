#ifndef READINPUT
#define READINPUT

#include <fstream>
#include <string>
#include <iostream>

struct parameters
    {
        double mu;
        double rho;
        
        int nx;
        int ny;

        double Lx;
        double Ly;

        double uLid;

        double uInitialGuess ;
        double vInitialGuess ;
        double pInitialGuess ;

        double alphau;
        double alphap;

    };

parameters getParameters();


#endif