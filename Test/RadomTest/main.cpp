#include <iostream>
#include <cmath>
#include "big_int.h"
int main() {
    double s = 1;
    std::cout<<((pow
    (
            1+
            8*5*pow(10,6)*(5*pow(10,6)+1)/2/2
            +4*s*s-4*s
            ,0.5)-1)/2);
    return 0;
}
