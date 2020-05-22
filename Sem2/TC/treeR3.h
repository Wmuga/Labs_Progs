#include <utility>
struct date       //Дата
{
    int day;
    int month;
    int year;
};
struct data       //Данные
{
    char*  FName; //Имя
    char*  SName; //Фамилия
    char*  LName; //Отчество
    date  dBirth; //Дата рождения
    date  dDeath; //Смерти (опционально)
    char* BPlace; //Место рождения(опционально)
};

int elemsCountUnsorted=0;
int elemsCountSorted=0;

data nullData = {nullptr,nullptr,nullptr, {0,0,0}, {0,0,0},nullptr};

//"Указатель" на ветвь содержит текущую позицию и тип дерева, к которому принадлежит
typedef std::pair<int,char> NodePtr;

FILE *pTreeUnsorted;NodePtr head;
FILE *pTreeSorted;  NodePtr headKey;

void Init()
{
    pTreeUnsorted = fopen("C:\\Users\\Public\\Documents\\treeUnsorted.bin","wb+");
    pTreeSorted = fopen("C:\\Users\\Public\\Documents\\treeSorted.bin","wb+");
    fseek(pTreeUnsorted, sizeof(data), SEEK_SET);
    fseek(pTreeSorted, sizeof(data), SEEK_SET);
    head = std::make_pair(1,'u');
    headKey = std::make_pair(1,'s');
}

//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(NodePtr *CurrentPosition, char Pos='0')
{
    NodePtr newPos;
    if (Pos=='L') newPos.first = (*CurrentPosition).first*2;
    else if (Pos=='R') newPos.first = (*CurrentPosition).first*2+1;
    else newPos.first = (*CurrentPosition).first;
    return newPos;
}

data getData(NodePtr cur){
    data currentData;
    if (cur.second=='u') {
        fseek(pTreeUnsorted, cur.first * sizeof(data), SEEK_SET);
        fread(&currentData, sizeof(data), 1, pTreeUnsorted);
    } else{
        fseek(pTreeSorted, cur.first * sizeof(data), SEEK_SET);
        fread(&currentData, sizeof(data), 1, pTreeSorted);
    }
    return currentData;
}

bool IsEmpty(NodePtr nd)
{
    if (!(getData(nd).FName))printf("Khu\n");
    else printf("%d\n",nd.first);
    return (getData(nd).FName==nullptr) or nd.second=='u' ? feof(pTreeUnsorted): feof(pTreeSorted);
}

void destroy(NodePtr *cur, int type)
{
    if (*cur==head) {
        fclose(pTreeUnsorted);
        remove("treeUnsorted.bin");
    }
    else if (*cur==headKey) {
        fclose(pTreeSorted);
        remove("treeSorted.bin");
    }
    else
    {
        if ((*cur).second=='u') {
            fseek(pTreeUnsorted, (*cur).first * sizeof(data), SEEK_SET);
            fread(&nullData, sizeof(data), 1, pTreeUnsorted);
        } else{
            fseek(pTreeSorted, (*cur).first * sizeof(data), SEEK_SET);
            fread(&nullData, sizeof(data), 1, pTreeSorted);
        }
        NodePtr nextL = std::make_pair((*cur).first*2,(*cur).second);
        NodePtr nextR = std::make_pair((*cur).first*2+1,(*cur).second);
        if (!IsEmpty(nextL)) destroy(&nextL,type);
        if (!IsEmpty(nextR)) destroy(&nextR,type);
    }
}


NodePtr getStartUnsorted(){
    return head;
}

NodePtr getStartSorted(){
    return headKey;
}


NodePtr back(NodePtr *cur) {
    return std::make_pair((*cur).first/2,(*cur).second);
}

NodePtr curL(NodePtr cur){
    return std::make_pair(cur.first*2,cur.second);
}

NodePtr curR(NodePtr cur){
    return std::make_pair(cur.first*2+1,cur.second);
}


void replDataM(NodePtr *cur,data inf){
    if ((*cur).second=='u') {
        fseek(pTreeUnsorted, (*cur).first * sizeof(data), SEEK_SET);
        fwrite(&inf,sizeof(data),1,pTreeUnsorted);
    } else{
        fseek(pTreeSorted, (*cur).first * sizeof(data), SEEK_SET);
        fwrite(&inf,sizeof(data),1,pTreeSorted);
    }

}

void replDataL(NodePtr *cur,data inf){
    if ((*cur).second=='u') {
        fseek(pTreeUnsorted, (*cur).first* 2 * sizeof(data), SEEK_SET);
        fwrite(&inf,sizeof(data),1,pTreeUnsorted);
    } else{
        fseek(pTreeSorted, (*cur).first*2 * sizeof(data), SEEK_SET);
        fwrite(&inf,sizeof(data),1,pTreeSorted);
    }
}

void replDataR(NodePtr *cur,data inf){
    if ((*cur).second=='u') {
        fseek(pTreeUnsorted,((*cur).first*2+1) * sizeof(data), SEEK_SET);
        fwrite(&inf,sizeof(data),1,pTreeUnsorted);
    } else{
        fseek(pTreeSorted, ((*cur).first*2+1) * sizeof(data), SEEK_SET);
        fwrite(&inf,sizeof(data),1,pTreeSorted);
    }
}
