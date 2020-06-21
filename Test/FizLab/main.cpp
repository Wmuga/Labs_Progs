#include <cstdio>
#include <cmath>

int main() {
    double R2,R1,u,p,e0;
    p =(100+24)*pow(10,-9);
    e0=8.85*pow(10,-12);
    printf("%.10f\n",p);
    R2=0.05;
    R1=0.02;
    u=24.0/26.0;
    printf("%.20f",
            R2/(exp(u*e0/p/R1/R1)));
    return 0;
}