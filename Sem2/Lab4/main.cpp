#include <cstdio>
#include <cmath>
#include <cstdlib>

bool RCheckElems(double *array, int start, int end) //Рекурсия (передаем массив, начало и конец)
{
    bool res; //Наш флаг на условие
    if (start==end) { //Достигли одного элемента
        res = pow((int)array[start], 2) / (end + 1) > 2; //Проверк условия
        if (res) {
            printf("Найден элемент (#%d), удовлетворяющий условию поиска\n",start+1);
        }else{}
        }
    else
    {
        int oot = trunc((end-start)/3.0)+start; //отделяем треть
        //Проверка отделенных частей (start - oot) первая треть (oot+1 - end) оставшиеся 2 трети
        res = RCheckElems(array, start, oot) or RCheckElems(array, oot+1, end);
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
    if (N!=0) if (!RCheckElems(array, 0, N)) printf("Не найдено элементов, удовлетворяющих условию\n"); else{}
    else printf("Пустой массив\n");
    delete[]array;
    printf("Press ENTER");
    getc(stdin);
    return 0;
}