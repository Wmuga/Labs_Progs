#include <cstdio>
#include <windows.h>
#include "tree.h"
#include "Func.h"
#include <ctime>

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [255];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,255," %d-%b-%Y %H.%M.%S",timeinfo);

    SetConsoleOutputCP(1251);
    char* logName = new char[256];
    logName[0]='D'; logName[1]=':'; logName[2]='\\';
    strcat(logName,"Documents\\GitHub\\Labs_Progs\\Sem2\\TC\\Logs\\Log");
    strcat(logName,buffer);
    strcat(logName,".txt");
    FILE *pLog = fopen(logName,"w");

    Init();
    printf("Khu");
    fprintf(pLog,"Initialised Tree\n");
    fflush(pLog);
    MakeTree(pLog);
    fprintf(pLog,"Maked Tree\n");
    remove(current);
    fclose(pLog);
    return 0;
}