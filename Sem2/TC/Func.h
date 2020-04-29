
void remove(Node **cur,FILE *pLog)
{
    if ((*cur)==head) fprintf(pLog,"Destroyed unsorted tree\n");
    else if ((*cur)==headKey) fprintf(pLog,"Destroyed sorted tree\n");
    else{
        data curData = getData(*cur);
        fprintf(pLog,"Destroyed branch -%s-%s-%s-\n",curData.FName,curData.SName,curData.LName);
    }
    destroy(cur);
}

void ShowTree(Node *TreeHead, int depth=1,FILE *pLog = stdin){
    data info = getData(TreeHead);
    for (int i=0;i<depth;i++) printf("-");
    fprintf(pLog,"%s %s %s Родился %d.%d.%d ",info.SName,info.FName,info.LName,info.dBirth.day,info.dBirth.month,info.dBirth.year);
    if (info.dDeath.day) fprintf(pLog,"Умер %d.%d.%d ",info.dDeath.day,info.dDeath.month,info.dDeath.year);
    if (!strtol(info.BPlace, nullptr,10)) fprintf(pLog,"Родился в %s",info.BPlace);
    fprintf(pLog,"\n");
    if (strcmp(getData(TreeHead->nextL).FName,"**")!=0) ShowTree(TreeHead->nextL,depth+1,pLog);
    else if (strcmp(getData(TreeHead->nextR).FName,"**")!=0) ShowTree(TreeHead->nextR,depth+1,pLog);
}

/*
void MakeTreeKey()
{

}
*/

/*
void AddToKeyTree()
{

}
*/

/*
void Task()
{

}
*/
void MakeTree(FILE* pLog, char* filename) {
    bstart();
    fprintf(pLog,"Making new tree w/o key\n");
    fflush(pLog);
    FILE *pFile = fopen(filename, "r");
    char *buffer = new char[50];
    char* FName = new char[20]; char* SName=new char[20]; char* LName=new char[20]; char* BPlace=new char[50];
    while (!feof(pFile)) {
        fscanf(pFile, "%s", buffer);
        while (buffer[0] != '*' and !feof(pFile)) {
            FName = buffer;
            fscanf(pFile, "%s", SName);
            fscanf(pFile, "%s", LName);

            int day,month,year;

            fscanf(pFile, "%d", &day);
            fscanf(pFile, "%d", &month);
            fscanf(pFile, "%d", &year);

            date dBirth={day,month,year};

            fscanf(pFile, "%d", &day);
            fscanf(pFile, "%d", &month);
            fscanf(pFile, "%d", &year);

            date dDeath={day,month,year};

            fscanf(pFile, "%s", BPlace);

            data newinfo={FName,SName,LName,dBirth,dDeath,BPlace};
            current->info = newinfo;
            fprintf(pLog,"Added -----%s %s %s\n",newinfo.FName,newinfo.SName,newinfo.LName);
            fflush(pLog);

            NewNode(&current, &(current->nextL));
            curL(&current);
            fscanf(pFile, "%s", buffer);
        }
        fprintf(pLog,"Went to another branch");
        current->info.FName = (char *)"**";
        back(&current);
            while (!IsEmpty(current->nextR) and !(IsEmpty(current->nextL))) {
                back(&current);
            }
        if (IsEmpty(current->nextR)) {
            NewNode(&current, &(current->nextR));
            curR(&current);
            fscanf(pFile, "%s", buffer);
        } else {
            NewNode(&current, &(current->nextL));
            curL(&current);
            fscanf(pFile, "%s", buffer);
        }
    }
    delete []FName; delete []SName; delete []LName; delete []BPlace; delete []buffer; //Освобождение памяти
    fprintf(pLog,"Constructed Tree\n"); ShowTree(head,1,pLog);
    fclose(pFile);
}
