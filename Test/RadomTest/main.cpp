#include "big_double.h"
#include <iostream>


int main() {
    big_double test1 = big_double(192300.91113);
    std::cout<<test1<<"\n";
    big_double test2 = big_double(999993.12);
    std::cout<<test2<<"\n";
    std::cout<<test1+test2;
    return 0;
}
