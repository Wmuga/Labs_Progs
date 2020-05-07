#include <ctime>

FILE *pLog;

void InitLogger(char* LogFolder)
{
    char* logName = new char[255];
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [255];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,255," %d-%b-%Y %H.%M.%S",timeinfo);
    snprintf(logName,255,"%sLog%s.txt",LogFolder,buffer);

    pLog = fopen(logName,"w");
    delete []logName;
}

void PutInLog(char* info)
{
    fprintf(pLog,"%s",info);
    fflush(pLog);
}

void EndLogger()
{
    fclose(pLog);
}