/*
 *Просто набор полезных функций, которые можно испоьзовать в разлличных лабораторных
*/

#include <cstdlib>

void Start(int num)
{
    system("chcp 65001");
    printf("Лабораторная работа #%d",num);
}

void End()
{
    printf("Press ENTER"); getc(stdin);
}

//Матрицы (для int и для char)

void PreInitMatrix(int** matrix, int n)
{
    for (int i=0; i<n;i++) matrix[i]=new int[n];
}

void FinMatrix(int** matrix, int n,int* buf)
{
    for (int i=0; i<n;i++) delete []matrix[i];
    delete []buf;
}

void PreInitMatrix(char** matrix, int n)
{
    for (int i=0; i<n;i++) matrix[i]=new char[n];
}

void FinMatrix(char** matrix, int n)
{
    for (int i=0; i<n;i++) delete []matrix[i];
}