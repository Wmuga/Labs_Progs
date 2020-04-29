#include <cstdio>
#include <cmath>
#include <cstdlib>

int RCheckElems(double *array, int start, int end) //Рекурсия (передаем массив, начало и конец)
{
    if (start==end) { //Достигли одного элемента
        printf("%d\n",start);
        if ((pow((int)array[start], 2)/(end + 1)) > 2) //Проверк условия
        {
            printf("Найден элемент (#%d), удовлетворяющий условию\n", start+1);
            return 1;
        } else return 0;
        }
    else
    { //Отделяется одна треть и проверяется по отдельности 1/3 и 2/3
        return (RCheckElems(array, start,  start + (end-start)/3)) or (RCheckElems(array,  start + (end-start)/3+1, end));
    }
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
    int res = RCheckElems(array, 0, N);
    if (N!=0) {
        if (!res) printf("Не найдено элементов, удовлетворяющих условию\n");
        else {}
    }
    else printf("Пустой массив\n");
    delete[]array;
    printf("Press ENTER");
    getc(stdin);
    return 0;
}