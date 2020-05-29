#include <utility>
#include "add_Structs.h"


//"Указатель" на ветвь содержит текущую позицию и указатель на файл, к которому принадлежит
typedef std::pair<int,FILE*> NodePtr;

FILE *pTreeUnsorted;NodePtr head;
FILE *pTreeSorted;  NodePtr headKey;

//Замена данных:
//          в текущей ветви
void replDataM(NodePtr *cur,data inf) {
    fseek((*cur).second, (*cur).first * sizeof(data), SEEK_SET);
    fwrite(&inf, sizeof(data), 1, (*cur).second);
}
//          слева
void replDataL(NodePtr *cur,data inf) {
    fseek((*cur).second, (*cur).first * 2 * sizeof(data), SEEK_SET);
    fwrite(&inf, sizeof(data), 1, (*cur).second);
}
//          справа
void replDataR(NodePtr *cur,data inf) {
    fseek((*cur).second, ((*cur).first * 2 + 1) * sizeof(data), SEEK_SET);
    fwrite(&inf, sizeof(data), 1, (*cur).second);
}

//Инициализатор
void Init()
{
    //Открываем соответствующие файлы
    pTreeUnsorted = fopen("C:\\Users\\Public\\Documents\\treeUnsorted.bin","wb+");
    pTreeSorted = fopen("C:\\Users\\Public\\Documents\\treeSorted.bin","wb+");
    if (pTreeUnsorted==nullptr or pTreeSorted== nullptr) throw 2;
    //Инициализируем корни
    head = std::make_pair(1,pTreeUnsorted);
    headKey = std::make_pair(1,pTreeSorted);
    //Записываем в корни пустые данные
    replDataM(&head,nullData);
    replDataM(&headKey,nullData);
}

//Переход влево
NodePtr curL(NodePtr cur){
    return std::make_pair(cur.first*2,cur.second);
}

//Переход вправо
NodePtr curR(NodePtr cur){
    return std::make_pair(cur.first*2+1,cur.second);
}
//Создание новой ветви, в зависимости от символа будет правым или левым или же "основой"
NodePtr NewNode(NodePtr *CurrentPosition, char Pos='0')
{
    if (Pos=='L') return curL(*CurrentPosition);
    else if (Pos=='R') return curR(*CurrentPosition);
    else return (*CurrentPosition);
}

//Получение данных
data getData(NodePtr cur) {
    data currentData;
    //Встаем на нужную позицию и считываем данные
    fseek(cur.second, cur.first * sizeof(data), SEEK_SET);
    fread(&currentData, sizeof(data), 1, cur.second);
    return currentData;
}

//Проверка на пустоту
bool IsEmpty(NodePtr nd)
{
    return (getData(nd).FName==nullptr);
}

//Уничтожение ветви или целого дерева
void destroy(NodePtr *cur) {
    //Если уничтожаем корень, то просто закрываем файл и уничтожаем его
    if (*cur == head) {
        fclose(pTreeUnsorted);
        remove("C:\\Users\\Public\\Documents\\treeUnsorted.bin");
    } else if (*cur == headKey) {
        fclose(pTreeSorted);
        remove("C:\\Users\\Public\\Documents\\treeSorted.bin");
    } else {
        //Иначе просто записываем в нужный файл на соответствующее место пустые данные
        fseek((*cur).second, (*cur).first * sizeof(data), SEEK_SET);
        fwrite(&nullData, sizeof(data), 1, (*cur).second);
        NodePtr nextL = std::make_pair((*cur).first * 2, (*cur).second);
        NodePtr nextR = std::make_pair((*cur).first * 2 + 1, (*cur).second);
        //и переходим влево и вправо
        if (!IsEmpty(nextL)) destroy(&nextL);
        if (!IsEmpty(nextR)) destroy(&nextR);
    }
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
    return std::make_pair((*cur).first/2,(*cur).second);
}

