#include "Logger.h"

/* Функция вывода полной информации.
 * Может выводить в консоль по умолчанию или в в другой поток
 * В частности - файл лога
 * Чтобы не писать нескольно раз, вынесено в отдельную функцию
 * входные параметры: данные, поток для вывода
*/
void ShowData(data info,FILE *pfile=stdout)
{
    //Основные данные
    fprintf(pfile, "%s %s %s Родился %d.%d.%d ", info.SName, info.FName, info.LName, info.dBirth.day, info.dBirth.month, info.dBirth.year);
    //Если есть дата смерти - выводим и ее
    if (info.dDeath.day) fprintf(pfile, "Умер %d.%d.%d ", info.dDeath.day, info.dDeath.month, info.dDeath.year);
    //Так же и место рождения
    if (strcmp(info.BPlace,"--")!=0) fprintf(pfile, "Родился в %s", info.BPlace);
    fprintf(pfile, "\n");
    fflush(pfile);
}

/* Первый способ выведения дерева Корень-лево-право
 * Может выводить по умолчанию в консоль, или в другой поток
 * В частности - лог
 * входные параметры: данные, поток для вывода, глубина текущаего элемента в дереве
 */
void ShowTree1(NodePtr TreeHead, FILE *pfile= stdout, int depth= 0){
    //Проверка на стоп-знак, если вызвана вне рекурсии
    if (strcmp(getData(TreeHead).FName,"**")==0 or IsEmpty(TreeHead)) fprintf(pfile,"**\n");
    else {
        fprintf(pfile, "%*s", depth * 2 + 3, "-- ");
        fflush(pfile);
        //выводим данные
        ShowData(getData(TreeHead), pfile);
        //проверяем на пустоту лево, право и выводим данные оттуда, если есть
        if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName, "**") != 0)
            ShowTree1(curL(TreeHead), pfile, depth + 1);
        if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName, "**") != 0)
            ShowTree1(curR(TreeHead), pfile, depth + 1);
    }
}

/* Второй способ выведения дерева лево-корень-право
 * Может выводить по умолчанию в консоль, или в другой поток
 * В частности - лог
 * входные параметры: данные, поток для вывода, глубина текущаего элемента в дереве
 */
void ShowTree2(NodePtr TreeHead,FILE *pfile=stdout, int depth=0) {
    //Проверка на стоп-знак, если вызвана вне рекурсии
    if (IsEmpty(TreeHead) or strcmp(getData(TreeHead).FName,"**")==0) fprintf(pfile,"**\n");
    else {
        //проверяем на пустоту лево и выводим данные оттуда, если есть
        if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName,"**")!=0) ShowTree2(curL(TreeHead), pfile,depth+1);
        fprintf(pfile,"%*s",depth*2+3,"-- "); fflush(pfile);
        //Нынещние данные
        ShowData(getData(TreeHead),pfile);
        //проверяем на пустоту  право и выводим данные оттуда, если есть
        if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0)ShowTree2(curR(TreeHead), pfile,depth+1);
    }
}

/* Третий способ выведения дерева лево-право-корень
 * Может выводить по умолчанию в консоль, или в другой поток
 * В частности - лог
 * входные параметры: данные, поток для вывода, глубина текущаего элемента в дереве
 */
void ShowTree3(NodePtr TreeHead,FILE *pfile=stdout, int depth=0) {
    //Проверка на стоп-знак, если вызвана вне рекурсии
    if (IsEmpty(TreeHead) or strcmp(getData(TreeHead).FName,"**")==0) fprintf(pfile,"**\n");
    else {
        //проверяем на пустоту лево, право и выводим данные оттуда, если есть
        if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName,"**")!=0) ShowTree2(curL(TreeHead), pfile,depth+1);
        if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0) ShowTree2(curR(TreeHead), pfile,depth+1);
        fprintf(pfile,"%*s",depth*2+3,"-- "); fflush(pfile);
        //Текущие данные
        ShowData(getData(TreeHead),pfile);
    }
}


