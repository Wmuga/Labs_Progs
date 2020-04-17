#include <cmath>
#include <cstdio>

typedef double (*func)(double); //Указатель на функцию типа double с принимаемым значением double

double funcF(double x) //Функция N24
{
    return (
            (double)1/(x*sqrt(x+0.3)+exp(-x)+(double)1/(double)7)-x
    );
}

double funcS(double x) //Функция N27
{
    return (
            cos(x)-exp(-pow(x+(double)1,2))+(double)1/(double)9-x
    );
}

double FindRootSec(double a, double b, double e, func f,int *nIter) //Метод секущекй
{
    double x1,x2,x3,FL,FR,FX;
    x1=a; x2=b;
    do  //Цикл с постусловием
    {
        FL = f(x1); //Левый край
        FR = f(x2); //Правый край
        x3 = x1 - FL/(FR-FL)*(x2-x1);
        FX = f(x3);
        x1=x2;x2=x3; //Переходим к следующему отрезку
        (*nIter)++;
    }
    while(fabs(x2-x1)>=e and FX!=0); //Ищем, пока не пересечем Ox или пока отрезок не будет меньше точности(погрешности)
    return x3;
}

int main() {
    int k;
    printf("%.10f %.10f",FindRootSec(0.1, 1.9,0.000001,funcF,&k), FindRootSec(.1, 1.9,0.000001,funcS,&k));
    return 0;
}
