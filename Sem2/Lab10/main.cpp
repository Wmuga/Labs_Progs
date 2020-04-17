#include "Func.h"
#include <cstdio>

int main() {
    stack* newStack = InitNewStack();
    s_push(&newStack, 3);
    s_push(&newStack, 2);
    s_push(&newStack, 1);
    try {
        printf("%d\n", s_pop(&newStack));
        printf("%d",   s_pop(&newStack));
    }
    catch (int error) {
        printf("SUCC");
    }

    s_destructor(&newStack);
    return 0;
}