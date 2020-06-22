#include <iostream>
#include <thread>
void f1(){}

int main() {
    std::thread t1(f1);
    t1.join();
    return 0;
}