/*
 * Способ вывода дерева только для сортированного дерева
 * Или же вывод плана поминок
 * Входные параметры: указатель на текущее положение, поток вывода
 */
void ShowTree(NodePtr TreeHead, FILE *pfile= stdout) {
    //Проверка на стоп-знак, если вызвана вне рекурсии
    if (IsEmpty(TreeHead) or strcmp(getData(TreeHead).FName,"**")==0) fprintf(pfile,"**\n");
    else {
        //По сортировке, что меньше - лево, поэтому идем Лево-Корень-Право
        if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName,"**")!=0)
            ShowTree(curL(TreeHead), pfile);
        data info = getData(TreeHead);
        fprintf(pfile, "%10s %10s %10s | Умер %d.%d.%d\n", info.SName, info.FName, info.LName, info.dDeath.day, info.dDeath.month, info.dDeath.year);
        fflush(pfile);
        if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0)
            ShowTree(curR(TreeHead), pfile);
    }
}
/*
 * Добавление элемента в отсортированное дерево
 * Входной параметр - данные для записи
 */
void AddToTreeKey(data currentData)
{
    PutInLog((char*)"Элемент: ");
    ShowData(currentData,pLog);
    NodePtr CurrentPosition=getStartSorted(); //Начинаем с корня
    while (!IsEmpty(CurrentPosition) and strcmp(getData(CurrentPosition).FName,"**")!=0) //Пока не пустой элемент
    {
        PutInLog((char*)"Сравнение текущего элемента с ");
        data prevData = getData(CurrentPosition);
        ShowData(prevData,pLog);
        //Сравнение текущего элемента с новым и определение его влево или вправо
        if ((prevData.dDeath.day-currentData.dDeath.day)+
            (prevData.dDeath.month-currentData.dDeath.month)*31>0)
        {
            CurrentPosition = curL(CurrentPosition);
            PutInLog((char*)"Переход влево\n");
        }
        else {
            CurrentPosition = curR(CurrentPosition);
            PutInLog((char*)"Переход вправо\n");
        }
    }
    //Запись
    replDataM(&CurrentPosition,currentData);
    PutInLog((char*)"Элемент записан\n");
    //Предопределение, что следующие пустые, потом по необходимости заменяются
    replDataR(&CurrentPosition,nullData);
    replDataL(&CurrentPosition,nullData);
}

// Рекурсия для построения отсортированного дерева
void TreeSortedBranches(NodePtr CurrentPositionOfUnsorted)
{
    data currentData = getData(CurrentPositionOfUnsorted);
    if (strcmp(currentData.FName,"**")!=0 and !IsEmpty(CurrentPositionOfUnsorted) and currentData.dDeath.day) { //Проверка на пустоту
        AddToTreeKey(currentData);
    }
    if (!IsEmpty(curL(CurrentPositionOfUnsorted)) and
        strcmp(getData(curL(CurrentPositionOfUnsorted)).FName, "**") != 0)
        //Если слева не пусто - вызываем для левой части
        TreeSortedBranches(curL(CurrentPositionOfUnsorted));
    if (!IsEmpty(curR(CurrentPositionOfUnsorted)) and
        strcmp(getData(curR(CurrentPositionOfUnsorted)).FName, "**") != 0)
        //Если справа не пусто - вызываем для правой части
        TreeSortedBranches(curR(CurrentPositionOfUnsorted));
}


//Инициализатор создания отсортированного дерева
void MakeTreeKey()
{
    PutInLog((char*)"Построение отсортированного дерева\n");
    TreeSortedBranches(getStartUnsorted()); //Создание ветвей
    PutInLog((char*)"Создано дерево:\n");
    ShowTree1(getStartSorted(), pLog);//вывод в лог
    PutInLog((char*)"План поминок выглядит:\n");
    ShowTree(getStartSorted(), pLog);
}

