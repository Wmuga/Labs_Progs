#include "Hstack.h"
#include <cstdio>

void InitNewStack(stack** pstack){
    if (!pstack) s_destructor(pstack);
    (*pstack) = nullptr;
}

void InKeyboard(stack** pstack) {
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

void InFile(stack** pstack, char* filename) {
    InitNewStack(pstack);
    FILE *pFile = fopen(filename,"r");
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

void stackShow(stack** pstack) {
    stack* temp = (*pstack);
    if (!temp) printf("Пустой стэк");
    while (temp)
    {
        printf(" %d\n",temp->data);
        temp=temp->back;
    }
    printf("\n");
}

stack* task(stack* pfstack, stack* psstack) {
    stack *res; InitNewStack(&res);
    stack *temp = pfstack;
    while (temp)
    {
        s_push(&res,temp->data);
        temp=temp->back;
    }
    temp = psstack;
    while (temp)
    {
        s_push(&res,temp->data);
        temp=temp->back;
    }
    temp = pfstack;
    while (temp)
    {
        s_push(&res,temp->data);
        temp=temp->back;
    }
    return res;
}

void End(stack** fStack, stack** sStack,stack** rStack) {
    s_destructor(fStack); s_destructor(sStack); s_destructor(rStack); //Освобождаем память
}