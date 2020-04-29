#include "Hstack.h"
#include <cstdio>

void InitNewStack(stack** pstack){ //Новый стек
    if (!pstack) s_destructor(pstack); //Если не пустой - очищаем
    (*pstack) = nullptr;
}

void InKeyboard(stack** pstack) { //Ввод по клавиатуре
    InitNewStack(pstack);
    int Data = 0,counter=0;
    printf("Стоп сигнал \'-1\'\n");
    while (Data!=-1)
    {
        scanf("%d",&Data); fflush(stdin);
        if (Data!=-1) {
            s_push(pstack, Data);
            counter++;
        }
    }
    if (counter==0) printf("Создан пустой стек\n");
    else printf("Создан стек с %d элементами\n",counter);
}

void InFile(stack** pstack, char* filename) { //ВВод из файла
    InitNewStack(pstack); //пересоздание стэка
    FILE *pFile = fopen(filename,"r"); //подключение файла
    int Data,counter=0;
    do {
        fscanf(pFile,"%d",&Data);
        if (!feof(pFile)) {
            s_push(pstack, Data);
            counter++;
        }
    }while(!feof(pFile));
    if (counter==0) printf("Создан пустой стек\n");
    else printf("Создан стек с %d элементами\n",counter);
}

void stackShow(stack** pstack) { //Вывод стека
    stack* temp = (*pstack); //Через доп. стек
    if (!temp) printf("Пустой стек");
    while (temp)
    {
        printf(" %d\n",temp->data);
        temp=temp->back;
    }
    printf("\n");
    free(temp);
}

stack* task(stack* pfstack, stack* psstack) { //Задача
    stack *res; InitNewStack(&res); //Стек - результат
    stack *temp; InitNewStack(&temp);
    temp = pfstack; //Временная ссылка на первый стек
    while (temp) //Пока не пустой
    {//Передаем результату данные первого, пока не дошли до конца
        s_push(&res,temp->data);
        temp=temp->back;
    }
    temp = psstack;//Временная ссылка на второй стек
    while (temp)
    {//Передаем результату данные второго, пока не дошли до конца
        s_push(&res,temp->data);
        temp=temp->back;
    }
    temp = pfstack;
    while (temp) //Временная ссылка на первый стек
    {//Передаем результату снова данные первого, пока не дошли до конца
        s_push(&res,temp->data);
        temp=temp->back;
    }
    free(temp);
    return res;
}

void End(stack** fStack, stack** sStack,stack** rStack) {
    s_destructor(fStack); s_destructor(sStack); s_destructor(rStack); //Освобождаем память
}