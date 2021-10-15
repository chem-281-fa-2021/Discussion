#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#include <math.h>
#include "myerf.h"


int main(int argc, char* argv[])
{
  if (argc !=2)
  {
  printf("usage hw1.1 number, for example hw1.1 250");
  return EXIT_FAILURE;
  }
  
  double input = atof(argv[1]);
  double c_erf = std::erfc(input);
  double m_erf_Chebyshev = myerf::erfc_Chebyshev(input);
  double m_erf_poly_inv = myerf::erfc_poly_inv(input);
  double m_erf_poly_exp = myerf::erfc_poly_exp(input);
  printf("Erf in C++ std  = %1.14f \n", c_erf);
  printf("Erf in poly inv = %1.14f   Difference = %1.14f \n", m_erf_poly_inv, std::abs(c_erf- m_erf_poly_inv));
  printf("Erf in poly exp = %1.14f   Difference = %1.14f \n", m_erf_poly_exp, std::abs(c_erf- m_erf_poly_exp));
  printf("Erf in Chebyshev= %1.14f   Difference = %1.14f \n", m_erf_Chebyshev, std::abs(c_erf- m_erf_Chebyshev));
  // printf("\n");
  return EXIT_SUCCESS;
}

