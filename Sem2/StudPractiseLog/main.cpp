#include <iostream>
#include <ctime>
#include <fstream>
#include "big_int.h"
#include "SearchInArray.h"
#include "Logger.h"
#include "functions.h"

typedef big_integer arrayType;

int main(int argc,char** argv) {
    clock_t time_start, time_end;
    Log loggerMin((char *) "D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\min_");
    Log loggerMax((char *) "D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\max_");
    Log loggerSum((char *) "D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\sum_");
    Log loggerCount((char *) "D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\count_");
    Log loggerMinMore((char *) "D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\MinMore_");
    std::ifstream InputFile(argv[1]);
    std::string data_buffer;

    size_t array_size;
    InputFile >> array_size;
    arrayType *inputArray = new arrayType[array_size];
    for (size_t i = 0; i < array_size; i++)
        InputFile >> inputArray[i];

    size_t _array_size = 50000;
    size_t _start = 999;

    std::clog<<"Min"<<std::endl;
    for (size_t cur_size = _start; cur_size < _array_size; cur_size += 1000) {
        loggerMin.PutInLog((int) cur_size + 1);
        std::clog<<cur_size + 1<<std::endl;

        arrayType *cur_array = new arrayType[cur_size + 1];
        std::copy(inputArray, inputArray + cur_size, cur_array);

        time_start = clock();
        SearchElement<arrayType, arrayType>
                SearchEl(cur_array,
                         cur_size + 1,
                         funcIsElement<arrayType>,
                         funcSearchMax<arrayType>);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMax);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMax);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMin.PutInLog(time_end - time_start);
    }

    std::clog<<"Max"<<std::endl;
    for (size_t cur_size = _start; cur_size < _array_size; cur_size += 1000) {
        loggerMax.PutInLog((int) cur_size + 1);
        std::clog<<cur_size + 1<<std::endl;

        arrayType *cur_array = new arrayType[cur_size + 1];
        std::copy(inputArray, inputArray + cur_size, cur_array);

        time_start = clock();
        SearchElement<arrayType, arrayType>
                SearchEl(cur_array,
                         cur_size + 1,
                         funcIsElement<arrayType>,
                         funcSearchMin<arrayType>);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMax.PutInLog(time_end - time_start);
    }

    std::clog<<"Sum"<<std::endl;
    for (size_t cur_size = _start; cur_size < _array_size; cur_size += 1000) {
        loggerSum.PutInLog((int) cur_size + 1);
        std::clog<<cur_size + 1<<std::endl;

        arrayType *cur_array = new arrayType[cur_size + 1];
        std::copy(inputArray, inputArray + cur_size, cur_array);

        time_start = clock();
        SearchElement<arrayType, arrayType>
                SearchEl(cur_array,
                         cur_size + 1,
                         funcIsElement<arrayType>,
                         funcSum<arrayType>);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerSum.PutInLog(time_end - time_start);
    }

    eqValue<arrayType> = big_integer(10);
    std::clog<<"Count"<<std::endl;
    for (size_t cur_size = _start; cur_size < _array_size; cur_size += 1000) {
        loggerCount.PutInLog((int) cur_size + 1);
        std::clog<<cur_size + 1<<std::endl;

        arrayType *cur_array = new arrayType[cur_size + 1];
        std::copy(inputArray, inputArray + cur_size, cur_array);

        time_start = clock();
        SearchElement<arrayType, arrayType>
                SearchEl(cur_array,
                         cur_size + 1,
                         funcIsEquals<arrayType>,
                         funcSum<arrayType>);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerCount.PutInLog(time_end - time_start);
    }

    std::clog<<"MinMore"<<std::endl;
    for (size_t cur_size = _start; cur_size < _array_size; cur_size += 1000) {
        loggerMinMore.PutInLog((int) cur_size + 1);
        std::clog<<cur_size + 1<<std::endl;

        arrayType *cur_array = new arrayType[cur_size + 1];
        std::copy(inputArray, inputArray + cur_size, cur_array);

        time_start = clock();
        SearchElement<arrayType, arrayType>
                SearchEl(cur_array,
                         cur_size + 1,
                         funcIsElement<arrayType>,
                         funcSearchMinMore<arrayType>);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);

        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
        time_start = clock();
        SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
        time_end = clock();
        loggerMinMore.PutInLog(time_end - time_start);
    }
    delete[]inputArray;
    return 0;
}