//Поиск человека, у которого обоих дедушек зовут Иванами
int Task(NodePtr CurrentPosition)
{
    //Проверка на пустоту текущей позиции
    if (IsEmpty(CurrentPosition) or strcmp(getData(CurrentPosition).FName,"**")==0)
    {
        printf("Невозможно выполнить поиск на пустом дереве\n");
        PutInLog((char*)"Функция вызвана на путом дереве\n");
    } else {
        PutInLog((char *) "Проверка элемента ");
        ShowData(getData(CurrentPosition), pLog);
        //Проверка на наличие родителей и дедушек
        if ( !IsEmpty(curL(CurrentPosition)) and !IsEmpty(curR(CurrentPosition)) and
            strcmp(getData(curL(CurrentPosition)).FName, "**") != 0 and
            strcmp(getData(curR(CurrentPosition)).FName, "**") != 0 and
            !IsEmpty(curL(curL(CurrentPosition))) and !IsEmpty(curR(curL(CurrentPosition)))
                )
        {
            PutInLog((char *) "У элемента найдены дедушки:\n");
            //Считываение дедушек
            data grandL = getData(curL(curL(CurrentPosition)));
            data grandR = getData(curL(curR(CurrentPosition)));
            ShowData(grandL,pLog);
            ShowData(grandR,pLog);
            //Проверка имени
            if (strcmp(grandL.FName, "Иван") == 0 and strcmp(grandR.FName, "Иван") == 0)
            {
                PutInLog((char *) "Элемент соответсвует поиску\n");
                return 1;
            }
            PutInLog((char *) "Не соответствует поиску\n");
        }
        else {
            PutInLog((char *) "У элемента нет дедушек\n");
        }
        //Если элемент не прошел проверку, пускаем по следующим элементам
        return ((
                        (!IsEmpty(curL(CurrentPosition))) and (Task(curL(CurrentPosition))))
                or ((!IsEmpty(curR(CurrentPosition))) and (Task(curR(CurrentPosition))))
        );
    }
    return 0;
}

/*
 * Чтение данных их потока(второй параметр).
 * Если считывается из стандартного текстового файла(консоль) -
 * выводятся подсказки для пользователя
 * Чтобы не писать нескольно раз, вынесено в отдельную функцию
 */
data readData(char* FName, FILE* FileIn=stdin)
{
    //FName находится в параметрах т.к. при считывании из файла проверяется на стоп-знак или eof
    char *SName = new char[10];
    char *LName = new char[10];
    char *BPlace = new char[50];

    char* buffer = new char[10];
    fscanf(FileIn, "%s", SName);
    fscanf(FileIn, "%s", LName);

    int day, month, year;
    if (FileIn==stdin) printf("Введите дату рождения\n");
    //Чтобы предотвратить вылет из-за неправильных данных, записываем сначала в буффер,
    //потом пытаемся конвертировать в число
    fscanf(FileIn, "%s", buffer); day   = strtol(buffer,nullptr,10);
    fscanf(FileIn, "%s", buffer); month = strtol(buffer,nullptr,10);
    fscanf(FileIn, "%s", buffer); year  = strtol(buffer,nullptr,10);
    date dBirth = {day, month, year};
    //Поверка на правильность даты, иначе - выдаем код ошибки
    if (day<1 or day>31 or month<1 or month>12 or year<1) throw 3;

    if (FileIn==stdin) printf("Введите дату смерти.\n");
    //Чтобы предотвратить вылет из-за неправильных данных, записываем сначала в буффер,
    //потом пытаемся конвертировать в число (в данном случае ошибка в формате даты распознается как отсутствие даты)
    fscanf(FileIn, "%s", buffer); day   = strtol(buffer,nullptr,10);
    fscanf(FileIn, "%s", buffer); month = strtol(buffer,nullptr,10);
    fscanf(FileIn, "%s", buffer); year  = strtol(buffer,nullptr,10);
    if (month==0 or year==0) day=0; //т.к. вся проверка даты смерти ведется через день, то если хоть где-то есть 0, то в дне тоже обязательно должен быть 0
    date dDeath = {day, month, year};
    //Поверка на правильность даты, иначе - выдаем код ошибки. Расширен до 0, т.к. может не быть даты смерти
    if (day<0 or day>31 or month<0 or month>12 or year<0) throw 3;

    if (FileIn==stdin) printf("Введите место рождения или \"--\"\n");
    fscanf(FileIn, "%s", BPlace);
    delete []buffer;
    return {FName,SName,LName,dBirth,dDeath,BPlace};
}

