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
struct Node
{
    data info;
    Node *nextL;
    Node *nextR;
    Node *prev;
};


typedef Node* NodePtr;
data nullData = {nullptr,nullptr,nullptr, {0,0,0}, {0,0,0},nullptr};
//Ссылки на деревья
NodePtr head=nullptr; //Неупорядоченное
NodePtr headKey=nullptr; //Упорядоченное

//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(Node **CurrentPosition, char Pos='0')
{
    Node *newNode = new Node;

    newNode->nextL=nullptr;
    newNode->nextR=nullptr;
    newNode->prev = (CurrentPosition == nullptr ? nullptr : (*CurrentPosition));

    if (Pos=='L') (*CurrentPosition)->nextL=newNode;
    if (Pos=='R') (*CurrentPosition)->nextR=newNode;

    newNode->info=nullData;
    return newNode;
}

void destroy(NodePtr *cur, int type)
{
    if (!type) {
        delete[]((*cur)->info.FName);
        delete[]((*cur)->info.SName);
        delete[]((*cur)->info.LName);
        delete[]((*cur)->info.BPlace);
    }
    if ((*cur)->nextL!= nullptr)
        destroy(&((*cur)->nextL),type);
    if ((*cur)->nextR!= nullptr)
        destroy(&((*cur)->nextR),type);

    if (*cur!=head and *cur!=headKey){
        Node *temp = (*cur)->prev;
        if (temp->nextL==(*cur)) temp->nextL=nullptr;
        if (temp->nextR==(*cur)) temp->nextR=nullptr;
        delete [](*cur);
        (*cur) = temp;
    }
    else {
        delete [](*cur);
        (*cur) = nullptr;
    }
}

void Init()
{
    if (head!=nullptr) destroy(&head,0);
    head = NewNode(nullptr);
    if (headKey!=nullptr) destroy(&headKey,1);
    headKey = NewNode(nullptr);
}

bool IsEmpty(NodePtr nd)
{
    return (nd->info.FName==nullptr) or (nd==nullptr);
}

NodePtr getStartUnsorted(){
    return head;
}

NodePtr getStartSorted(){
    return headKey;
}


NodePtr back(NodePtr *cur) {
    return (*cur)->prev;
}

NodePtr curL(NodePtr cur){
    return cur->nextL;
}

NodePtr curR(NodePtr cur){
    return cur->nextR;
}

data getData(NodePtr cur){
    return cur->info;
}

void replDataM(NodePtr *cur,data inf){
    (*cur)->info=inf;
}

void replDataL(NodePtr *cur,data inf){
    (*cur)->nextL = NewNode(cur);
    (*cur)->nextL->info=inf;
}

void replDataR(NodePtr *cur,data inf){
    (*cur)->nextR = NewNode(cur);
    (*cur)->nextR->info=inf;
}
