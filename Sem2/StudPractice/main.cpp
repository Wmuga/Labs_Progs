#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "SearchInArray.h"
typedef int arrayType; //Пока считаем, что int. Вполне заменяемо на double, float и char

template <typename ArrayType>
ArrayType funcChangeElement(ArrayType ar) {return (ar + 1);}
template <typename ArrayType>
ArrayType funcSearchElement(ArrayType ar1, ArrayType ar2) {return std::min(ar1,ar2);}

int main(int argc,char** argv) {
    system("chcp 65001");
    FILE* pInputFile = fopen(argv[1],"r");

    //Ввод данных тип, размер и массив
/*
    char* array_type = new char[10]; fscanf(pInputFile,"%s",array_type);

    Попытка на программном уровне определять тип данных. Не удачная
    printf("%s\n",array_type);
    if      (strcmp(array_type,"char")==0)   typedef char   arrayType;
    else if (strcmp(array_type,"int")==0)    typedef int    arrayType;
    else if (strcmp(array_type,"double")==0) typedef double arrayType;
*/
    size_t array_size; fscanf(pInputFile,"%d",&array_size);
    arrayType* inputArray = new arrayType[array_size];

    for (int i=0;i<array_size;i++) fscanf(pInputFile,"%d",&inputArray[i]);

    fclose(pInputFile);

    SearchElement<arrayType,arrayType>
            SearchEl(inputArray,
            array_size,
            funcChangeElement<arrayType>,
            funcSearchElement<arrayType>
                    );
    //UserInterface
    bool end = false;
    int start_pos=0,end_pos=(int)array_size-1;
    char act;
    printf("Введены входные данные:\n");
    while (!end)
    {
        printf("Текущий подотрезок:[%d %d]\n"
               "\'c\' - изменить границы подотрезка\n"
               "\'u\' - обновить элементы\n"
               "\'s\' - выполнить функцию\n"
               "\'v\' - просмотреть массив\n"
               "\'x\' - завершить работу\n",
        start_pos,end_pos);
       act = (char)tolower(getc(stdin)); fflush(stdin);
       switch(act)
       {
           default:
               printf("Неизвестная команда\n");
               break;

           case 'c':
               printf("Введите новые границы подотрезка\n");
               scanf("%d %d",&start_pos,&end_pos); fflush(stdin);
               break;

           case 's':
               printf("Результат работы заданной функции:\n");
               printf("%d\n", SearchEl.search(1, start_pos, end_pos, 0, array_size - 1));
               break;
           case 'v':
               printf("Входной массив:\n");
               SearchEl.watch_contents();
               printf("\n");
               break;
           case 'x':
               printf("Завершение работы\n");
               end=true;
               break;
           case 'u':
               printf("Каким образом изменить занчения \'1\'-функцией \'2\'-ввод вручную\n");
               int type = getc(stdin)-'0'; fflush(stdin);
               if (type==1) SearchEl.change_with_function(start_pos,end_pos);
               else{
                   arrayType newValues[end_pos-start_pos];
                   printf("Введите новые значения:\n");
                   for (int i=0;i<=end_pos-start_pos;i++) scanf("%d",&newValues[i]);
                   fflush(stdin);
                   SearchEl.change_with_new_values(start_pos,end_pos,newValues);
               }
               break;
       }
    }
    return 0;
}
