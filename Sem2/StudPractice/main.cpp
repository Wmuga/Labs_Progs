#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cctype>
#include "big_int.h"
#include "SearchInArray.h"
#include "functions.h"

typedef big_integer arrayType; //Пока считаем, что int. Вполне заменяемо на double, float и char

int main(int argc,char** argv) {
    //system("chcp 65001");
    setlocale(LC_ALL,"Russian");
    std::ifstream InputFile(argv[1]);
    std::string data_buffer;

    size_t array_size; InputFile>>array_size;
    arrayType* inputArray = new arrayType[array_size];

    for (size_t i=0;i<array_size;i++)
        InputFile>>inputArray[i];

    //Инициализация класса, вызов его конструктора
    SearchElement<arrayType,arrayType>
            SearchEl(inputArray,
                     array_size,
                     funcIsElement<arrayType>,
                     funcSearchMin<arrayType>);
    std::string currentFunction ="Поиск минимума"; //Изначально функция - поиск минимума
    //UserInterface
    bool end = false;
    size_t start_pos=0,end_pos=array_size-1; //Границы текущего отрезка
    char act;
    while (!end)
    {
        std::cout<<"Текущая функция \""<<currentFunction<<"\"\n"<<
               "Текущий подотрезок:["<<start_pos+1<<" "<<end_pos+1<<"]\n"<<
               "\'c\' - изменить границы подотрезка\n"<<
               "\'u\' - обновить элементы\n"<<
               "\'s\' - выполнить функцию\n"<<
               "\'m\' - изменить основную функцию\n"<<
               "\'v\' - просмотреть массив\n"<<
               "\'x\' - завершить работу\n";
       act = (char)tolower(getc(stdin)); fflush(stdin);
       switch(act)
       {
           default:
               std::cout<<"Неизвестная команда\n";
               break;

           case 'c':
               std::cout<<"Введите новые границы подотрезка\n";
               std::cin>>start_pos>>end_pos; fflush(stdin);
               start_pos--;
               end_pos--;
               break;

           case 's':
               std::cout<<"Результат работы заданной функции:\n";
               std::cout << SearchEl.search(1, start_pos, end_pos, 0, array_size - 1) << std::endl;
               break;
           case 'v':
               std::cout<<"Входной массив:\n";
               SearchEl.watch_contents();
               std::cout<<"\n";
               break;
           case 'x':
               std::cout<<"Завершение работы\n";
               end=true;
               break;
           case 'm':
               std::cout<<"Выберите на какую функцию изменить\n"
                      "\'1\' - произведение\n"
                      "\'2\' - сумма\n"
                      "\'3\' - минимум\n"
                      "\'4\' - максимум\n"
                      "\'5\' - количество элементов определенного значения\n";
               int f_type; std::cin>>f_type; fflush(stdin);
               switch(f_type)
               {
                   default:
                       std::cout<<"Неизвестная функция\n";
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
                       std::cout<<"Введите с каким значением желаете сравнивать элемнты\n";
                       std::cin >> eqValue<arrayType>; fflush(stdin);
                       currentFunction=(char*)"Расчет количества элементов";
                       break;
               }
               break;
           case 'u':
               std::cout<<"Каким образом изменить занчения \'1\'-функцией \'2\'-ввод вручную\n";
               int type = getc(stdin)-'0'; fflush(stdin);
               if (type==1) {
                   std::cout<<"Какой функцией изменить занчения:\n\'1\'- увеличить\n\'2\'- вычесть\n\'3\'- умножить\n\'4\'- разделить \n";
                   int ch_type = getc(stdin)-'0'; fflush(stdin);
                   std::cout<<"Каким числом менять значение?\n";
                   std::cin>>chValue<arrayType>; fflush(stdin);
                   switch (ch_type) {
                       default:
                           std::cout<<"Неизвестная функция\n";
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
                   std::cout<<"Введите новые значения:\n";
                   for (int i=0;i<=end_pos-start_pos;i++)
                       std::cin>>newValues[i];
                   fflush(stdin);
                   SearchEl.change_with_new_values(start_pos,end_pos,newValues);
               }
               break;
       }
    }
    return 0;
}
