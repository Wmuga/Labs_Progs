#include <cstdlib>
//Массив названий пород
char* catType[] = {(char*)"Сиамский",(char*)"Мейн-кун",(char*)"Британская",(char*)"Сибирская",(char*)"Сфинкс",(char*)"Тайская"};

struct Cat //Структура она же запись
{
    int   type;        //Порода (храниться как индекс по массиву)
    char  name[30];    //Кличка
    char  color[30];   //Окрас
    int   age;         //Возраст
    char  OSName[30];  //Фамилия хозяина
    int   place;       //Место
};

void CreateNew(char* in, char* out) //Создание нового файла
{
    FILE* inp  = fopen(in,"r");    //Открытие файлов ввода и вывода
    FILE* outp = fopen(out,"wb");  //Приписка b - бинарный файл
    int count = 0;
    while (true)   //Считывание данных
    {
        Cat newCat;
        char buffer[3];
        fscanf(inp,"%s",buffer);  newCat.type = atoi(buffer);
        if (newCat.type==0 || feof(inp)) break;  //Проверка на окончание файла или стоп-знак
        fscanf(inp,"%30s",newCat.name);
        fscanf(inp,"%30s",newCat.color);
        fscanf(inp,"%s",buffer); newCat.age = atoi(buffer);
        fscanf(inp,"%30s",newCat.OSName);
        fscanf(inp,"%s",buffer); newCat.place = atoi(buffer);
        fwrite(&newCat, sizeof(Cat),1,outp);
        count++;
    }
    fclose(inp);
    fclose(outp);
    if (count==0) printf("Создан пустой файл\n");
    else printf("Создан файл с %d записями\n",count);
    printf("-------------------------------\nНажмите ENTER чтобы продолжить\n");
    fgetc(stdin); fflush(stdin);
}

void ViewBinary(char* file) //Просмотр файла
{
    FILE* pFBin = fopen(file,"rb");
    int count=0;
    while (true)  //Считывание данных....
    {
        Cat newCat;
        fread(&newCat, sizeof(newCat),1,pFBin);
        if (feof(pFBin)) break;    //...пока не конец файла
        printf("Кот %d:\n  Кличка: %s\n  Порода: %s\n  Окрас: %s\n  Возраст: %d\n  Хозяин: %s\n  Место: %d\n",
                count+1,newCat.name,catType[newCat.type-1],newCat.color,newCat.age,newCat.OSName,newCat.place);
        count++;
    }
    fclose(pFBin);
    if (count==0) printf("Пустой файл\n");
    printf("-------------------------------\nНажмите ENTER чтобы продолжить\n");
    fgetc(stdin); fflush(stdin);
}

void SearchContent(char* file) //Поиск по ключу
{
    int i=-1,count=0, av_age=0;
    FILE* pFBin = fopen(file,"rb");
    do //Пока не конец файла
    {
        Cat newCat;
        i++;
        fread(&newCat, sizeof(newCat),1,pFBin); //Считывание
        if (newCat.type==1 and newCat.place<=10 and !feof(pFBin)) //проверка на условие
        {
            count++;
            printf("Найден кот:\n  Кличка: %s\n  Порода: %s\n  Окрас: %s\n  Возраст: %d\n  Хозяин: %s\n  Место: %d\n",
                   newCat.name,catType[newCat.type-1],newCat.color,newCat.age,newCat.OSName,newCat.place);
            av_age+=newCat.age;
        }
    }while(!feof(pFBin));
    fclose(pFBin);
    if (i==0) printf("Пустой файл\n");
    else if (count==0) printf("Не найдено элементов, удовлетворяющих условию\n");
    else printf("Средний возраст котов:%d\n",av_age/count);
    printf("-------------------------------\nНажмите ENTER чтобы продолжить\n");
    fgetc(stdin); fflush(stdin);
}

void ChangeContent(char* file) //Корректировка содержимого
{
    int i=-1,count=0;
    Cat newCat;
    FILE* pFBin = fopen(file,"rb+");
    do {
        bool flag = false;
        i++;
        fread(&newCat, sizeof(newCat), 1, pFBin);
        //Условия замены
        if (!feof(pFBin)){ //Проверка на конец файла
        if (newCat.age < 0) {
            newCat.age = 0;
            flag = true;
        }
        if (newCat.age > 15) {
            newCat.age = 15;
            flag = true;
        }
        if (newCat.place < 0) {
            newCat.place = abs(newCat.place);
            flag = true;
        }
        //---
        if (flag) {
            printf("Исправлена %d запись:\n  Кличка: %s\n  Порода: %s\n  Окрас: %s\n  Возраст: %d\n  Хозяин: %s\n  Место: %d\n",
                   i+1, newCat.name, catType[newCat.type - 1], newCat.color, newCat.age, newCat.OSName, newCat.place);
            count++;
            fseek(pFBin, 0 - sizeof(newCat), SEEK_CUR); //Двигаемся на заменяемую запись
            fwrite(&newCat, sizeof(Cat), 1, pFBin); //перезаписываем
            fseek(pFBin, 0, SEEK_CUR);
        }
    }
    }while(!feof(pFBin));
    fclose(pFBin);
    if (i==0) printf("Пустой файл\n");
    else if (count==0) printf("Ничего не изменено\n");
    else printf("Сделано %d изменений\n",count);
    printf("-------------------------------\nНажмите ENTER чтобы продолжить\n");
    fgetc(stdin); fflush(stdin);
}