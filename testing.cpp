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

  // creating empty matrices
  #include "empyMatricesAndVectors.h"
     
    std::cout << typeid(mn(0)).name() << '\n';
    std::cout << typeid(2.0).name() << '\n';
    std::cout << std::max(mn(0),2.0) << '\n';
    //std::cout << std::max(double(mn(0)),2);
}