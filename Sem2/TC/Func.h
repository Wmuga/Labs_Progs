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
    if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0)ShowTree(curR(TreeHead), pfile,depth+1);
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

/*Получение полных данных, так как для проверки приходится читать первое слово заранее, отправляем и его.
 * Чтобы не писать дважды, вынесено в отдельную функцию
*/
data getFullData(FILE *FileIn,char* buffer)
{
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

    return {FName, SName, LName, dBirth, dDeath, BPlace};
}

/*
void AddToKeyTree()
{

}
*/

/*
void MakeTreeKey()
{

}
*/


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

            newinfo = getFullData(FileIn,buffer);

            next = NewNode(CurrentPosition,'L');
            replDataM(CurrentPosition,newinfo);
        }
        else
        {
            newinfo = {(char*)"**"};
            replDataM(CurrentPosition,newinfo);
            do
            {
                back(CurrentPosition);
            }while(!IsEmpty(curR(*CurrentPosition)));
            next = NewNode(CurrentPosition,'R');
        }

        if (strcmp(newinfo.FName,"**")!=0) {PutInLog((char*)"Создана ветвь "); ShowData(*CurrentPosition,pLog);}
        else PutInLog((char*)"Переход на друю подветвь\n");
        TreeBranches(FileIn, &next);
    }
    else{ //Так как последний ** считывается, но не обрабатывается - делаем сами
        newinfo = {(char*)"**"};
        replDataM(CurrentPosition,newinfo);
    }
}
//Инициализатор создания дерева
void MakeTree(char* filename)
{
    PutInLog((char*)"Построение обыкновенного дерева\n");
    FILE* in = fopen(filename,"r");
    TreeBranches(in,&head);
    PutInLog((char *)"Конец файла\nСоздано дерево:\n");
    ShowTree(head, pLog);
}

void remove(NodePtr *cur)
{
    if ((*cur)==head) PutInLog((char*)"Уничтожено обыкновенное дерево\n");
    else if ((*cur)==headKey) PutInLog((char*)"Уничтожено отсортированное дерево\n");
    else{
        PutInLog((char*)"Уничтожена ветвь "); ShowData(*cur,pLog);
    }
    destroy(cur);
}