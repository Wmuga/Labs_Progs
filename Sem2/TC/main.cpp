#include <cstdio>
#include <windows.h>
#include "tree.h"
//#include "treeR2.h" (вторая реализация дерева)
#include "Func.h"


int main(int argc, char** argv) { //Параметры - входной файл, Папка Логов
    system("chcp 65001");

    Init();
    InitLogger(argv[2]);

    PutInLog((char*)"Инициализированы модули\n");
    MakeTree(argv[1]);
    ShowTree(head);
    PutInLog((char*)"Выведено древо на экран\n");
    remove(&head);

    PutInLog((char*)"Завершение програмы\n");
    EndLogger();
    return 0;
}