
void remove(Node *cur)
{
    if (cur!= nullptr) {
        Node *ndL = new Node;
        Node *ndR = new Node;
        ndL = cur->nextL;
        ndR = cur->nextR;
        delete []cur;
        remove(ndL);
        remove(ndR);
    }
}
/*
void MakeTreeKey()
{

}
*/

void MakeTree(FILE* pLog) {
    NewNode(head);
    bstart(current);
    fprintf(pLog,"Making new tree w/o key\n");
    fflush(pLog);
    FILE *pFile = fopen("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\TC\\in.txt", "r");
    char *buffer = new char[50];
    while (!feof(pFile)) {
        fscanf(pFile, "%s", buffer);
        while (buffer[0] != '*') {
            data newinfo{};
            newinfo.FName = buffer;
            fscanf(pFile, "%s", newinfo.SName);
            fscanf(pFile, "%s", newinfo.LName);

            fscanf(pFile, "%d", &newinfo.dBirth.day);
            fscanf(pFile, "%d", &newinfo.dBirth.month);
            fscanf(pFile, "%d", &newinfo.dBirth.year);

            fscanf(pFile, "%d", &newinfo.dDeath.year);
            fscanf(pFile, "%d", &newinfo.dDeath.year);
            fscanf(pFile, "%d", &newinfo.dDeath.year);
            fscanf(pFile, "%s", newinfo.BPlace);
            fprintf(pLog,"-----%s %s %s",newinfo.FName,newinfo.SName,newinfo.LName);
            fflush(pLog);

            current->info = newinfo;

            NewNode(current, current->nextL);
            curL(current);
            fscanf(pFile, "%s", buffer);
        }
        current->info.FName = (char *) "**";
        back(current);
            while (!IsEmpty(current->nextR) || !(IsEmpty(current->nextL))) {
                back(current);
            }
        if (IsEmpty(current->nextR)) {
            NewNode(current, current->nextR);
            curR(current);
            fscanf(pFile, "%s", &buffer);
        } else {
            NewNode(current, current->nextL);
            curL(current);
        }
    }
}