#include <string>
#include <iostream>

enum type {
    wall,
    movingWall,
    vInlet,
    pOutlet,
    internal
};

type hashit (std::string const& inString) {
    if (inString == "wall") return wall;
    if (inString == "movingWall") return movingWall;
    if (inString == "vInlet") return vInlet;
    if (inString == "pOutlet") return pOutlet;
    else return internal;
}

void momentum(parameters par, double m, double& au, double& spu, double& suu, std::string type, double uW=0.0, double vW=0.0) {
    switch (hashit(type)) {
    case wall:
    {   

    }
    case movingWall:
    {
      au = 0.0;
      spu = spu - par.mu*par.Lx/par.nx/(0.5*par.Ly/par.ny);
      suu = suu + par.mu*par.Lx/par.nx/(0.5*par.Ly/par.ny)*uW;
      return;
    }   
    case vInlet:
    {

    }
    case pOutlet:
    {

    } 
    case internal:
    {
      au = - ( std::max(m,0.0) + par.mu*par.Lx/par.nx/(par.Ly/par.ny)); 
      return;     
    }
    }
}






