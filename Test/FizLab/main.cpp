#include <cstdio>
#include <cmath>

int main() {
    double p,e,e0,L,x0,R2,Q1,Q2;
    p=0.42708*pow(10,-6);
    e=2.0;
    e0=8.85*pow(10,-12);
    L=0.1;
    x0=-0.103;
    //double k = -1.0*(p/e/e0*0.05*0.05);
    double k=p*L/2.0/e0*(L/2.0-x0);
    k-=(p/e/e0*0.05*0.05);
    printf("%.10f",k);
    return 0;
}