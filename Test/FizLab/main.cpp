#include <cstdio>
#include <cmath>

int main() {
    double p,e,e1,R,R1,R2,Q1,Q2;
    p=0.7069*pow(10,-9);
    R1=0.05;
    R2=0.06;
    R=0.03;
    double e0 = 8.85*pow(10,-12);
    Q1=-0.293*pow(10,-12);
    Q2=4*pow(10,-12);
    e=2;
    e1=4;
    double k = p/(6*e*e0)*R*R+(p*pow(R,3)/3.0/e0)*(1.0/R1-1.0/R) +
            (p*pow(R,3)/3.0/e0/e1 + Q1/4.0/3.14/e0/e1)*(1.0/R2-1.0/R1)+
            (p*pow(R,3)/3.0/e0 + Q1+Q2/4.0/3.14/e0)*(1.0/R2);
    printf("%.10f",k);
    return 0;
}