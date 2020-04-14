#include <cstdio>
#include <cmath>

int main() {
    double l = 0.0025;
    double r = 0.002;
    double N = 100.0;
    double I = 0.2;
    double x0 = -1*l*29.0/27.0;
    double u0 = 4*3.14*pow(10,-7);
    double res = u0*I*N/2*(
            ((l/2-x0)/pow(r*r+(l/2-x0)*(l/2-x0),0.5))
            +
            ((l/2+x0)/pow(r*r+(l/2+x0)*(l/2+x0),0.5))
            );
    printf("%.10f",res);
    return 0;
}