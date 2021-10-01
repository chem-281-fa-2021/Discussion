#include <cstdlib>
#include <iostream>

using namespace std;

void matvec(const double* matrix, const double* vector, double* result,
	    const unsigned int mrows, const unsigned int mcols)
{
  for (unsigned int i=0; i<mrows; i++)
    {
    double accum = 0;
    for (unsigned int j=0; j<mcols; j++)
      accum += matrix[mrows*i+j]*vector[j];
    result[i] = accum;
    }
}

// Given a matrix M and a vector v, calculate the square of the norm of Mv, namely |Mv|^2
// In python numpy, it's like b = M @ v, and calculate b.T @ b
double norm(const double* matrix, const double* vector,
	    const unsigned int mrows, const unsigned int mcols)
{
  const unsigned int dim = mcols;
  double buffer[dim];
  double total = 0;
  matvec(matrix, vector, buffer, mrows, mcols);
  for (unsigned int k=0; k<dim; k++)
    total += buffer[k]*buffer[k];
  return total;
}


void fillmatrices(double* matrix, double* vector,
		  const unsigned int mrows, const unsigned int mcols)
{
  const char* cp = "chem281";
  unsigned int* uip = (unsigned int*) cp;
  srand(*uip);

  for (unsigned int i=0; i<mrows; i++)
    {
    for (unsigned int j=0; j<mcols; j++)
      matrix[mrows*i+j] = (double) (rand()%10000);
    vector[i] = (double) (rand()%10000);
    }
}

int main(int argc, char* argv[])
{
  const unsigned int mrows = 20;
  const unsigned int mcols = 10;
  double* matrix = new double[mrows*mcols];
  double* rhs = new double[mcols];
  fillmatrices(matrix, rhs, mrows, mcols);
  const double res = norm(matrix, rhs, mrows, mcols);
  cout<<"hw3.3 result: "<<res<<endl;
  return EXIT_SUCCESS;
}

