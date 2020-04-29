#include <cstdio>
#include <cmath>

int main() {
    double r=0,t;
    double i=0;
    do{
        scanf("%lf",&t);
        if (t!=-1) { i+=1; r+=t;}
    }while(t!=-1);
    printf("%lf",r/i);
    return 0;
}