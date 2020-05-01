#include <cstdio>
#include <windows.h>
#include "tree.h"
//#include "treeR2.h" (вторая реализация дерева)
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

    char* logName = new char[255];
    snprintf(logName,255,"%sLog%s.txt",argv[2],buffer);

    FILE *pLog = fopen(logName,"w");

    Init();
    fprintf(pLog,"Initialised Tree\n");
    fflush(pLog);
    MakeTree(pLog, argv[1]);
    ShowTree(head);

    remove(&head,pLog);
    fclose(pLog);
    delete []logName;
    return 0;
}