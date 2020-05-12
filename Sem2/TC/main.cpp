#include <cstdio>
#include <windows.h>
//#include "tree.h"
#include "treeR2.h" //(вторая реализация дерева)
#include "Func.h"

//Параметры - входной файл для безключевого дерева
//файл для дерева по ключу, , Папка Логов
int main(int argc, char** argv) {

    system("chcp 65001");

    Init();
    InitLogger(argv[3]);

    PutInLog((char*)"Инициализированы модули\n");
    MakeTree(argv[1]);
    ShowTree2(head);
    PutInLog((char*)"Выведено древо на экран\n");
    remove(&head);

    PutInLog((char*)"Завершение програмы\n");
    EndLogger();
    return 0;
}