//Формирование ветвей генеалогического древа.
void TreeBranches(FILE *FileIn,NodePtr* CurrentPosition)
{
    //Считываем первый символ
    char *buffer = new char[50];
    fscanf(FileIn,"%s",buffer);
    data newinfo{};
    //Если не конец файла - смотрим является ли стоп-знаком
    if (!feof(FileIn)) {
        NodePtr next;
        if (strcmp(buffer,"**")!=0) {
            PutInLog((char*)"Найден новый элемент\n");
            //Cчитываем из входного файла
            newinfo = readData(buffer,FileIn);
            PutInLog((char*)"Прочитан новый элемент\n");
            //Дальше - лево, создаем пустой элемент
            next = NewNode(CurrentPosition,'L');
            replDataM(CurrentPosition,newinfo);
            replDataR(CurrentPosition,nullData); //Так как бинарный файл не забивает пустые позиции nullptr-м, предопределяем их нулевыми данными
            PutInLog((char*)"Создана ветвь "); ShowData(getData(*CurrentPosition),pLog);
            PutInLog((char*)"Переход влево\n");
        }
        else
        {
            PutInLog((char*)"Прочитан cтоп-знак\n");
            newinfo = {(char*)"**"};
            replDataM(CurrentPosition,newinfo);
            //Если прочитали стоп-знак, возвращаемся назад, пока не найдем справа пустое место
            do
            {
                *CurrentPosition = back(CurrentPosition);
                PutInLog((char*)"Возврат на предыдущую позицию\n");
            }while(!IsEmpty(curR(*CurrentPosition)) and (*CurrentPosition)!=getStartUnsorted());
            if (!IsEmpty(curR(*CurrentPosition))) throw 4;
            //Нашли - идем вправо
            next = NewNode(CurrentPosition,'R');
            PutInLog((char*)"Переход вправо\n");
        }
        TreeBranches(FileIn, &next);
    }
    else{ //Так как последний ** считывается, но не обрабатывается - делаем сами
        PutInLog((char*)"Конец файла\n");
        newinfo = {(char*)"**"};
        replDataM(CurrentPosition,newinfo);
    }
}
//Инициализатор создания неупорядоченного дерева
void MakeTree(char* filename)
{
    PutInLog((char*)"Построение обыкновенного дерева\n");
    FILE* in = fopen(filename,"r");
    if (in==nullptr) throw 1; //Если файл не удалось открыть - сообщаем
    NodePtr headUnsorted = getStartUnsorted();
    TreeBranches(in,&headUnsorted); //Запускаем создание дерева
    fclose(in);
    PutInLog((char *)"Создано дерево:\n");
    ShowTree1(headUnsorted, pLog);

}
//Уничтожение ветви или целого дерева
void remove(NodePtr *cur)
{
    //Проверяем какое дерево уничтожаем, соответствующе отчитываемся
    if ((*cur)==getStartUnsorted()) {
        PutInLog((char*)"Уничтожено обыкновенное дерево\n");
        destroy(cur);
    }
    else if ((*cur)==getStartSorted()) {
        PutInLog((char*)"Уничтожено отсортированное дерево\n");
        destroy(cur);
    }
    //Есть возможность "обрубания" одной из ветвей, но не используется
    else{
        PutInLog((char*)"Уничтожена ветвь "); ShowData(getData(*cur),pLog);
        destroy(cur);
    }
}