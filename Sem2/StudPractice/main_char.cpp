#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include "SearchInArray.h"
#include "functions.h"

typedef char arrayType; //Пока считаем, что int. Вполне заменяемо на double, float и char

int main(int argc,char** argv) {
    system("chcp 65001");
    FILE* pInputFile = fopen(argv[1],"r");
    char* char_buffer = new char[256];

    size_t array_size; fscanf(pInputFile,"%d",&array_size);
    arrayType* inputArray = new arrayType[array_size];

    for (size_t i=0;i<array_size;i++) {
        fscanf(pInputFile, "%s", char_buffer);
        inputArray[i] = char_buffer[0];
    }

    fclose(pInputFile);
    //Инициализация класса, вызов его конструктора
    SearchElement<arrayType,arrayType>
            SearchEl(inputArray,
                     array_size,
                     funcIsElement<arrayType>,
                     funcSearchMin<arrayType>);
    char* currentFunction = (char*)"Поиск минимума"; //Изначально функция - поиск минимума
    //UserInterface
    bool end = false;
    size_t start_pos=0,end_pos=array_size-1; //Границы текущего отрезка
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
        currentFunction,start_pos+1,end_pos+1);
       act = (char)tolower(getc(stdin)); fflush(stdin);
       switch(act)
       {
           default:
               printf("Неизвестная команда\n");
               break;

           case 'c':
               printf("Введите новые границы подотрезка\n");
               scanf("%d %d",&start_pos,&end_pos); fflush(stdin);
               start_pos--;
               end_pos--;
               break;

           case 's':
               printf("Результат работы заданной функции:\n");
               std::cout << SearchEl.search(1, start_pos, end_pos, 0, array_size - 1) << std::endl;
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
                      "\'4\' - максимум\n"
                      "\'5\' - количество элементов определенного значения\n");
               int f_type; scanf("%d",&f_type); fflush(stdin);
               switch(f_type)
               {
                   default:
                       printf("Неизвестная функция\n");
                       break;
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
                   case(5):
                       SearchEl.change_main_function(funcSum);
                       SearchEl.change_elem_function(funcIsEquals);
                       printf("Введите с каким значением желаете сравнивать элемнты\n");
                       scanf("%s", char_buffer); fflush(stdin);
                       eqValue<arrayType> = char_buffer[0];
                       currentFunction=(char*)"Расчет количества элементов";
                       break;
               }
               break;
           case 'u':
               printf("Каким образом изменить занчения \'1\'-функцией \'2\'-ввод вручную\n");
               int type = getc(stdin)-'0'; fflush(stdin);
               if (type==1) {
                   printf("Какой функцией изменить занчения:\n\'1\'- увеличить\n\'2\'- вычесть\n\'3\'- умножить\n\'4\'- разделить \n");
                   int ch_type = getc(stdin)-'0'; fflush(stdin);
                   printf("Каким числом менять значение?\n");
                   scanf("%s", char_buffer); chValue<arrayType> = char_buffer[0]; fflush(stdin);
                   switch (ch_type) {
                       default:
                           printf("Неизвестная функция\n");
                           break;
                       case(1):
                           SearchEl.change_with_function(start_pos, end_pos, funcIncElement);
                           break;
                       case(2):
                           SearchEl.change_with_function(start_pos, end_pos, funcDecElement);
                           break;
                       case(3):
                           SearchEl.change_with_function(start_pos, end_pos, funcMultiElement);
                           break;
                       case(4):
                           SearchEl.change_with_function(start_pos, end_pos, funcDivElement);
                           break;
                   }
               }
               else{
                   arrayType newValues[end_pos-start_pos];
                   printf("Введите новые значения:\n");
                   for (int i=0;i<=end_pos-start_pos;i++) {
                       scanf("%s", char_buffer);
                       newValues[i] = char_buffer[0];
                   }
                   fflush(stdin);
                   SearchEl.change_with_new_values(start_pos,end_pos,newValues);
               }
               break;
       }
    }
    delete []char_buffer;
    delete []currentFunction;
    return 0;
}
