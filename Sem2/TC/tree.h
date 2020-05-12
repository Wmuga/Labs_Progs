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

//Ссылки на деревья
NodePtr head=nullptr,    current=nullptr; //Неупорядоченное
NodePtr headKey=nullptr, currentKey= nullptr; //Упорядоченное

//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(Node **CurrentPosition, char Pos='0')
{
    Node *newNode = new Node;

    newNode->nextL=nullptr;
    newNode->nextR=nullptr;
    newNode->prev = (CurrentPosition == nullptr ? nullptr : (*CurrentPosition));

    if (Pos=='L') (*CurrentPosition)->nextL=newNode;
    if (Pos=='R') (*CurrentPosition)->nextR=newNode;

    return newNode;
}

void destroy(NodePtr *cur)
{
    delete []((*cur)->info.FName);
    delete []((*cur)->info.SName);
    delete []((*cur)->info.LName);
    delete []((*cur)->info.BPlace);
    if ((*cur)->nextL!= nullptr)
        destroy(&((*cur)->nextL));
    if ((*cur)->nextR!= nullptr)
        destroy(&((*cur)->nextR));

    if (*cur!=head){
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
    if (head!=nullptr) destroy(&head);
    head = NewNode(nullptr);
    if (headKey!=nullptr) destroy(&headKey);
    headKey = NewNode(nullptr);
}

bool IsEmpty(Node *nd)
{
    return (nd==nullptr);
}

void backToStartUnsorted(){
    current = head;
}

void backToStartSorted(){
    currentKey = headKey;
}


void back(NodePtr *cur) {
    (*cur)=(*cur)->prev;
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
