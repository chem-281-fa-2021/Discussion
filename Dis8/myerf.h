#if !defined MYERF_H
#define MYERF_H

namespace myerf
{
    double erf_Chebyshev(double x);
    double erfc_Chebyshev(double x);
    double erfc_poly_inv(double x);
    double erfc_poly_exp(double x);
}

#endif //MYERF_H
