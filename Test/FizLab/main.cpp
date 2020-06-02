#include <cstdio>
#include <cmath>

int main() {
    double q,Q,x,R,e0;
    q=6*pow(10,-9);
    e0=8.85*pow(10,-12);
    Q = (1.0 - 12.5/34.0)*pow(10,-9);
    R=0.05;
    x=R/pow(2,0.5);
    printf("%.10f\n",q*Q*x/4/3.14/e0/pow(R*R+x*x,1.5));
    x=R/pow(2,0.5)+0.01;
    printf("%.10f\n",q*Q*x/4/3.14/e0/pow(R*R+x*x,1.5));
    x=R/pow(2,0.5)-0.01;
    printf("%.10f\n",q*Q*x/4/3.14/e0/pow(R*R+x*x,1.5));
    return 0;
}