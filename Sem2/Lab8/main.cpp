#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "LabFunc.h"

int main() {
    system("chcp 65001"); //Поддержка кириллицы Входной файл UTF-8
    printf("Введите значения A, B\n");
    int n;
    double a,b;
    try {
        scanf("%lf", &a);
        if (a<=0) throw 1; if (a>=2) throw 2; // Проверка на аномалии с выдачей кода ошибки
        scanf("%lf", &b);
        if (b<=0) throw 3; if (b>=2) throw 4;// Проверка на аномалии с выдачей кода ошибки
        if (b<a) throw 5;
        fflush(stdin);
        printf("Введите количество итераций\n");
        scanf("%d", &n); if (n<1) throw 6; if (n>10) throw 7; // Проверка на аномалии с выдачей кода ошибки
        double e[n];
        for (int i = 0; i < n; i++) {
            printf("Точность[%d]=", i + 1);
            scanf("%lf", &e[i]);
            if (floor(e[i]*pow(10,10))==0) throw 8 + i;
            fflush(stdin);
        }

        printf("Для первой функции:\n");
        TableStart(1, a, b); //Начало таблцы
        for (int i = 0; i < n; i++) { //Поиск корня
            int n1 = 0;
            int n2 = 0;
            double x1 = FindRootDiv(a, b, e[i], funcF, &n1); //Деление пополам
            double x2 = FindRootChord(a, b, e[i], funcF, &n2); //Метод хорд
            TableCell(e[i], x1, n1, x2, n2); //Вывод в таблицу
            i++;
        }
        printf("Для второй функции:\n");
        TableStart(2, a, b); //Начало таблцы
        for (int i = 0; i < n; i++) { //Поиск корня
            int n1 = 0;
            int n2 = 0;
            double x1 = FindRootDiv(a, b, e[i], funcS, &n1); //Деление пополам
            double x2 = FindRootSec(a, b, e[i], funcS, &n2); //Метод хорд
            TableCell(e[i], x1, n1, x2, n2); //Вывод в таблицу
            i++;
        }
    }
    catch (int errNum) {
        switch (errNum){
            default:
                errNum-=7;
                printf("Точность[%d] сишком маленькая\n",errNum);
                break;
            case 1:
                printf("\'А\' должна быть больше 0\n");
                break;
            case 2:
                printf("\'А\' должна быть меньше 2\n");
                break;
            case 3:
                printf("\'B\' должна быть больше 0\n");
                break;
            case 4:
                printf("\'B\' должна быть меньше 2\n");
                break;
            case 5:
                printf("\'А\' не должна быть больше \'B\'\n");
                break;
            case 6:
                printf("\'N\' должна быть больше 1\n");
                break;
            case 7:
                printf("\'N\' должна не превосходить 10\n");
                break;
        }
    }
    printf("------------------------------------------------------------\nPress ENTER"); getc(stdin);
    return 0;
}
