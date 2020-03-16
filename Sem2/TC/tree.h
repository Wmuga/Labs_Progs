struct date
{
    int day;
    int month;
    int year;
};
struct data
{
    char* FName;
    char* SName;
    char* LName;
    date dBirth;
    date dDeath;
    char* BPlace;
};
struct Node
{
    data info;
    Node *nextL;
    Node *nextR;
    Node *prev;
};

Node *head,*current;

void Init()
{
    head=nullptr;
    current=nullptr;
}

void NewNode(Node *cur, Node *place= nullptr)
{
    Node *nd = new Node;
    nd->nextL = nullptr;
    nd->nextR = nullptr;
    if (cur==nullptr) {
        cur = nd;
        nd->prev  = nullptr;
    }
    else {
        nd->prev = cur;
        place = nd;
    }
}

bool IsEmpty(Node *nd)
{
    return nd== nullptr;

}

void bstart(Node *cur){
    cur = head;
}

void back(Node *cur) {
    cur = cur->prev;
}

void curL(Node *cur){
    cur = cur->nextL;
}

void curR(Node *cur){
    cur = cur->nextR;
}

data getData(){
    return current->info;
}

void replDataM(data inf){
    current->info=inf;
}

void replDataL(data inf){
    current->nextL->info=inf;
}

void replDataR(data inf){
    current->nextR->info=inf;
}