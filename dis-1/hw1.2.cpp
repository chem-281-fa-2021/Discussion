#include <math.h>
#include <float.h>
#include <stdio.h>
#include <hw1.2.h>

double sqrtguess(const double number)
{
  const float x = number;
  const float xhalf = x*0.5F;
  const float threehalfs = 1.5F;

  union
  {
    float f;
    unsigned int u;
  } invroot = { .f = x};
  invroot.u = 0x5f3759df - (invroot.u>>1);
  invroot.f = threehalfs - (xhalf*invroot.f*invroot.f);
  return 1.e+00/invroot.f;
}

double rootiter(const double squared, const double approx)
{
  union
  {
    double d;
    unsigned long u;
  } leqiv = { .d=squared };
  unsigned long exponent = leqiv.u&0x7FF0000000000000;
  leqiv.u = exponent;
  printf("exponent %le\n", leqiv.d);
  const double tol = DBL_EPSILON * leqiv.d;
  double root = approx;
  do
    {
    root += 0.5e+00*(squared-root*root)/root;
    } while (fabs(squared - root*root) > tol);
  return root;
}

#include <stdlib.h>

int main(int arc, char* argv[])
{
  //double y=1.5;
  double y=atof(argv[1]);
  double root = mssesqrt(y);
  double mathroot = sqrt(y);
  printf("Computed %1.17le libm %1.17le error %1.17le libm-mssesqrt %1.17le\n",
	                       root, mathroot, y-root*root, mathroot - root);
}

