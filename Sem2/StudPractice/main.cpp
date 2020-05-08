#include <iostream>
#include "SearchInArray.h"
double bruh(double ar) {return ar+1;}
double bruh1(double ar,  double ar2) {return ar+ar2;}

int main() {
    double* ar = new double[12];
    SearchElement<double,double> test(ar,12,bruh,bruh1);
    return 0;
}
