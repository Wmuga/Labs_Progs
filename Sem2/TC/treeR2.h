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

int elemsCountUnsorted;
int elemsCountSorted;

data nullData = {nullptr,nullptr,nullptr, {0,0,0}, {0,0,0},nullptr};

typedef std::pair<int,char> NodePtr;
 //В зависимости от второго символа опрделяем к какому дереву относится "указатель"
data* treeUnsorted; NodePtr head;
data* treeSorted;   NodePtr headKey;


//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(NodePtr *CurrentPosition, char Pos='0')
{
    (*CurrentPosition).second == 'u' ? treeUnsorted = (data*)realloc(treeUnsorted,elemsCountUnsorted*4*sizeof(data)):
    treeSorted = (data*)realloc(treeSorted,elemsCountSorted*4*sizeof(data));
    NodePtr newPos;
    newPos.second=(*CurrentPosition).second;
    if (Pos=='L') newPos.first = (*CurrentPosition).first*2;
    else if (Pos=='R') newPos.first = (*CurrentPosition).first*2+1;
    else newPos.first = (*CurrentPosition).first;
    (*CurrentPosition).second == 'u' ? treeUnsorted[newPos.first] = nullData
                                     : treeSorted[newPos.first] = nullData;
    return newPos;
}

bool IsEmpty(NodePtr nd)
{
    return nd.second=='u' ? treeUnsorted[nd.first].FName==nullptr
    : treeSorted[nd.first].FName==nullptr;
}
void destroy(NodePtr *cur, int type)
{
    if ((*cur).second=='u') {
        printf("%s\n",treeUnsorted[(*cur).first].FName);
        delete[](treeUnsorted[(*cur).first].FName);
        delete[](treeUnsorted[(*cur).first].SName);
        delete[](treeUnsorted[(*cur).first].LName);
        delete[](treeUnsorted[(*cur).first].BPlace);
        elemsCountUnsorted--;
    }
    NodePtr nextL = std::make_pair((*cur).first*2,(*cur).second);
    NodePtr nextR = std::make_pair((*cur).first*2+1,(*cur).second);

    if (!IsEmpty(nextL)) destroy(&nextL,0);
    if (!IsEmpty(nextR)) destroy(&nextR,0);
    if ((*cur)!=head and (*cur)!=headKey) (*cur) = std::make_pair((*cur).first/2,(*cur).second);
    else{
        (*cur).second == 'u' ? treeUnsorted=(data*)realloc(treeUnsorted,0) :
        treeSorted=(data*)realloc(treeSorted,0);
    }
}




void Init()
{
    treeUnsorted = (data*)malloc(2*sizeof(data));
    treeSorted = (data*)malloc(2*sizeof(data));
    head = std::make_pair(1,'u');
    headKey = std::make_pair(1,'s');
    elemsCountUnsorted=0;
    elemsCountSorted=1;
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

data getData(NodePtr cur){
    return cur.second == 'u' ? treeUnsorted[cur.first]: treeSorted[cur.first];
}

void replDataM(NodePtr *cur,data inf){
    (*cur).second == 'u' ? treeUnsorted[(*cur).first] = inf: treeSorted[(*cur).first] = inf;
}

void replDataL(NodePtr *cur,data inf){
    (*cur).second == 'u' ? treeUnsorted[(*cur).first*2] = inf
            : treeSorted[(*cur).first*2] = inf;
}

void replDataR(NodePtr *cur,data inf){
    (*cur).second == 'u' ? treeUnsorted[(*cur).first*2+1] = inf
            : treeSorted[(*cur).first*2+1] = inf;
}
