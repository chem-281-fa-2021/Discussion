#include <iostream>
#include <stack>
#include <algorithm>
#include <armadillo>
#include <time.h>
using namespace std;

template <class T>
int compare(T &a1, T &a2) {}

template <class T>
inline void swap(T *a, int i, int j) {}

template <class T>
void quicksort(T *a, int left, int right) {}

template <class T>
void insertionSort(T *a, int n) {}

template <class T>
void quicksortm(T *a, int left, int right, int m) {}

int main()
{
    arma::uvec m = {0, 1, 2, 3, 4, 5, 7, 9, 12, 15, 18, 21, 25, 50, 100, 300, 1000};
    m.t().print("m");
    arma::rowvec time_m = arma::zeros(m.n_elem).t();
    size_t size_vec = 100000;

    arma::vec avec = arma::randu(size_vec);
    double *a = avec.memptr();
    quicksortm<double>(a, 0, avec.n_elem - 1, 7);

    clock_t t;
    t = clock();
    quicksortm<double>(a, 0, size_vec - 1, 3);
    t = clock() - t;
    time_m(0) += (double)t / CLOCKS_PER_SEC;
    time_m.print();
    return 0;
}