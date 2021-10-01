// CPP program to illustrate
// concept of Virtual Functions

#include <iostream>

using namespace std;

class Integrand
{
public:
	virtual double eval(double x) = 0;
};

class Polynomial_2 : public Integrand
{
private:
	double n0;
	double n1;
	double n2;

public:
	Polynomial_2(double n0_input, double n1_input, double n2_input) : n0(n0_input), n1(n1_input), n2(n2_input) {}
	Polynomial_2() : n0(0.0), n1(0.0), n2(0.0) {}
	~Polynomial_2() {}
	double eval(double x)
	{
		return n0 + n1 * x + n2 * x * x;
	}
	double IntA(double start, double end)
	{
		return n0 * (end - start) + n1 / 2.0 * (end * end - start * start) + n2 / 3.0 * (end * end * end - start * start * start);
	}
};

double Integration(Integrand &f, const double start, const double end, const int numpoints)
{
	double stepsize = (end - start) / double(numpoints); // h*N = b-a   int/2.0 = 2 int = 5  
	double Sum = (f.eval(start) + f.eval(end)) / 2;
	for (int k = 1; k < numpoints; k++)
		// printf("%1.2f + %1.2f + %1.2f+ %1.2f \n", n0 * (end - start), n1/2.0 * (end*end - start*start), start, end);
		Sum += f.eval(start + double(k) * stepsize);
	return Sum * stepsize;
}

// double DEInfinity(Integrand& f1, Integrand& f2, const int nmupoints_oneside, const double stepsize);

int main()
{
	double start = 0.0;
	double end = 2.0;
	double n0 = 1.0;
	double n1 = 1.0;
	double n2 = 0.0;
	int numpoints = 10;
	Polynomial_2 Linear(n0, n1, n2);
	double Analytical = Linear.IntA(start, end);
	double Numerical = Integration(Linear, start, 2.0, numpoints);
	printf("y = %1.2f *x^2 + %1.2f *x + %1.2f Integrate from %1.2f to %1.2f, Analytical Integral is %1.17e.\n", n2, n1, n0, start, end, Analytical);
	printf("Numerical Integral is %1.17e Difference is %1.17e \n", Numerical, Numerical - Analytical);


	n2 = 1.0;
	Polynomial_2 Quadratic(n0, n1, n2);
	Analytical = Quadratic.IntA(start, end);
	Numerical = Integration(Quadratic, start, 2.0, numpoints);
	printf("y = %1.2f *x^2 + %1.2f *x + %1.2f Integrate from %1.2f to %1.2f, Analytical Integral is %1.17e.\n", n2, n1, n0, start, end, Analytical);
	printf("Numerical Integral is %1.17e Difference is %1.17e \n", Numerical, Numerical - Analytical);

	for (int k = 1; k < 8; k++){
		Numerical =  Integration(Quadratic, start, 2.0, numpoints);
		double stepsize = (end - start) / double(numpoints);
		printf("Numerical Integral is %1.10f Difference is %1.10f when stepsize = %1.5f\n", Numerical, Numerical - Analytical, stepsize);
		numpoints *= 2;
	}


}
