#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include "readInput.h"
#include "readBoundary.h"

#include <algorithm>

#include "northMomentum.h"
 
using Eigen::MatrixXd;
 
int main()
{
    // reading user inputs
  parameters par{getParameters()};
  boundaries bon(getBoundaries());

  // creating empty matrices
  #include "empyMatricesAndVectors.h"

  int cellNumber{0};

  // Inital guess for p, u and v
  MatrixXd u = MatrixXd::Ones(par.nx*par.ny,1);
  MatrixXd v = MatrixXd::Ones(par.nx*par.ny,1);
  MatrixXd p = MatrixXd::Ones(par.nx*par.ny,1);

  // Previous solution
  MatrixXd pOld = p;
  MatrixXd uOld = u;
  MatrixXd vOld = v;
  
  //////////////////////////////////////////////////////////////////////////////
  //  Simple loop
  //////////////////////////////////////////////////////////////////////////////
  std:: cout << "Iterarion, U-Res, V-Res, Continuity-Res\n";
  std:: cout << "---------------------------------------\n";

////////////// u and v momentum equations /////////////////////////////////
for (int iter{0}; iter<1; iter++)
{
  
  for (int j = 0; j<par.nx; j++)
  {
    for (int i = 0; i<par.ny; i++)
    {
      cellNumber = j*par.nx + i;

      // North face
      if (j == par.ny-1)
      {
        //boundary face
        //std::cout << "if branch: ";
        momentum(par, mn(cellNumber), anu(cellNumber), spu(cellNumber), suu(cellNumber),bon.top, 2.0);
        
      }
      else
      {
        //internal face
        //std::cout << "else branch: ";
        momentum(par, mn(cellNumber), anu(cellNumber), spu(cellNumber), suu(cellNumber),"internal");
      }

    
    
    // East face
    if (i == par.nx -1)
      {
        //boundary face
        //std::cout << "if branch: ";
        momentum(par, me(cellNumber), aeu(cellNumber), spu(cellNumber), suu(cellNumber),bon.right);
        
      }
      else
      {
        //internal face
        //std::cout << "else branch: ";
        momentum(par, me(cellNumber), aeu(cellNumber), spu(cellNumber), suu(cellNumber),"internal");
      }

    // South face
    if (j == 0)
      {
        //boundary face
        //std::cout << "if branch: ";
        momentum(par, ms(cellNumber), asu(cellNumber), spu(cellNumber), suu(cellNumber),bon.bottom);
        
      }
      else
      {
        //internal face
        //std::cout << "else branch: ";
        momentum(par, ms(cellNumber), asu(cellNumber), spu(cellNumber), suu(cellNumber),"internal");
      }

    // West face
    if (i == 0)
      {
        //boundary face
        //std::cout << "if branch: ";
        momentum(par, mw(cellNumber), awu(cellNumber), spu(cellNumber), suu(cellNumber),bon.left);
        
      }
      else
      {
        //internal face
        //std::cout << "else branch: ";
        momentum(par, mw(cellNumber), awu(cellNumber), spu(cellNumber), suu(cellNumber),"internal");
      }

    
    }
    // Calculating the face pressures

    // pfe and pfw
    // West side boundary
    if (i == 0)
    {
      pfe(cellNumber) = 0.5 * p(cellNumber) + 0.5 * p(cellNumber+1);
      pfw(cellNumber) = p(cellNumber) - p(cellNumber+1) + 0.5*(p(cellNumber)+p(cellNumber+1));
    }
    // East side 
    else if (i==par.nx -1)
    {
      pfe(cellNumber) = p(cellNumber) - p(cellNumber-1) + 0.5*(p(cellNumber)+p(cellNumber-1));
      pfw(cellNumber) = p(cellNumber) - p(cellNumber-1) + 0.5*(p(cellNumber)+p(cellNumber-1));
    }
    // Central cell
    else
    {
      pfe(cellNumber) = 0.5 * p(cellNumber) + 0.5*(p(cellNumber+1));
      pwe(cellNumber) = 0.5 * p(cellNumber) + 0.5*(p(cellNumber-1));
    }

    // pfn and pfs
    //North side
    if (j==par.ny-1)
    {
      pfn(cellNumber) = 0.5 * p(cellNumber) + 0.5 * p(cellNumber + par.nx);
      pfs(cellNumber) = p(cellNumber) - p(cellNumber - par.nx) + 0.5*(p(cellNumber)+p(cellNumber - par.ny));
    }
    else if(j==0)
    {
      pfs(cellNumber) = 0.5 * p(cellNumber) + 0.5 * p(cellNumber - par.nx);
      pfn(cellNumber) = p(cellNumber) - p(cellNumber + par.nx) + 0.5*(p(cellNumber)+p(cellNumber + par.ny));
    }
    else
    {
      pfn(cellNumber) =  0.5 * p(cellNumber) + 0.5 * p(cellNumber + par.nx);
      pfs(cellNumber) =  0.5 * p(cellNumber) + 0.5 * p(cellNumber - par.nx);
    }

    // Calculate the central coeffs
    apu(cellNumber) = -(aeu(cellNumber)+awu(cellNumber)+anu(cellNumber)+asu(cellNumber)+spu(cellNumber));

    // Relax the central coeffs 
    apurelax (cellNumber) = apu(cellNumber)/par.alphau;

    // calculate the relaxation source term
    MatrixXd suurelax(cellNumber,1) = (apu(cellNumber)*uOld(cellNumber)*((1-par.alphau)/par.alphau));
    MatrixXd suurelax(cellNumber,2) = (apu(cellNumber)*uOld(cellNumber)*((1-par.alphau)/par.alphau));
  }
  
  


}

}