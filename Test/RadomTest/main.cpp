#include <iostream>
#include <cmath>
#include <thread>
#include "big_int.h"

bool t = false;

void f()
{
    getchar();
    t=true;
}

int main() {
    std::thread t1(f);
    while (!t)
    {
        std::cout<<"t";
    }
    t1.join();
    return 0;
}
