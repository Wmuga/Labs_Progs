#include "Func.h"
#include <cctype>

int main(int argc,char** argv) { //Параметры входные файлы для стэков 1й и 2й соответственно
    system("chcp 65001");//поддержка кириллицы
    stack *fStack,*sStack,*rStack;//стэки
    InitNewStack(&fStack);
    InitNewStack(&sStack);
    InitNewStack(&rStack);
    bool end = false;
    printf("Лабораторная работа #10\n");
    while(!end)
    {
        printf("\'N\' ввести стек с клавиатуры\n"
               "\'M\' ввести стек из файла\n"
               "\'V\' ввывести содержимое стека\n"
               "\'T\' решение задачи\n"
               "\'D\' освобождение стеков\n"
               "\'X\' Выход\n");
        int num;
        char act;
        scanf("%c",&act);
        fflush(stdin);
        act =(char)tolower(act);
        switch(act)
        {
            case 'n':
                printf("В 1й или 2й стек?\n");
                scanf("%d",&num); fflush(stdin);
                if (num==1) {InKeyboard(&fStack);}
                else InKeyboard(&sStack);
                break;
            case 'm':
                printf("В 1й или 2й стек?\n");
                scanf("%d",&num); fflush(stdin);
                if (num==1) InFile(&fStack, argv[1]);
                else InFile(&sStack, argv[2]);
                break;
            case 'v':
                printf("Первый стек:\n");
                stackShow(&fStack);
                printf("Второй стек:\n");
                stackShow(&sStack);
                printf("Результат задачи:\n");
                stackShow(&rStack);
                break;
            case 't':
                rStack=task(fStack,sStack);
                break;
            case 'd':
                InitNewStack(&fStack);
                InitNewStack(&sStack);
                InitNewStack(&rStack);
                break;
            case 'x':
                end=true;
                break;
            default:
                printf("Неизвестная команда\n");
                break;
        }
        printf("press ENTER\n"); getc(stdin); fflush(stdin);
    }
    End(&fStack,&sStack,&rStack); //Освобождение памяти
    return 0;
}