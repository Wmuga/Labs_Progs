typedef double (*func)(double);

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

double FindRootDiv(double a, double b, double e, func f,int *nIter) //Метод деления отрезка
{
    double x,FA,FB,FX;
    bool flag = true; //Проверка на наличие корня на отрезке
    do  //Цикл с постусловием
    {
        x = (b+a)/(double)2; //Середина отрезка
        FA = f(a); //F(a) левый край
        FB = f(b); //F(b) правый край
        FX = f(x); //F(X)
        if (FX*FB<0) a = x; //Сравнение знаков F(x) и F(b)
        else b = x;
        (*nIter)++;
        if (FA*FB>0) flag=false; //Если знак одинаковый - нет корня
    } while (fabs(a-b)>=e and FX!=0 and flag); //Ищем, пока не пересечем Ox или пока отрезок не будет меньше точности(погрешности)
    if (!flag) return -1;
    return x;
}

double FindRootChord(double a, double b, double e, func f,int *nIter) //Метод хорд
{
    double x,FA,FB,FX,d;
    bool flag = true; //Проверка на наличие корня на отрезке
    do  //Цикл с постусловием
    {
        FA = f(a); //F(a) левый край
        FB = f(b); //F(b) правый край
        x = a - (FA*(b-a)/(FB-FA));
        FX = f(x); //F(X)
        if (FX*FB<0) { //Сравнение знаков F(x) и F(b)
            d = fabs(a-x);
            a = x;
        }
        else {
            d = fabs(b-x);
            b = x;
        }
        (*nIter)++;
        if (FA*FB>0) flag=false; //Если знак одинаковый - нет корня
    }
    while(d>=e and FX!=0 and flag); //Ищем, пока не пересечем Ox или пока один из отрезков не будет меньше точности(погрешности)
    if (!flag) return -1;
    return x;
}

double FindRootSec(double a, double b, double e, func f,int *nIter) //Метод секущекй
{
    double x1,x2,x3,FL,FR,FX;
    x1=a; x2=b;
    bool flag = true; //Проверка на наличие корня на отрезке
    do  //Цикл с постусловием
    {
        FL = f(x1); //Левый край
        FR = f(x2); //Правый край
        x3 = x1 - FL/(FR-FL)*(x2-x1);
        FX = f(x3);
        x1=x2;x2=x3; //Переходим к следующему отрезку
        (*nIter)++;
        if (FL*FR>0) flag=false; //Если знак одинаковый - нет корня
    }
    while(fabs(x2-x1)>=e and FX!=0 and flag); //Ищем, пока не пересечем Ox или пока отрезок не будет меньше точности(погрешности)
    if (!flag) return -1;
    return x3;
}

void TableStart(int n,double a,double b)
{
    char* fname;
    if (n==1) fname =(char*)"      Метод хорд      ";
    else fname=(char*)"    Метод секущих     ";
    printf("Отрезок [%.5f, %.5f]\n",a,b);
    printf("|Функция N%d  |   Деление отрезка    |%s|\n",n,fname);
    printf("|Точность    |Корень      |Итерации |Корень      |Итерации |\n");
}

void TableCell(double e,double x1,int n1, double x2, int n2)
{
    int z = ceil(fabs(log(e)/log(10)));
    char* r1 = new char[z+2];
    char* r2 = new char[z+2];
    if (x1==-1) r1 = (char*)"Нет корня   ";
    else sprintf(r1,"%.*f",z,x1);
    if (x2==-1) r2 = (char*)"Нет корня   ";
    else sprintf(r2,"%.*f",z,x2);
    printf("|%12.*f|%12s|%9d|%12s|%9d|\n",z,e,r1,n1,r2,n2);
    delete []r1; delete []r2;
}
