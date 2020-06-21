#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cctype>
#include "big_int.h"
#include "SearchInArray.h"
#include "functions.h"

typedef big_integer arrayType; //Пока считаем, что int. Вполне заменяемо на double, float и char

int main(int argc,char** argv) {
    //system("chcp 1251");
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
    std::string currentFunction ="Search minimum"; //Изначально функция - поиск минимума
    //UserInterface
    bool end = false;
    size_t start_pos=0,end_pos=array_size-1; //Границы текущего отрезка
    char act;
    while (!end)
    {
        std::cout<<"Current function\""<<currentFunction<<"\"\n"<<
               "Current segment:["<<start_pos+1<<" "<<end_pos+1<<"]\n"<<
               "\'c\' - change segment\n"<<
               "\'u\' - update elements\n"<<
               "\'s\' - run function\n"<<
               "\'m\' - change main function\n"<<
               "\'v\' - show array\n"<<
               "\'x\' - shutdown\n";
       act = (char)tolower(getc(stdin)); fflush(stdin);
       switch(act)
       {
           default:
               std::cout<<"Unknown command\n";
               break;

           case 'c':
               std::cout<<"Enter new segment boundaries\n";
               std::cin>>start_pos>>end_pos; fflush(stdin);
               start_pos--;
               end_pos--;
               break;

           case 's':
               std::cout<<"Function result:\n";
               std::cout << SearchEl.search(1, start_pos, end_pos, 0, array_size - 1) << std::endl;
               break;
           case 'v':
               std::cout<<"Array:\n";
               SearchEl.watch_contents();
               std::cout<<"\n";
               break;
           case 'x':
               std::cout<<"Shutting down\n";
               end=true;
               break;
           case 'm':
               std::cout<<"Choose new function\n"
                      "\'1\' - multiply\n"
                      "\'2\' - sum\n"
                      "\'3\' - minimum\n"
                      "\'4\' - maximum\n"
                      "\'5\' - number of elements of a certain value\n";
               int f_type; std::cin>>f_type; fflush(stdin);
               switch(f_type)
               {
                   default:
                       std::cout<<"Unknown choice\n";
                       break;
                   case(1):
                       SearchEl.change_main_function(funcMultiply);
                       currentFunction=(char*)"Multiplication";
                       break;
                   case(2):
                       SearchEl.change_main_function(funcSum);
                       currentFunction=(char*)"Summary";
                       break;
                   case(3):
                       SearchEl.change_main_function(funcSearchMin);
                       currentFunction=(char*)"Search minimum";
                       break;
                   case(4):
                       SearchEl.change_main_function(funcSearchMax);
                       currentFunction=(char*)"Search maximum";
                       break;
                   case(5):
                       SearchEl.change_main_function(funcSum);
                       SearchEl.change_elem_function(funcIsEquals);
                       std::cout<<"Enter value to compare elements\n";
                       std::cin >> eqValue<arrayType>; fflush(stdin);
                       currentFunction=(char*)"Count elements of a certain value";
                       break;
               }
               break;
           case 'u':
               std::cout<<"How to change elements? \'1\'- by function \'2\'- manually\n";
               int type = getc(stdin)-'0'; fflush(stdin);
               if (type==1) {
                   std::cout<<"What type of function use:\n\'1\'- increase\n\'2\'- decrease\n\'3\'- multiply\n\'4\'- divide \n";
                   int ch_type = getc(stdin)-'0'; fflush(stdin);
                   std::cout<<"What value to use?\n";
                   std::cin>>chValue<arrayType>; fflush(stdin);
                   switch (ch_type) {
                       default:
                           std::cout<<"Unknown choice\n";
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
                   std::cout<<"Enter new values:\n";
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
