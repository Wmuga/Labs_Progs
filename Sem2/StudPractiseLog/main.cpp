#include <iostream>
#include <thread>
#include <ctime>
#include <fstream>
#include "big_int.h"
#include "SearchInArray.h"
#include "Logger.h"
#include "functions.h"

typedef big_integer arrayType;

void f1(arrayType* max_array,size_t start_size ,size_t max_size,Log* logger)
{
    clock_t time_start, time_end;
    size_t step = 10000;
    for (size_t cur_size = start_size+step; cur_size<max_size; cur_size+=step)
    {
        (*logger).PutInLog((int)cur_size+1);
        std::clog<<cur_size+1<<std::endl;
        arrayType* cur_array = new arrayType[cur_size+1];
        std::copy(max_array,max_array+cur_size,cur_array);
        SearchElement<arrayType,arrayType> SearchEl(cur_array,cur_size,funcIsElement,funcSearchMin);


        time_start=clock();
        SearchEl.change_with_function(cur_size/2,cur_size/2,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_with_function(cur_size/2,cur_size/2,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_with_function(cur_size/2,cur_size/2,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);

        time_start=clock();
        SearchEl.change_with_function(0,cur_size/2,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_with_function(0,cur_size/2,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_with_function(0,cur_size/2,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);

        time_start=clock();
        SearchEl.change_with_function(0,cur_size,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_with_function(0,cur_size,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
        time_start=clock();
        SearchEl.change_with_function(0,cur_size,funcIncElement);
        time_end=clock();
        (*logger).PutInLog(time_end-time_start);
    }
}

int main(int argc,char** argv) {
    Log logger1(R"(D:\Documents\GitHub\Labs_Progs\Sem2\StudPractiseLog\Log\change1_)");
    Log logger2(R"(D:\Documents\GitHub\Labs_Progs\Sem2\StudPractiseLog\Log\change2_)");
    std::ifstream InputFile(argv[1]);
    std::string data_buffer;

    size_t array_size;
    InputFile >> array_size;
    arrayType *inputArray = new arrayType[array_size];
    for (size_t i = 0; i < array_size; i++)
        InputFile >> inputArray[i];

    chValue<arrayType> = 10;

    size_t start,end;
    start=-1; end=3530000;
    std::thread t1(f1,inputArray,start,end,&logger1);
    start=end-1; end = 5000000;
    std::thread t2(f1,inputArray,start,end,&logger2);

    t1.join();
    t2.join();

    delete[]inputArray;
    return 0;
}
