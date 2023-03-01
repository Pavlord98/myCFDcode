#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <string>
#include "readInput.h"

#include <algorithm>
 
using Eigen::MatrixXd;
 
int main()
{
    // reading user inputs
  parameters par{getParameters()};
  boundaries bon(getBoundaries());

  // creating empty matrices
  #include "empyMatricesAndVectors.h"
     
  or (int j = 0; j<par.nx; j++)
  {
    for (int i = 0; i<par.ny; i++)
    {
      cellNumber = j*par.nx + i;

      // North face
      [anu(cellNumber), spu(cellNumber), suu(cellNumber,1)] = northMomentum(mn(cellNumber),par.uLid, bon.top);

    }
  }
}