#include <iostream>
#include <armadillo>

using namespace std;

int main()
{
  //Create mat or vector
  arma::mat A(4, 5, arma::fill::randu);
  arma::mat B(4, 5, arma::fill::randu);
  A.print("A");
  B.print("B");
  cout << A*B.t() << endl;

  arma::vec C(2, arma::fill::randu);
  arma::vec D(2, arma::fill::randu);
  C.print("C");
  D.print("D");
  cout << arma::dot(C,D) << endl;
  
  return 0;
}
