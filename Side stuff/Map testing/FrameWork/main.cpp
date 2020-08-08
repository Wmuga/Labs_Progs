#include "hmap.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <ctime>

struct Node
{
    char key[10];
    int value;
};


void tester(std::ofstream& out,const std::vector<Node>& array)
{
    clock_t start,end;
    //for (size_t i=5000-1;i<1000000;i+=5000)
    for (size_t i=0;i<10;i++)
    {
        out<<i+1<<std::endl;
        std::clog<<i+1<<std::endl;
        map<std::string,int> _map;
        start=clock();
        for (size_t j=0;j<i;j++)
        {
            _map.emplace(array[j].key,array[j].value);
        }
        end=clock();
        out<<end-start<<std::endl;
        std::clog<<end-start<<std::endl;
    }
}


int main() {
    std::ofstream out1("..\\out1.txt");
    std::ofstream out2("..\\out2.txt");
    std::ofstream out3("..\\out3.txt");

    std::ifstream in1("..\\in.txt",std::ios::binary);

    std::vector<Node> in_ar;
    while(true) {
        Node el{};
        in1.read((char*)&el, sizeof(Node));
        if (in1.eof()) break;
        in_ar.push_back(el);
    }
    in1.close();
    //std::thread t1(tester,out3,in_ar);
    //std::thread t2(tester,out3,in_ar);
    tester(out3,in_ar);
    //t1.join();
    //t2.join();
    out1.close();out2.close();out3.close();

    std::ifstream fin1("..\\out1.txt");
    std::ifstream fin2("..\\out2.txt");
    std::ifstream fin3("..\\out3.txt");

    std::ofstream out("..\\out.txt");

    while (true)
    {
        size_t count;
        size_t val1;
        size_t val2;
        size_t val3;
        fin1 >> count; fin2 >> count; fin3 >> count;
        fin1 >> val1; fin2 >> val2; fin3 >> val3;
        if (fin1.eof() || fin2.eof() || fin3.eof()) break;
        out << count << "\n";
        out << val1 << "\n" << val2 << "\n" << val3 << std::endl;
    }

    fin1.close();fin2.close();fin3.close(); out.close();
    remove("..\\out1.txt");remove("..\\out2.txt");remove("..\\out3.txt");

    return 0;
}
