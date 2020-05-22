#include <cstdio>
#include <windows.h>
//#include "tree.h"
//#include "treeR2.h" //(вторая реализация дерева)
#include "treeR3.h" //(вторая реализация дерева)
#include "Func.h"

//Параметры - входной файл для безключевого дерева
//файл входных данных, Папка Логов
int main(int argc, char** argv) {

    system("chcp 65001");

    Init();
    InitLogger(argv[2]);

    PutInLog((char*)"Инициализированы модули\n");

    MakeTree(argv[1]);
    NodePtr headUnsorted = getStartUnsorted();
    ShowTree2(headUnsorted);
    PutInLog((char*)"Выведено неотсортированное древо на экран\n");
    printf("--------\n");
    MakeTreeKey();
    NodePtr headSorted = getStartSorted();
    ShowTree2(headSorted);
    PutInLog((char*)"Выведено отсортированное древо на экран\n");
    remove(&headUnsorted);
    remove(&headSorted);
    PutInLog((char*)"Завершение программы\n");
    EndLogger();
    return 0;
}