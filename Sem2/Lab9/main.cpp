#include <cstdio>
#include <cstdlib>
#include <algorithm>

int main(int argc, char** argv) {
    system("chcp 65001");
    printf("Лабораторная работа #9\n");

    FILE *pFile = fopen(argv[1], "r");

    char* sentenceSeparator = (char*)".!?";
    char* wordsSeparator = (char*)" ,:;\n\r\t\v.!?";

    bool flag=true; //Проверкана условие - количество слов в каждом предложении равно порядковому номеру этого предложения
    int wordsCount = 0, sentenceCount = 0, wrongSentence; //Счетчики слов и предлодений
    char gotchar; //принятый символ
    bool prevNotSeparator=false,curNotSeparator; //Является ли предыдущий символ и нынешний разделителем

    do {
        gotchar = (char) fgetc(pFile); //Получаем символ из предложений
        if (!feof(pFile)) {
            curNotSeparator=(std::find(wordsSeparator,wordsSeparator+11,gotchar)!=wordsSeparator+11); //определяем, является ли он разделителем
            if (prevNotSeparator and !curNotSeparator) wordsCount++; //Если предыдущей символ - не разделитель? а полученный им является - новое слово
            if (wordsCount != 0 and (std::find(sentenceSeparator,sentenceSeparator+3,gotchar)!=sentenceSeparator+3)) //ненулевое количество слов и полученный символ - разделитель
            {
                sentenceCount++;  // новое предложение
                flag = wordsCount==sentenceCount; //проверка на совпадание количества слов и номера предложения
                if (!flag) wrongSentence=sentenceCount; //Если не совпало, записываем его номер
                wordsCount = 0; //Обнуляем счетчик слов
            }
            prevNotSeparator = curNotSeparator; //Полученный символ становится предыдущим
        }
        else { //На случай если файл закончился не .?! увеличиваем количество предложений и делаем дополнительую проверку
            if (wordsCount != 0) sentenceCount++;
            if (wordsCount != 0 and wordsCount != sentenceCount) {flag = false; wrongSentence=sentenceCount;}
        }
    } while (!feof(pFile));

    if (!flag) printf("В предложении #%d количество слов не совпадает с номером\n", wrongSentence);
    else if (sentenceCount!=0) printf("Во всех %d предложениях количество совпадает с номером\n", sentenceCount);
    else printf("Нет предложений\n");

    fclose(pFile);

    printf("Press ENTER");
    getc(stdin);
    return 0;
}
