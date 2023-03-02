  #include "readInput.h"
  #include <Eigen/Dense>

///////////////////////////////////////
  //
  // setting up empty vecors and matrices
  //
  ///////////////////////////////////////

  // u and v momentum equations
  // Matrix ceoffs
  MatrixXd aeu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd awu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd anu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd asu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd apu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd apu_relax = MatrixXd::Zero(par.nx*par.ny,1);

  // Pressure gradient
  MatrixXd nablapp = MatrixXd::Zero(par.nx*par.ny,2);
  
  // Source Terms
  MatrixXd spu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd suu = MatrixXd::Zero(par.nx*par.ny,2);

  // Matrices and Vectors
  MatrixXd A = MatrixXd::Zero(par.nx*par.ny,par.nx*par.ny);
  MatrixXd Bu = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd Bv = MatrixXd::Zero(par.nx*par.ny,1);

  //Mass Source
  // Interpolated face velocity
  MatrixXd upinterpe = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd upinterpw = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd upinterpn = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd upinterps = MatrixXd::Zero(par.nx*par.ny,2);

  // Face pressure gradient
  MatrixXd nfdotnablapfe = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd nfdotnablapfw = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd nfdotnablapfn = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd nfdotnablapfs = MatrixXd::Zero(par.nx*par.ny,2);

  // Interpolated face pressure gradient
  MatrixXd nablapinterpe = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd nablapinterpw = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd nablapinterpn = MatrixXd::Zero(par.nx*par.ny,2);
  MatrixXd nablapinterps = MatrixXd::Zero(par.nx*par.ny,2);

  // Interpolated central coefficient
  MatrixXd apurelaxe = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd apurelaxw = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd apurelaxn = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd apurelaxs = MatrixXd::Zero(par.nx*par.ny,1);

  // Face nass flow rate
  MatrixXd me = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd mw = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd mn = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd ms = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd massSource = MatrixXd::Zero(par.nx*par.ny,1);

  // Pressure Correction equation
  // Matrix coeffs
  MatrixXd aep = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd awp = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd anp = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd asp = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd app = MatrixXd::Zero(par.nx*par.ny,1);

  // Matrices and vectors
  MatrixXd pPrime = MatrixXd::Zero(par.nx*par.ny,1);
  MatrixXd Ap = MatrixXd::Zero(par.nx*par.ny, par.nx*par.ny);
  MatrixXd Bp = MatrixXd::Zero(par.nx*par.ny,1);

  
  // Residuals

  //Point Monitors