#include <cstdio>
#include <cmath>

int main() {
    /*
    double R2,R1,u,p,e0;
    p =(100+24)*pow(10,-9);
    e0=8.85*pow(10,-12);
    printf("%.10f\n",p);
    R2=0.05;
    R1=0.02;
    u=24.0/26.0;
    printf("%.20f",
            R2/(exp(u*e0/p/R1/R1)));
            */
    double R,x,q,Q,e0;
    e0=8.85*pow(10,-12);
    R=0.05;
    x=R/pow(2,0.5);
    q=6*pow(10,-9);
    Q=(1-12.5/26.0)*pow(10,-9);
    printf("%.20f\n",q*Q*x/4/3.14/e0/pow(R*R+x*x,1.5));
    x+=0.01;
    printf("%.20f\n",q*Q*x/4/3.14/e0/pow(R*R+x*x,1.5));
    x-=0.02;
    printf("%.20f\n",q*Q*x/4/3.14/e0/pow(R*R+x*x,1.5));
    return 0;
}