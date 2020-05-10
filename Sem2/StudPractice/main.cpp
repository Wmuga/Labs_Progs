#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "SearchInArray.h"
#include "functions.h"
typedef int arrayType; //Пока считаем, что int. Вполне заменяемо на double, float и char

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

    for (size_t i=0;i<array_size;i++) fscanf(pInputFile,"%d",&inputArray[i]);

    fclose(pInputFile);

    SearchElement<arrayType,arrayType>
            SearchEl(inputArray,
                     array_size,
                     funcIsElement<arrayType>,
                     funcSearchMin<arrayType>);
    char* currentFunction = (char*)"Поиск минимума";
    //UserInterface
    bool end = false;
    int start_pos=0,end_pos=(int)array_size-1;
    char act;
    while (!end)
    {
        printf("Текущая функция \"%s\"\n"
               "Текущий подотрезок:[%d %d]\n"
               "\'c\' - изменить границы подотрезка\n"
               "\'u\' - обновить элементы\n"
               "\'s\' - выполнить функцию\n"
               "\'m\' - изменить основную функцию\n"
               "\'v\' - просмотреть массив\n"
               "\'x\' - завершить работу\n",
        currentFunction,start_pos,end_pos);
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
           case 'm':
               printf("Выберите на какую функцию изменить\n"
                      "\'1\' - произведение\n"
                      "\'2\' - сумма\n"
                      "\'3\' - минимум\n"
                      "\'4\' - максимум\n");
               int f_type; scanf("%d",&f_type); fflush(stdin);
               switch(f_type)
               {
                   default:
                       printf("Неизвестная функция\n");
                   case(1):
                       SearchEl.change_main_function(funcMultiply);
                       currentFunction=(char*)"Поиск произведения";
                       break;
                   case(2):
                       SearchEl.change_main_function(funcSum);
                       currentFunction=(char*)"Поиск суммы";
                       break;
                   case(3):
                       SearchEl.change_main_function(funcSearchMin);
                       currentFunction=(char*)"Поиск минимума";
                       break;
                   case(4):
                       SearchEl.change_main_function(funcSearchMax);
                       currentFunction=(char*)"Поиск максимума";
                       break;
               }
               break;
           case 'u':
               printf("Каким образом изменить занчения \'1\'-функцией \'2\'-ввод вручную\n");
               int type = getc(stdin)-'0'; fflush(stdin);
               if (type==1) SearchEl.change_with_function(start_pos, end_pos, funcIsElement);
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
    delete []currentFunction;
    return 0;
}
