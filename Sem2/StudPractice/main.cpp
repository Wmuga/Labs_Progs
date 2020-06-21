#include <iostream>
#include <fstream>
#include <cctype>
#include <ctime>
#include "big_int.h"
#include "SearchInArray.h"
#include "functions.h"
#include "Logger.h"

typedef big_integer arrayType;

int main(int argc,char** argv) {
    clock_t time_start,time_end;
    char *message = new char[255];
    Log logger((char*)"D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractice\\Log\\");
    std::ifstream InputFile(argv[1]);
    std::string data_buffer;

    size_t array_size; InputFile>>array_size;
    arrayType* inputArray = new arrayType[array_size];
    time_start=clock();
    for (size_t i=0;i<array_size;i++)
        InputFile>>inputArray[i];
    time_end = clock();
    sprintf(message,"Time consumed for reading file: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
    logger.PutInLog(message);
    //Инициализация класса, вызов его конструктора

    time_start=clock();
    SearchElement<arrayType,arrayType>
            SearchEl(inputArray,
                     array_size,
                     funcIsElement<arrayType>,
                     funcSearchMin<arrayType>);
    time_end = clock();
    sprintf(message,"Time consumed for build tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
    logger.PutInLog(message);
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
               time_start = clock();
               std::cout << SearchEl.search(1, start_pos, end_pos, 0, array_size - 1) << std::endl;
               time_end = clock();
               sprintf(message,"Time consumed for executing function: %.15f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
               logger.PutInLog(message);
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
                      "\'5\' - number of elements of a certain value\n"
                      "\'6\' - minimal element more than certain value\n";
               int f_type; std::cin>>f_type; fflush(stdin);
               switch(f_type)
               {
                   default:
                       std::cout<<"Unknown choice\n";
                       break;
                   case(1):
                       time_start=clock();
                       SearchEl.change_elem_function(funcIsElement);
                       SearchEl.change_main_function(funcMultiply);
                       time_end = clock();
                       sprintf(message,"Time consumed for build tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
                       logger.PutInLog(message);
                       currentFunction=(char*)"Multiplication";
                       break;
                   case(2):
                       time_start=clock();
                       SearchEl.change_elem_function(funcIsElement);
                       SearchEl.change_main_function(funcSum);
                       time_end = clock();
                       sprintf(message,"Time consumed for rebuilding tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
                       logger.PutInLog(message);
                       currentFunction=(char*)"Summary";
                       break;
                   case(3):
                       time_start=clock();
                       SearchEl.change_elem_function(funcIsElement);
                       SearchEl.change_main_function(funcSearchMin);
                       time_end = clock();
                       sprintf(message,"Time consumed for rebuilding tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
                       logger.PutInLog(message);
                       currentFunction=(char*)"Search minimum";
                       break;
                   case(4):
                       time_start=clock();
                       SearchEl.change_elem_function(funcIsElement);
                       SearchEl.change_main_function(funcSearchMax);
                       time_end = clock();
                       sprintf(message,"Time consumed for rebuilding tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
                       logger.PutInLog(message);
                       currentFunction=(char*)"Search maximum";
                       break;
                   case(5):
                       std::cout<<"Enter value to compare elements\n";
                       std::cin >> eqValue<arrayType>; fflush(stdin);
                       time_start=clock();
                       SearchEl.change_main_function(funcSum);
                       SearchEl.change_elem_function(funcIsEquals);
                       time_end = clock();
                       sprintf(message,"Time consumed for rebuilding tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
                       logger.PutInLog(message);
                       currentFunction=(char*)"Count elements of a certain value";
                       break;
                   case(6):
                       std::cout<<"Enter value to compare elements\n";
                       std::cin >> eqValue<arrayType>; fflush(stdin);
                       time_start=clock();
                       SearchEl.change_elem_function(funcIsElement);
                       SearchEl.change_main_function(funcSearchMinMore);
                       time_end = clock();
                       sprintf(message,"Time consumed for rebuilding tree: %.6f seconds\n",(float)(time_end-time_start)/CLOCKS_PER_SEC);
                       logger.PutInLog(message);
                       currentFunction=(char*)"Minimal element more than certain value";
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
    delete []message;
    return 0;
}
