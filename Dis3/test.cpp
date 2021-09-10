#include <armadillo>
#include <iostream>

int main() {
    double r =10;
    double& ar = r;
    ar = 5;
    double y =7;
    ar = y;
    std::cout << ar << "\n";
    return 0;
}