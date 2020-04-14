#include <cstdio>
#include <cmath>
#include <cstdlib>

bool RCheckElems(double *array, int start, int end) //Рекурсионная функция
{
    bool  res = false;
    if (start>end) start=end;
    if (start==end) {
        res = pow((int)array[start], 2) / (end + 1) > 2;
        if (res) {
            printf("Найден элемент (#%d), удовлетворяющитй условию поиска\n",start+1);
        }else{}
        }
    else
    {
        double oot = (end-start)/3.0;
        res = RCheckElems(array, start, (trunc(oot)) + start);
        if (!res) res = RCheckElems(array, ceil(oot) + start, end);
    }
    return res;
}

int main() {
    int N;
    system("chcp 65001");
    printf("Лабораторная работа #4\n");
    printf("Введите количество элементов массива N=");
    scanf("%d",&N);
    fflush(stdin);
    double *array = new double[N];
    for (int i=0;i<N;i++) scanf("%lf",&array[i]);
    fflush(stdin);
    if (!RCheckElems(array,0,N)) printf("Не найдено элемнтов, удовлетворяющих условию\n");
    delete []array;
    printf("Press ENTER");
    getc(stdin);
    return 0;
}