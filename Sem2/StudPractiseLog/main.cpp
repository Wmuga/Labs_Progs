#include <iostream>
#include <ctime>
#include <fstream>
#include "big_int.h"
#include "SearchInArray.h"
#include "Logger.h"
#include "functions.h"

typedef big_integer arrayType;

int main(int argc,char** argv) {
        clock_t time_start,time_end;
        Log logger((char*)"D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\min_");
        Log loggerMax((char*)"D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\max_");
        std::ifstream InputFile(argv[1]);
        std::string data_buffer;

        size_t array_size; InputFile>>array_size;
        arrayType* inputArray = new arrayType[array_size];
        for (size_t i=0;i<array_size;i++)
            InputFile>>inputArray[i];

        size_t _array_size = 2000;
        for (size_t cur_size=999;cur_size<_array_size;cur_size+=1000) {
            logger.PutInLog((int)cur_size+1);
            arrayType* cur_array = new arrayType[cur_size+1];
            std::copy(inputArray,inputArray+cur_size,cur_array);

            time_start=clock();
            SearchElement<arrayType, arrayType>
                    SearchEl(cur_array,
                             cur_size+1,
                             funcIsElement<arrayType>,
                             funcSearchMax<arrayType>);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.change_main_function(funcSearchMax);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.change_main_function(funcSearchMax);
            time_end=clock();
            logger.PutInLog(time_end-time_start);

            time_start=clock();
            SearchEl.search(1,0,cur_size,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.search(1,0,cur_size,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.search(1,0,cur_size,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);

            time_start=clock();
            SearchEl.search(1,0,cur_size%2,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.search(1,0,cur_size%2,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.search(1,0,cur_size%2,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);

            time_start=clock();
            SearchEl.search(1,cur_size%2,cur_size%2,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.search(1,cur_size%2,cur_size%2,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
            time_start=clock();
            SearchEl.search(1,cur_size%2,cur_size%2,0,cur_size);
            time_end=clock();
            logger.PutInLog(time_end-time_start);
        }

    for (size_t cur_size=999;cur_size<array_size;cur_size+=1000) {
        loggerMax.PutInLog((int)cur_size+1);
        arrayType* cur_array = new arrayType[cur_size+1];
        std::copy(inputArray,inputArray+cur_size,cur_array);

        time_start=clock();
        SearchElement<arrayType, arrayType>
                SearchEl(cur_array,
                         cur_size+1,
                         funcIsElement<arrayType>,
                         funcSearchMin<arrayType>);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_main_function(funcSearchMin);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);

        time_start=clock();
        SearchEl.search(1,0,cur_size,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.search(1,0,cur_size,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.search(1,0,cur_size,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);

        time_start=clock();
        SearchEl.search(1,0,cur_size%2,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.search(1,0,cur_size%2,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.search(1,0,cur_size%2,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);

        time_start=clock();
        SearchEl.search(1,cur_size%2,cur_size%2,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.search(1,cur_size%2,cur_size%2,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.search(1,cur_size%2,cur_size%2,0,cur_size);
        time_end=clock();
        loggerMax.PutInLog(time_end-time_start);
    }
    delete []inputArray;
    return 0;
}
