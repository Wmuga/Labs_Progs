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
    size_t step = 10000;
    for (size_t cur_size = start_size; cur_size<max_size; cur_size+=step)
    {
        SearchElement<arrayType,arrayType> SearchEl(max_array,cur_size-1,funcIsElement,funcSearchMin);
        std::clog<<"constructed\n";
        time_t st,et;
        st=clock();
        big_integer res = SearchEl.search(1,cur_size/2,cur_size/2+1,0,cur_size-1);
        et=clock();
        (*logger).PutInLog(et-st);
    }
}

int main(int argc,char** argv) {
    Log logger1(R"(D:\Documents\GitHub\Labs_Progs\Sem2\StudPractiseLog\Log\)");
    Log logger2(R"(D:\Documents\GitHub\Labs_Progs\Sem2\StudPractiseLog\Log\)");
    Log logger3(R"(D:\Documents\GitHub\Labs_Progs\Sem2\StudPractiseLog\Log\)");
    std::ifstream InputFile(argv[1]);
    std::string data_buffer;

    size_t array_size;
    InputFile >> array_size;
    arrayType *inputArray = new arrayType[array_size];
    for (size_t i = 0; i < array_size; i++)
        InputFile >> inputArray[i];

    size_t start=array_size-1,end = array_size;

    std::thread t1(f1,inputArray,start,end,&logger1);
    //std::thread t2(f1,inputArray,start,end,&logger2);

    t1.join();
    //t2.join();
    //f1(inputArray,start,end,&logger3);

    delete[]inputArray;
    return 0;
}
