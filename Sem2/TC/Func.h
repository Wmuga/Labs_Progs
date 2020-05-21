#include "Logger.h"

/* Функция вывода полной информации.
 * Может выводить в консоль по умолчанию или в в другой поток
 * В частности - файл лога
 * Чтобы не писать нескольно раз, вынесено в отдельную функцию
*/
void ShowData(NodePtr cur,FILE *pfile=stdout)
{
    data info = getData(cur);
    fprintf(pfile, "%s %s %s Родился %d.%d.%d ", info.SName, info.FName, info.LName, info.dBirth.day, info.dBirth.month, info.dBirth.year);
    if (info.dDeath.day) fprintf(pfile, "Умер %d.%d.%d ", info.dDeath.day, info.dDeath.month, info.dDeath.year);
    if (strcmp(info.BPlace,"--")!=0) fprintf(pfile, "Родился в %s", info.BPlace);
    fprintf(pfile, "\n");
    fflush(pfile);
}

/* Первый способ выведения дерева Корень-лево-право
 * Может выводить по умолчанию в консоль, или в другой поток
 * В частности - лог
 */
void ShowTree(NodePtr TreeHead,FILE *pfile=stdout, int depth=0){
    fprintf(pfile,"%*s",depth*2+3,"-- "); fflush(pfile);
    ShowData(TreeHead,pfile);
    if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName,"**")!=0) ShowTree(curL(TreeHead), pfile,depth+1);
    if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0) ShowTree(curR(TreeHead), pfile,depth+1);
}

/* Второй способ выведения дерева лево-корень-право
 * Может выводить по умолчанию в консоль, или в другой поток
 * В частности - лог
 */
void ShowTree2(NodePtr TreeHead,FILE *pfile=stdout, int depth=0) {
    if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName,"**")!=0) ShowTree2(curL(TreeHead), pfile,depth+1);
    fprintf(pfile,"%*s",depth*2+3,"-- "); fflush(pfile);
    ShowData(TreeHead,pfile);
    if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0)ShowTree2(curR(TreeHead), pfile,depth+1);
}



void TreeSortedBranches(NodePtr CurrentPositionOfUnsorted)
{
    data currentData = getData(CurrentPositionOfUnsorted);
    if (currentData.dDeath.day) {
        elemsCountSorted++;
        PutInLog((char*)"Найдена информация о дате смерти в элементе:\n");
        ShowData(CurrentPositionOfUnsorted,pLog);
        NodePtr CurrentPosition=headKey;
        while (getData(CurrentPosition).dDeath.day and CurrentPositionOfUnsorted!=head)
        {
            data prevData = getData(CurrentPosition);
            if ((prevData.dDeath.day-currentData.dDeath.day)+
            (prevData.dDeath.month-currentData.dDeath.month)*31>0)
            CurrentPosition=curL(CurrentPosition);
            else CurrentPosition=curR(CurrentPosition);
        }
        replDataM(&CurrentPosition,currentData);
        data StopCode = {(char*)"**"};
        NewNode(&CurrentPosition,'R');
        replDataR(&CurrentPosition,StopCode);
        NewNode(&CurrentPosition,'L');
        replDataL(&CurrentPosition,StopCode);
    }
    if (!IsEmpty(curL(CurrentPositionOfUnsorted)) and strcmp(getData(curL(CurrentPositionOfUnsorted)).FName,"**")!=0)
        TreeSortedBranches(curL(CurrentPositionOfUnsorted));
    if (!IsEmpty(curR(CurrentPositionOfUnsorted)) and strcmp(getData(curR(CurrentPositionOfUnsorted)).FName,"**")!=0)
        TreeSortedBranches(curR(CurrentPositionOfUnsorted));
}



void MakeTreeKey()
{
    PutInLog((char*)"Построение отсортированного дерева\n");
    TreeSortedBranches(getStartUnsorted());
    PutInLog((char*)"Создано дерево:\n");
    ShowTree(getStartSorted(), pLog);
}



/*
void Task()
{

}
*/
//Формирование ветвей. При желании можно сделать не рекурсию, а while
void TreeBranches(FILE *FileIn,NodePtr* CurrentPosition)
{
    char *buffer = new char[50];
    fscanf(FileIn,"%s",buffer);
    data newinfo;
    if (!feof(FileIn)) {
        NodePtr next;
        if (buffer[0] != '*') {
            elemsCountUnsorted++;
            char *FName= buffer;
            char *SName = new char[20];
            char *LName = new char[20];
            char *BPlace = new char[50];

            fscanf(FileIn, "%s", SName);
            fscanf(FileIn, "%s", LName);

            int day, month, year;
            fscanf(FileIn, "%d", &day);
            fscanf(FileIn, "%d", &month);
            fscanf(FileIn, "%d", &year);
            date dBirth = {day, month, year};

            fscanf(FileIn, "%d", &day);
            fscanf(FileIn, "%d", &month);
            fscanf(FileIn, "%d", &year);
            date dDeath = {day, month, year};

            fscanf(FileIn, "%s", BPlace);

            newinfo = {FName,SName,LName,dBirth,dDeath,BPlace};

            next = NewNode(CurrentPosition,'L');
            replDataM(CurrentPosition,newinfo);
            PutInLog((char*)"Создана ветвь "); ShowData(*CurrentPosition,pLog);
        }
        else
        {
            newinfo = {(char*)"**"};
            replDataM(CurrentPosition,newinfo);
            do
            {
                *CurrentPosition = back(CurrentPosition);
            }while(!IsEmpty(curR(*CurrentPosition)));
            next = NewNode(CurrentPosition,'R');
            PutInLog((char*)"Переход на друю подветвь\n");
        }
        TreeBranches(FileIn, &next);
    }
    else{ //Так как последний ** считывается, но не обрабатывается - делаем сами
        newinfo = {(char*)"**"};
        replDataM(CurrentPosition,newinfo);
    }
}
//Инициализатор создания неупорядоченного дерева
void MakeTree(char* filename)
{
    PutInLog((char*)"Построение обыкновенного дерева\n");
    FILE* in = fopen(filename,"r");
    TreeBranches(in,&head);
    PutInLog((char *)"Конец файла\nСоздано дерево:\n");
    ShowTree(getStartUnsorted(), pLog);
    fclose(in);
}

void remove(NodePtr *cur)
{
    if ((*cur)==getStartUnsorted()) {
        PutInLog((char*)"Уничтожено обыкновенное дерево\n");
        destroy(cur,0);
    }
    else if ((*cur)==getStartSorted()) {
        PutInLog((char*)"Уничтожено отсортированное дерево\n");
        destroy(cur,1);
    }
    else{
        PutInLog((char*)"Уничтожена ветвь "); ShowData(*cur,pLog);
        destroy(cur,0);
    }
}