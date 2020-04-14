#include <cstdio>
#include "Func.h"
#include <cctype>

int main(int argc, char** argv) {
    system("chcp 65001"); //Поддержка кириллицы Входной файл UTF-8
    printf("%40s","Лабараторная работа 7. Бинарный файл\n");
    bool end=false;
    while (!end)
    {
        printf("Выберите действие:\n"
               "\'N\' создать бинарный файл\n"
               "\'V\' просмотреть содержимое бинарного файла\n"
               "\'F\' найти элемент по ключу\n"
               "\'C\' корректировка содержимого\n"
               "\'X\' завершить\n");
        char act;
        act=(char)getc(stdin);
        fflush(stdin);
        act =(char)tolower(act);
        switch(act)
        {
            case 'n':
                CreateNew(argv[1], argv[2]);
                break;
            case 'v':
                ViewBinary(argv[2]);
                break;
            case 'f':
                SearchContent(argv[2]);
                break;
            case 'c':
                ChangeContent(argv[2]);
                break;
            case 'x':
                end=true;
                break;
            default:
                printf("Неизвестная команда\n");
                break;
        }
        printf("-------------------------------\n");
    }
    return 0;
}