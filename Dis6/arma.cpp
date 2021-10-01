#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
  int nrows = 5;
  int ncols = 4;
  //Create mat or vec, and initailize
  mat A(nrows, ncols, arma::fill::randu); // With initialisation
  mat A1(nrows, ncols); // Without initialisation
  A1.randu();
  mat B = { {1, 3, 5},
          {2, 4, 6} };  // With initialisation
  mat C;      // Without initialisation, you want use it in class
  // A.print("A");
  // B.print("B");
  // C.set_size(6,2);
  // cout << "size of C: " << size(C) << endl;

  mat I = eye(5,5); //Identity
  // I.print("I");

  //Vec 
  arma::vec a_vec(5, fill::randu);
  arma::rowvec b_vec(5, fill::zeros);
  uvec la = {1, 0, 0};
  // a_vec.print("a_vec");
  // b_vec.print("b_vec");
  // la.print();


  // //Fill values
  // A.zeros();
  // A.print("zeros");
  // A.ones();
  // A.print("ones");
  // A.fill(50.0);
  // A.print("fill");

  A.set_size(5,5);
  A.randn();
  // A.print("A");
// transpose
  // A.t().print("At");
// multiplication
  //accu (sum)
    // cout<< "Sum A all" << accu(A) <<endl;
    // rowvec sum_vec = sum(A);
    // sum_vec.print("sum_vec"); 


// diagmat
  // mat a_vec_to_m = arma::diagmat(a_vec);
  // a_vec_to_m.print("a_vec_to_m"); 
// dot
  arma::vec c_vec(5, fill::randu);
  // cout<< "a dot c = " << as_scalar(a_vec.t() * c_vec) <<endl;
  // cout<< "a dot c = " << arma::dot(a_vec, c_vec) <<endl;
  // trace( X )
  // approx_equal


  // miscellaneous element-wise
  // A.fill(4.0);
  // sqrt(A).print("Asqrt");

// eigs_sym
  mat OV =A *A.t();
  OV.print("OV");
  vec eigval;
  mat eigvec;
  eig_sym(eigval, eigvec, OV);
  eigval.print("eigval");
  eigvec.print("eigvec");


  return 0;
}
