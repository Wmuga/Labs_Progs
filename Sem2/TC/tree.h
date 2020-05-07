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

//Ссылки на деревья
Node *head=nullptr,    *current=nullptr; //Неупорядоченное
Node *headKey=nullptr, *currentKey= nullptr; //Упорядоченное


Node* NewNode(Node **CurrentPosition, char Pos='0')
{
    Node *newNode = new Node;

    newNode->nextL=nullptr;
    newNode->nextR=nullptr;
    newNode->prev = (CurrentPosition == nullptr ? nullptr : (*CurrentPosition));

    if (Pos=='L') (*CurrentPosition)->nextL=newNode;
    if (Pos=='R') (*CurrentPosition)->nextR=newNode;

    return newNode;
}

void destroy(Node **cur)
{
    if ((*cur)->nextL!= nullptr)
    {
        destroy(&((*cur)->nextL));
    }
    else if ((*cur)->nextR!= nullptr)
    {
        destroy(&((*cur)->nextR));
    }
    else if (*cur!=head){
        Node *temp = (*cur)->prev;
        if (temp->nextL==(*cur)) temp->nextL=nullptr;
        if (temp->nextR==(*cur)) temp->nextR=nullptr;
        free(*cur);
        (*cur) = temp;
    }
    else {
        free(*cur);
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


void back(Node **cur) {
    (*cur)=(*cur)->prev;
}

Node* curL(Node *cur){
    return cur->nextL;
}

Node* curR(Node *cur){
    return cur->nextR;
}

data getData(Node *cur){
    return cur->info;
}

void replDataM(Node **cur,data inf){
    (*cur)->info=inf;
}

void replDataL(Node **cur,data inf){
    (*cur)->nextL = NewNode(cur);
    (*cur)->nextL->info=inf;
}

void replDataR(Node **cur,data inf){
    (*cur)->nextR = NewNode(cur);
    (*cur)->nextR->info=inf;
}
