struct date         //Дата
{
    int day;        //День
    int month;      //Месяц
    int year;       //Год
};
struct data         //Данные
{
    char*  FName;   //Имя
    char*  SName;   //Фамилия
    char*  LName;   //Отчество
    date  dBirth;   //Дата рождения
    date  dDeath;   //Смерти (опционально)
    char* BPlace;   //Место рождения(опционально)
};
data nullData = {nullptr,nullptr,nullptr, {0,0,0}, {0,0,0},nullptr};