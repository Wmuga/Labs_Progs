#include <iostream>
#include <thread>
#include <fstream>

struct data{
    size_t num;
    size_t time1;
    size_t time2;
    size_t time3;
    size_t time4;
};

void get_data(std::ifstream* inp,data* new_data)
{
    *inp>>(*new_data).num;
    *inp>>(*new_data).time1;
    *inp>>(*new_data).time2;
    *inp>>(*new_data).time3;
    *inp>>(*new_data).time4;
}

int main() {
    std::ifstream f1("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\Log1.txt");
    std::ifstream f2("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\Log2.txt");
    std::ifstream f3("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\Log3.txt");
    std::ofstream out("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\Log\\search.txt");
    data data1;
    data data2;
    data data3;
    while (!f1.eof())
    {
        std::thread t1(get_data,&f1,&data1);
        std::thread t2(get_data,&f2,&data2);
        get_data(&f3,&data3);
        t1.join();
        t2.join();
        out<<data1.num<<std::endl;
        out<<data1.time1<<std::endl;
        out<<data2.time1<<std::endl;
        out<<data3.time1<<std::endl;
        out<<data1.time2<<std::endl;
        out<<data2.time2<<std::endl;
        out<<data3.time2<<std::endl;
        out<<data1.time3<<std::endl;
        out<<data2.time3<<std::endl;
        out<<data3.time3<<std::endl;
        out<<data1.time4<<std::endl;
        out<<data2.time4<<std::endl;
        out<<data3.time4<<std::endl;
    }
    return 0;
}
