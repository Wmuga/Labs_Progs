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
Node *head=nullptr,*current=nullptr; //Неупорядоченное
Node *headKey=nullptr, *currentKey= nullptr; //Упорядоченное


void NewNode(Node **cur, Node **place= nullptr)
{
    Node *newNode = new Node;

    newNode->nextL=nullptr;
    newNode->nextR= nullptr;

    if (place==nullptr)
    {
        newNode->prev= nullptr;
        (*cur)=newNode;
    } else{
        newNode->prev = (*cur);
        (*place)=newNode;
    }
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

Node* Init()
{
    if (head!=nullptr) destroy(&head);
    NewNode(&head);
    if (headKey!=nullptr) destroy(&headKey);
    NewNode(&headKey);
}

bool IsEmpty(Node *nd)
{
    return (nd==nullptr);
}

void bstart(){
    current = head;
}

void back(Node **cur) {
    (*cur) = (*cur)->prev;
}

void curL(Node **cur){
    (*cur) = (*cur)->nextL;
}

void curR(Node **cur){
    (*cur) = (*cur)->nextR;
}

data getData(Node *cur){
    return cur->info;
}

void replDataM(Node **cur,data inf){
    (*cur)->info=inf;
}

void replDataL(Node **cur,data inf){
    (*cur)->nextL->info=inf;
}

void replDataR(Node **cur,data inf){
    (*cur)->nextR->info=inf;
}