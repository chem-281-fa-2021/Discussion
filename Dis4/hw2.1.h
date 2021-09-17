#if !defined HW_2_1_H
#define HW_2_1_H
#include <complex>
#include <cmath>

using namespace std;

class Derivable
{
public:
virtual complex<double> eval(const complex<double> x) = 0;
};

double firstDerivative(Derivable& f, const double x);
#endif
