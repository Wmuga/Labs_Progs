#include <cstdio>
#include <windows.h>
#include "tree.h"
#include "Func.h"
#include <ctime>

int main(int argc, char** argv) { //Параметры - входной файл, Папка Логов
    system("chcp 65001");

    time_t rawtime;
    struct tm * timeinfo;
    char buffer [255];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,255," %d-%b-%Y %H.%M.%S",timeinfo);

    char* logName = argv[2];
    strcat(logName,"Log");
    strcat(logName,buffer);
    strcat(logName,".txt");
    FILE *pLog = fopen(logName,"w");

    Init();
    fprintf(pLog,"Initialised Tree\n");
    fflush(pLog);
    MakeTree(pLog, argv[1]);
    ShowTree(head);
    remove(&head,pLog);
    fclose(pLog);
    return 0;
}