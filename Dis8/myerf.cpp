#include "myerf.h"
#include <stdexcept>
#include <math.h>

double myerf::erfc_poly_inv(double x)
{
    const int ncof = 6;
    const double cof[ncof] = {0.0705230784, 0.0422820123, 0.0092705272, 0.0001520143, 0.0002765672, 0.0000430638};
    double temp=x, sum=1.;
    for (int k= 0; k < ncof; k++){
        sum += cof[k] *temp;
        temp *= x;
    }
    
    return 1./std::pow(sum, 16);
}
double myerf::erfc_poly_exp(double x)
{
    const int ncof = 5;
    const double cof[ncof] = {0.254829592, -0.284496736,  1.421413741,  -1.453152027, 1.061405429};
    double t = 1. / (1. + 0.3275911*x);
    double temp=t, sum=0.;
    for (int k= 0; k < ncof; k++){
        sum += cof[k] *temp;
        temp *= t;
    }
    return sum * std::exp(-x*x);
}

// Chebyshev
double erfccheb(double z);

double myerf::erf_Chebyshev(double x)
{
    if (x >= 0.)
        return 1.0 - erfccheb(x);
    else
        return erfccheb(-x) - 1.0;
}
double myerf::erfc_Chebyshev(double x)
{
    if (x >= 0.)
        return erfccheb(x);
    else
        return 2.0 - erfccheb(-x);
}

double erfccheb(double z)
{
    int j;
    const int ncof = 28;
    const double cof[28] = {-1.3026537197817094, 6.4196979235649026e-1,
                            1.9476473204185836e-2, -9.561514786808631e-3, -9.46595344482036e-4,
                            3.66839497852761e-4, 4.2523324806907e-5, -2.0278578112534e-5,
                            -1.624290004647e-6, 1.303655835580e-6, 1.5626441722e-8, -8.5238095915e-8,
                            6.529054439e-9, 5.059343495e-9, -9.91364156e-10, -2.27365122e-10,
                            9.6467911e-11, 2.394038e-12, -6.886027e-12, 8.94487e-13, 3.13092e-13,
                            -1.12708e-13, 3.81e-16, 7.106e-15, -1.523e-15, -9.4e-17, 1.21e-16, -2.8e-17};
    double t, ty, tmp, d = 0., dd = 0.;
    if (z < 0.)
        throw std::invalid_argument("erfccheb requires nonnegative argument");
    t = 2. / (2. + z);
    ty = 4. * t - 2.;
    for (j = ncof - 1; j > 0; j--)
    {
        tmp = d;
        d = ty * d - dd + cof[j];
        dd = tmp;
    }
    return t * std::exp(-z * z + 0.5 * (cof[0] + ty * d) - dd);
}
