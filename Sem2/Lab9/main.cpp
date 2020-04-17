#include <cstdio>
#include "WordsFunc.h"
#include <cstdlib>

int main(int argc, char** argv) { //Параметр - входной файл
    system("chcp 65001");
    printf("Лабораторная работа #9");

    FILE *pFile = fopen(argv[1],"r");

    bool flag = true; //Проверкана условие - количество слов в каждом предложении равно порядковому номеру этого предложения
    int i = 1;
    do
    {
    }while(!feof(pFile) and flag);

    fclose(pFile);

    printf("Press ENTER"); getc(stdin);
    return 0;
}
