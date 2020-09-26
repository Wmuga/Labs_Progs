//
// Created by Alex on 18.09.2020.
//

#ifndef LAB4_STACK_HPP
#define LAB4_STACK_HPP

template<class T>
struct tStackPart{

    T data;
    tStackPart* back;

    tStackPart(){
        data = T();
        back = nullptr;
    }
    tStackPart(const T& _data){
        data = _data;
        back = nullptr;
    }
};

template<class T>
class stack {
    tStackPart<T>* last;
public:
    stack();
};


#endif //LAB4_STACK_HPP

/*
#include <cstdlib>

typedef int TInfo; //удобство для написания абстрактных функций
struct stack{      //Элемент стэка
    TInfo data;    //содержание
    stack* back;   //указатель на предыдущий
};
void s_push(stack** pstack, TInfo Data) //Добавление элемента в стек
{
    if ((*pstack) == nullptr) { //Если стек пустой
        stack* newElem = new stack; //Новый адресс памяти
        newElem->data = Data; //Передаем значение
        newElem->back = nullptr; //Предыдущего нет
        (*pstack) = newElem; //Присваеваем новой адресс памяти текущему
    } else{
        stack* newElem = new stack; //Новый адресс памяти
        newElem->data = Data;
        newElem->back = (*pstack); //Текущий становиться предыдущим
        (*pstack) = newElem; //Присваеваем новой адресс памяти текущему
    }
}


void destr_last(stack** pstack) //Удаление нынешнего элемента
{
    stack* temp = (*pstack)->back; //Уходим назад
    free(pstack); //Удаляем нынешний элемент
    (*pstack) =temp; //Присвпиваем предыдущий
}

TInfo s_pop(stack** pstack) //"Вытаскивание" элемента
// (в текущем не используется т.к. нет необходимости в "вытаскивании элемента", а только получение значений стека)
{
    if ((*pstack)==nullptr) throw 1; //Код ошибки на случай пустого
    else {
        TInfo value = (*pstack)->data; //Получаем значение
        destr_last(pstack); //Удаляем нынешний
        return value; //Возврашаем значение
    }
}


void s_destructor(stack** pstack) //Полное уничтожение стека
{
    while ((*pstack))
    {
        destr_last(pstack);
    }
}
 */