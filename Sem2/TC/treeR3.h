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

data nullData = {nullptr,nullptr,nullptr, {0,0,0}, {0,0,0},nullptr};

//"Указатель" на ветвь содержит текущую позицию и тип дерева, к которому принадлежит
typedef std::pair<int,char> NodePtr;

FILE *pTreeUnsorted;NodePtr head;
FILE *pTreeSorted;  NodePtr headKey;

void Init()
{
    pTreeUnsorted = fopen("C:\\Users\\Public\\Documents\\treeUnsorted.bin","wb+");
    pTreeSorted = fopen("C:\\Users\\Public\\Documents\\treeSorted.bin","wb+");
    head = std::make_pair(1,'u');
    headKey = std::make_pair(1,'s');
}

NodePtr curL(NodePtr cur){
    return std::make_pair(cur.first*2,cur.second);
}

NodePtr curR(NodePtr cur){
    return std::make_pair(cur.first*2+1,cur.second);
}
//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(NodePtr *CurrentPosition, char Pos='0')
{
    if (Pos=='L') return curL(*CurrentPosition);
    else if (Pos=='R') return curR(*CurrentPosition);
    else return (*CurrentPosition);
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
    return (getData(nd).FName==nullptr);
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
