#include <cstdlib>

typedef int TInfo; //удобство для написания абстрактных функций при конкретной задаче заменено
struct stack{      //Элемент стэка
    TInfo data;    //содержание
    stack* back;   //указатель на предыдущий
};
void s_push(stack** pstack, TInfo Data)
{
    if ((*pstack) == nullptr) {
        stack* newElem = new stack;
        newElem->data = Data;
        newElem->back = nullptr;
        (*pstack) = newElem;
    } else{
        stack* newElem = new stack;
        newElem->data = Data;
        newElem->back = (*pstack);
        (*pstack) = newElem;
    }
}


void destr_last(stack** pstack)
{
    stack* temp = (*pstack)->back;
    free(pstack);
    (*pstack) =temp;
}

TInfo s_pop(stack** pstack)
{
    if ((*pstack)==nullptr) throw 1;
    else {
        TInfo value = (*pstack)->data;
        destr_last(pstack);
        return value;
    }
}


void s_destructor(stack** pstack)
{
    while ((*pstack))
    {
        destr_last(pstack);
    }
}