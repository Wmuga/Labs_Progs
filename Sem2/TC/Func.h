#include "Logger.h"

void ShowData(Node *cur,FILE *pfile=stdout)
{
    data info = getData(cur);
    fprintf(pfile, "%s %s %s Родился %d.%d.%d ", info.SName, info.FName, info.LName, info.dBirth.day, info.dBirth.month, info.dBirth.year);
    if (info.dDeath.day) fprintf(pfile, "Умер %d.%d.%d ", info.dDeath.day, info.dDeath.month, info.dDeath.year);
    if (strcmp(info.BPlace,"--")!=0) fprintf(pfile, "Родился в %s", info.BPlace);
    fprintf(pfile, "\n");
    fflush(pfile);
}


void ShowTree(Node *TreeHead,FILE *pfile=stdout, int depth=0){
    fprintf(pfile,"%*s",depth*2+3,"-- "); fflush(pfile);
    ShowData(TreeHead,pfile);
    if (!IsEmpty(curL(TreeHead)) and strcmp(getData(curL(TreeHead)).FName,"**")!=0) ShowTree(curL(TreeHead), pfile,depth+1);
    if (!IsEmpty(curR(TreeHead)) and strcmp(getData(curR(TreeHead)).FName,"**")!=0)ShowTree(curR(TreeHead), pfile,depth+1);
}


void ShowTree2(Node *TreeHead) {}

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
//Сделать через рекурсию
void TreeBranches(FILE *FileIn,Node** CurrentPosition)
{
    char *buffer = new char[50];
    fscanf(FileIn,"%s",buffer);
    data newinfo;
    if (!feof(FileIn)) {
        Node *next;
        if (buffer[0] != '*') {

            char *FName;
            char *SName = new char[20];
            char *LName = new char[20];
            char *BPlace = new char[50];

            FName = buffer;
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

            newinfo = {FName, SName, LName, dBirth, dDeath, BPlace};

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
    delete[]buffer;
}
void MakeTree(char* filename)
{
    backToStartUnsorted();
    PutInLog((char*)"Построение обыкновенного дерева\n");
    FILE* in = fopen(filename,"r");
    TreeBranches(in,&head);
    PutInLog((char *)"Конец файла\nСоздано дерево\n");
    ShowTree(head, pLog);
}

void remove(Node **cur)
{
    if ((*cur)==head) PutInLog((char*)"Уничтожено обыкновенное дерево\n");
    else if ((*cur)==headKey) PutInLog((char*)"Уничтожено отсортированное дерево\n");
    else{
        PutInLog((char*)"Уничтожена ветвь "); ShowData(*cur,pLog);
    }
    destroy(cur);
}