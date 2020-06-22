#include <iostream>
#include <thread>
#include <ctime>
#include <fstream>
#include "big_int.h"
#include "SearchInArray.h"
#include "Logger.h"
#include "functions.h"

typedef big_integer arrayType;

void f1(arrayType* cur_array, size_t cur_size,Log loggerMulty)
{
    clock_t time_start, time_end;
    loggerMulty.PutInLog((int) cur_size + 1);
    std::clog<<cur_size + 1<<std::endl;


    time_start = clock();
    SearchElement<arrayType, arrayType>
            SearchEl(cur_array,
                     cur_size + 1,
                     funcIsElement<arrayType>,
                     funcSearchMax<arrayType>);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.change_main_function(funcSearchMax);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.change_main_function(funcSearchMax);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);

    time_start = clock();
    SearchEl.search(1, 0, cur_size, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.search(1, 0, cur_size, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.search(1, 0, cur_size, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);

    time_start = clock();
    SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.search(1, 0, cur_size % 2, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);

    time_start = clock();
    SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
    time_start = clock();
    SearchEl.search(1, cur_size % 2, cur_size % 2, 0, cur_size);
    time_end = clock();
    loggerMulty.PutInLog(time_end - time_start);
}

int main(int argc,char** argv) {
    Log loggerMulty((char *) "D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\multy_");
    std::ifstream InputFile(argv[1]);
    std::string data_buffer;

    size_t array_size;
    InputFile >> array_size;
    arrayType *inputArray = new arrayType[array_size];
    for (size_t i = 0; i < array_size; i++)
        InputFile >> inputArray[i];

    size_t _array_size = 50000;
    size_t _start = 999;
    size_t step = 20000;
    for (size_t cur_size = _start; cur_size < _array_size; cur_size += step) {
        arrayType *cur_array = new arrayType[cur_size/2 + 1];
        arrayType *cur_array1 = new arrayType[cur_size + 1];
        std::copy(inputArray, inputArray + cur_size-step/2, cur_array);
        std::copy(inputArray, inputArray + cur_size, cur_array1);

        std::thread t1(f1, cur_array,cur_size-step/2,loggerMulty);
        std::thread t2(f1, cur_array1,cur_size,loggerMulty);
        t1.join();
        t2.join();
    }
    delete[]inputArray;
    return 0;
}
