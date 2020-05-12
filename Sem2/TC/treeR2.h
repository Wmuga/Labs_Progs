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

typedef std::pair<int,char> NodePtr;
 //В зависимости от второго символа опрделяем к какому дереву относится "указатель"
data* treeUnsorted; NodePtr head;
data* treeSorted;   NodePtr headKey;


//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(NodePtr *CurrentPosition, char Pos='0')
{
    date nullDate = {0,0,0};
    data nullData = {nullptr,nullptr,nullptr,nullDate,nullDate,nullptr};
    NodePtr newPos; newPos.second=(*CurrentPosition).second;
    if (Pos=='L') newPos.first = (*CurrentPosition).first*2;
    else if (Pos=='R') newPos.first = (*CurrentPosition).first*2+1;
    else newPos.first = (*CurrentPosition).first;
    (*CurrentPosition).second == 'u' ? treeUnsorted[newPos.first] = nullData
                                     : treeSorted[newPos.first] = nullData;
    return newPos;
}

bool IsEmpty(NodePtr nd)
{
    return nd.second=='u' ? treeUnsorted[nd.first].FName==nullptr : treeSorted[nd.first].FName==nullptr;
}
void destroy(NodePtr *cur)
{
    if ((*cur).first=='u') {
        delete[](treeUnsorted[(*cur).first].FName);
        delete[](treeUnsorted[(*cur).first].SName);
        delete[](treeUnsorted[(*cur).first].LName);
        delete[](treeUnsorted[(*cur).first].BPlace);
    }
    else{
        delete[](treeSorted[(*cur).first].FName);
        delete[](treeSorted[(*cur).first].SName);
        delete[](treeSorted[(*cur).first].LName);
        delete[](treeSorted[(*cur).first].BPlace);
    }
    NodePtr nextL = std::make_pair((*cur).first*2,(*cur).second);
    NodePtr nextR = std::make_pair((*cur).first*2+1,(*cur).second);
    if (!IsEmpty(nextL)) destroy(&nextL);
    if (!IsEmpty(nextL)) destroy(&nextR);
    if ((*cur)!=head) (*cur) = std::make_pair((*cur).first/2,(*cur).second);
}




void Init()
{
    treeUnsorted = new data[100]();
    treeSorted = new data[100]();
    head = std::make_pair(1,'u');
    headKey = std::make_pair(1,'s');
}

void backToStartUnsorted(){
//    head = std::make_pair(1,'u');
}

void backToStartSorted(){
//    headKey = std::make_pair(1,'s');
}


void back(NodePtr *cur) {
    (*cur) = std::make_pair((*cur).first/2,(*cur).second);
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