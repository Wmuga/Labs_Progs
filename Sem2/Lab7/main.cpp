#include <cstdio>
#include "Func.h"
#include <cctype>

int main(int argc, char** argv) {
    printf("Lab 7. Binary File\n");
    bool end=false;
    while (!end)
    {
        printf("Choose what you want to do:\n"
               "\'N\' to create new binary file\n"
               "\'V\' to view content of binary file\n"
               "\'F\' to find element by key\n"
               "\'C\' to correct elements\n"
               "\'X\' to exit\n");
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
                printf("Unknown command\n");
                break;
        }
        printf("-------------------------------\n");
    }
    return 0;
}