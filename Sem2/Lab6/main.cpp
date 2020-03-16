#include <cstdio>
#include <windows.h>
#include "LabFunc.h"

int main(int argc, char *argv[]) {
    FILE *pFileIn  = fopen(argv[1],"r");
    FILE *pFileOut = fopen(argv[2],"w");

    SetConsoleOutputCP(1251);
    int n;
    fscanf(pFileIn,"%d",&n);

    int **matrix = new int* [n];

    PreInit(matrix,n);
    MatrixInit(matrix,n,pFileIn);

    fprintf(pFileOut,"Лабораторная Работа №6\nВведенная матрица:\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) fprintf(pFileOut,"%3d ",matrix[i][j]);
        fprintf(pFileOut,"\n");
    }

    int* seq = new int[n];
    fgetSeq(pFileIn,seq,n);

    fclose(pFileIn);
    fprintf(pFileOut,"Введенный массив чисел:\n");
    foutSeq(pFileOut,seq,n,',');

   if (CheckAndEdit(matrix,n,seq,pFileOut))
   {
       fprintf(pFileOut,"Сумма элементов каждой строки меньше соответствующего элемента последовательности\n");
       fprintf(pFileOut,"Измененный массив чисел\n");
       foutSeq(pFileOut,seq,n,',');
   }
   fclose(pFileOut);
   Finallization(matrix,n, seq);
   return 0;
}