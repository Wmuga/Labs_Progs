#include "add_Structs.h"


struct Node         //Структура одной ветыи
{
    data info;      //Данные
    Node *nextL;    //Указатель на левый элемент
    Node *nextR;    //Указатель на правый элемент
    Node *prev;     //Указатель на предыдущий элемент
};

//Указатель на ветвь называем NodePtr
typedef Node* NodePtr;
//Ссылки на деревья
NodePtr head=nullptr; //Неупорядоченное
NodePtr headKey=nullptr; //Упорядоченное

//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(Node **CurrentPosition, char Pos='0')
{
    Node *newNode = new Node;

    newNode->nextL=nullptr;
    newNode->nextR=nullptr;
    //Создание пустых связей
    //Проверка на наличие "предшественника"
    newNode->prev = (CurrentPosition == nullptr ? nullptr : (*CurrentPosition));
    //Добавление связи в зависимости от того, куда неообходимо добавить новую ветвь
    if (Pos=='L') (*CurrentPosition)->nextL=newNode;
    if (Pos=='R') (*CurrentPosition)->nextR=newNode;
    //Записываем пустые данные
    newNode->info=nullData;
    return newNode;
}

//Уничтожение ветви или целого дерева
void destroy(NodePtr *cur)
{
    if (!(*cur)->info.FName) { //Проверка, удалили ли данные раньше
        /*
         * Нужно в основном для отсортированного дерева
         * т.к. есть элемнты добавленные вручную, а остальные
         * удалены ранее в генеологическом дереве
         */
        delete[]((*cur)->info.FName);
        delete[]((*cur)->info.SName);
        delete[]((*cur)->info.LName);
        delete[]((*cur)->info.BPlace);
        (*cur)->info.FName=nullptr; //для возможности определить был ли удален элемент ранее
    }
    //Если есть что-то слева или справа - уничтожаем
    if ((*cur)->nextL!= nullptr)
        destroy(&((*cur)->nextL));
    if ((*cur)->nextR!= nullptr)
        destroy(&((*cur)->nextR));
    //Если не голова - удаляем текущий элемент и соответствующую связь
    if (*cur!=head and *cur!=headKey){
        Node *temp = (*cur)->prev;
        if (temp->nextL==(*cur)) temp->nextL=nullptr;
        if (temp->nextR==(*cur)) temp->nextR=nullptr;
        delete [](*cur);
        (*cur) = temp;
    }
    else {
        //Очищаем голову и отдаем nullptr
        delete [](*cur);
        (*cur) = nullptr;
    }
}

//Инициализатор
void Init()
{
    //Создаем на корне пустые элементы и присваиваем неотсортированному стоп-знак
    head = NewNode(nullptr);
    headKey = NewNode(nullptr);
    head->info={(char*)"**"};
}

//Проверка на пустоту
bool IsEmpty(NodePtr nd)
{
    return (nd->info.FName==nullptr) or (nd==nullptr);
}

//Указатель на корень Геологического дерева
NodePtr getStartUnsorted(){
    return head;
}

//Указатель на корень отсортированного дерева
NodePtr getStartSorted(){
    return headKey;
}

//Возврат назад
NodePtr back(NodePtr *cur) {
    return (*cur)->prev;
}

//Переход влево
NodePtr curL(NodePtr cur){
    return cur->nextL;
}

//Переход вправо
NodePtr curR(NodePtr cur){
    return cur->nextR;
}

//Получение данных
data getData(NodePtr cur){
    return cur->info;
}
//Замена данных:
//          в текущей ветви
void replDataM(NodePtr *cur,data inf){
    (*cur)->info=inf;
}
//          слева
void replDataL(NodePtr *cur,data inf){
    (*cur)->nextL = NewNode(cur); //Создание элемента слева
    (*cur)->nextL->info=inf;
}
//          справа
void replDataR(NodePtr *cur,data inf){
    (*cur)->nextR = NewNode(cur); //Создание элемента справа
    (*cur)->nextR->info=inf;
}
