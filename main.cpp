#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include "readInput.h"
#include <algorithm>
#include "readBoundary.h"

using Eigen::MatrixXd;
 
int main()
{
  // reading user inputs
  parameters par{getParameters()};
  boundaries bon(getBoundaries());
  // creating empty matrices
  #include "empyMatricesAndVectors.h"

  // Inital guess for p, u and v
  MatrixXd u = MatrixXd::Ones(par.nx*par.ny,1);
  MatrixXd v = MatrixXd::Ones(par.nx*par.ny,1);
  MatrixXd p = MatrixXd::Ones(par.nx*par.ny,1);

  int cellNumber{0};

  for (int j = 0; j<par.nx; j++)
  {
    for (int i = 0; i<par.ny; i++)
    {
      cellNumber = j*par.nx + i;

      // North face
      if (j == par.ny-1)
      {
        //Boundary face (moving wall)
        anu(cellNumber) = 0;
        
        spu(cellNumber) = spu(cellNumber) - (par.mu*par.Lx/par.nx/(0.5*par.Ly/par.ny));

        suu(cellNumber,1)= suu(cellNumber,1) + ((par.mu*par.Lx/par.nx)/(0.5*par.Ly/par.ny))*par.uLid;

      } 
      else
      {
        // Interior face
        anu(cellNumber) = - ( std::max(mn(cellNumber),0.0) + par.mu*par.Lx/par.nx/(par.Ly/par.ny));
      }

      // East Face
      //if ()/
    }
  }

  


}