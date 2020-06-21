#include <ctime>
#include <cstdlib>
/*
 * Собственоручно созданная "библиотека" для логов
 */

class Log
{
private:
    FILE *pLog; //Указатель на файл лога, доступен всем
public:
    //Открытие файла, передается папка для логоа
    Log(char* LogFolder)
    {
        char* logName = new char[255];
        time_t rawtime;
        struct tm * timeinfo;
        char buffer [255];

        time (&rawtime);
        timeinfo = localtime (&rawtime);
        strftime (buffer,255," %d-%b-%Y %H.%M.%S",timeinfo);
        snprintf(logName,255,"%sLog%s.txt",LogFolder,buffer);
        //Имя файла - пака\Log - день-месяц-год час.минута.секунда.txt на момент создания
        pLog = fopen(logName,"w");
        if (pLog==nullptr) throw 0; //Возможность отправить код ошибки, если файл не открыт
        delete []logName; //Сразу же очищаем лишнюю память
    }
    //Просто отправляет в лог сообщение (char*)
    void PutInLog(char* info)
    {
        fprintf(pLog,"%s",info);
        fflush(pLog);
    }
    void PutInLog(int info)
    {
        fprintf(pLog,"%d\n",info);
        fflush(pLog);
    }
#ifdef _GLIBCXX_STRING
    void PutInLog(std::string info)
    {
        const char* msg = info.c_str();
        fprintf(pLog,"%s",msg);
        fflush(pLog);
        delete []msg;
    }
#endif
    //Закрытие файла
   ~Log()
    {
        fclose(pLog);
    }

};
