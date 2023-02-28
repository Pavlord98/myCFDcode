#include "readInput.h"


parameters getParameters()
{
    parameters p;
    std::ifstream inf{"inputs"};

    //inf.seekg(5);
    std::string dummy;
    //std::getline(inf, dummy);
    
    inf >> p.mu >> dummy;
    inf >> p.rho >> dummy;
    inf >> p.nx >> dummy;
    inf >> p.ny >> dummy;
    inf >> p.Lx >> dummy;
    inf >> p.Ly >> dummy;
    inf >> p.uLid >> dummy;
    inf >> p.uInitialGuess >> dummy;
    inf >> p.vInitialGuess >> dummy;
    inf >> p.pInitialGuess >> dummy;
    inf >> p.alphau >> dummy;
    inf >> p.alphap >> dummy;

    //std::getline(inf, strInput);

    return p;
};



