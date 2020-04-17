#include <cstdio>
#include <cstdlib>
#include <cctype>

//Параметр - входной файл
int main(int argc, char** argv) {
    system("chcp 65001");
    printf("Лабораторная работа #9\n");

    FILE *pFile = fopen(argv[1], "r");

    bool flag = true; //Проверкана условие - количество слов в каждом предложении равно порядковому номеру этого предложения
    int wordsCount = 0, sentenceCount = 0; //Счетчики слов и предлодений
    char gotchar; //принятый символ
    bool prevAlpha=false; //Является ли предыдущий сивол числом
    do {
        gotchar = (char) fgetc(pFile);
        if (!feof(pFile)) {
            if (prevAlpha and !isalpha(gotchar)) wordsCount++;
            if (wordsCount != 0 and (gotchar == '!' or gotchar == '.' or gotchar == '?')) {
                sentenceCount++;
                if (wordsCount != sentenceCount) flag = false;
                wordsCount = 0;
            }
            prevAlpha = isalpha(gotchar);
        }
        else {
            if (wordsCount != 0) sentenceCount++;
            if (wordsCount != 0 and wordsCount != sentenceCount) flag = false;
        }
    } while (!feof(pFile) and flag);

    if (!flag) printf("В предложении #%d количество слов не совпадает с номером\n", sentenceCount);
    else printf("Во всех #%d предложениях количетсво совпадает с номером\n", sentenceCount);

    fclose(pFile);

    printf("Press ENTER");
    getc(stdin);
    return 0;
}
