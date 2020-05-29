#include <cstdio>
#include <windows.h>
#include <cctype>
#include "tree.h"    //Реализация дерева через список
//#include "treeR3.h"  //Реализация дерева через файл
#include "Func.h"


using function = void(*)(NodePtr,FILE*,int);
//Параметры - входной файл для безключевого дерева
//файл входных данных, Папка Логов
int main(int argc, char** argv) {

    system("chcp 65001");
    Init();
    char* filename = new char[255]; //Имя входного файла
    char* buffer = new char[10]; //Буффер для считывания комманд при вывода дерева
    //Начало обработки аномалий
    try {
        InitLogger(argv[2]); //Подключаем лог-файл
        PutInLog((char *) "Инициализированы модули\n");
        //Создание деревьев
        MakeTree(argv[1]);
        MakeTreeKey();
        //Получение "указателей" на "корень"
        NodePtr headUnsorted = getStartUnsorted();
        NodePtr headSorted = getStartSorted();
        //Меню
        int end = 0;
        while (!end) {
            char act;
            printf("\'v\' - вывести деревья на экран\n"
                   "\'p\' - вывести план поминок\n"
                   "\'a\' - добавить к дереву по ключу\n"
                   "\'t\' - выполнить поиск человека, у которого обоих дедушек зовут Иванами\n"
                   "\'r\' - пересоздать деревья\n"
                   "\'x\' - завершение программы\n");
            scanf("%c", &act);
            fflush(stdin);
            act = (char) tolower(act);
            //Обработка  комманд
            switch (act) {
                default: //Если пользователь ввел что-то невнятное
                    printf("Неизвестная команда\n");
                    break;
                case 'v': //Вывод деревьев на экран
                    PutInLog((char *) "Вывод деревьев на экран ");
                    int type;
                    function fShowTree; //переменная, в которую определяется способ вывода дерева
                    printf("Выберите способ: \'1\' - Корень-Лево-Право \'2\' - Лево-Корень-Право  \'3\' - Лево-Право-Корень\n");
                    scanf("%s", buffer); type = strtol(buffer, nullptr, 10);
                    fflush(stdin);
                    //Выбираем на основе введенных данных
                    switch (type) {
                        default: //Если пользователь ввел что-то невнятное
                            printf("Неверная команда\n");
                            fShowTree = nullptr;
                            PutInLog((char *) "\nНе удалось т.к. пользователь ввел неверную команду\n");
                            break;
                        case (1): //Kорень-Лево-Право
                            PutInLog((char *) "типом Kорень-Лево-Право\n");
                            fShowTree = &ShowTree1;
                            break;
                        case (2): //Лево-Корень-Право
                            PutInLog((char *) "типом Лево-Корень-Право\n");
                            fShowTree = &ShowTree2;
                            break;
                        case (3): //Лево-Право-Корень
                            PutInLog((char *) "типом Лево-Право-Корень\n");
                            fShowTree = &ShowTree3;
                            break;
                    }
                    if (fShowTree!=nullptr) { //Если успешно выбран способ
                        printf("Генеалогическое дерево\n");
                        //Выводим в консоль деревья
                        fShowTree(headUnsorted, stdout, 0);
                        printf("----------------\nУпорядоченное дерево\n");
                        fShowTree(headSorted, stdout, 0);
                        printf("\n");
                    }
                    break;
                case 't': //Поиск человека, у которого обоих дедушек зовут Иванами
                    PutInLog((char *) "Производится поиск элемнта по ключу\n");
                    if (Task(headUnsorted))
                        printf("Найден человек, у которого обоих дедушек зовут Иванами\n");
                    else printf("Нет такого человека, у которого обоих дедушек зовут Иванами\n");
                    break;
                case 'r': //Пересоздание деревьев
                    PutInLog((char *) "Вызвано пересоздание деревьев\n");
                    //уничтожаем текущие деревья
                    remove(&headUnsorted);
                    remove(&headSorted);
                    //Переинициализируем
                    Init();
                    //Считываем имя файла
                    printf("Введите полное имя файла, с которого нужно получить входные файлы\n"
                           "Если из того же \"--\"\n");
                    scanf("%s",filename);
                    //Если введено --  - вызываем из того же
                    if (strcmp(filename,"--")==0) {
                        filename = argv[1];
                        PutInLog((char *) "Создание из того же входного файла\n");
                    }
                    else {
                        PutInLog((char *) "Создание из ");
                        PutInLog(filename);
                        PutInLog((char*)"\n");
                    }
                    //Создаем снова деревья
                    MakeTree(filename);
                    MakeTreeKey();
                    //Получаеи указатели на корни
                    headUnsorted = getStartUnsorted();
                    headSorted = getStartSorted();
                    break;
                case 'x': //Завершение программы
                    PutInLog((char *) "Вызвано завершение программы\n");
                    end = 1;
                    break;
                case 'p': //Вывод плана поминок
                    PutInLog((char *) "Вывод плана поминок\n");
                    ShowTree(headSorted);
                    printf("\n");
                    break;
                case 'a': //Добавление элемента в интеракитвном режиме
                    PutInLog((char *) "Вызвано добавление элемента вручную\n");
                    printf("Введите ФИО\n");
                    //Считываем отдельно имя
                    char *FName = new char[10];
                    scanf("%s", FName);
                    //Отправляем в функцию, продолжающую считывать данные, и получеенные данные в функцию добвления элемента
                    AddToTreeKey(readData(FName));
                    PutInLog((char *) "Отсортированное дерево:\n");
                    ShowTree1(headSorted, pLog);
                    break;
            }
        }
        // под конец уничтожаем деревья и закрываем в лог
        remove(&headUnsorted);
        remove(&headSorted);
        PutInLog((char *) "Завершение программы\n");
        EndLogger();
    }
    //Если во время выполнения программы пошло что-то не так
    catch(int errorCode)
    { //На основе выданного кода ошибки сообщаем какая именно она была
        switch(errorCode){
            default: //На случай, если выбросится что-то непонятное
                printf("Неизвестный код ошибки\n");
                break;
            case (0):
                printf("Невозможно создать Лог-файл\n");
                break;
            case (1):
                printf("Невозможно прочитать входной файл\n");
                PutInLog((char*)"Завершение программы из-за невозможности прочитать входной файл\n");
                EndLogger();
                break;
            case (2):
                printf("Невозможно создать бинарные файлы\n");
                PutInLog((char*)"Завершение программы из-за невозможнсти создать бинарные файлы\n");
                EndLogger();
                break;
            case (3):
                printf("Неверный формат в поле даты\n");
                PutInLog((char*)"Завершение программы из-за неверного формата даты\n");
                EndLogger();
                break;
            case (4):
                printf("Попытка записи в существующий блок\n");
                PutInLog((char*)"Завершение программы из-за неверных входных данных\n");
                EndLogger();
                break;
        }
    }
    //Возвращаем память
    delete []filename;
    delete []buffer;
    printf("PRESS ENTER");
    getchar();
    return 0;
}