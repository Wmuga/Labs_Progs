#include <iostream>
#include "hash_table.h"

int main() {
    hash_table<int> test;
    test.insert("test",123);
    std::cout << test["xor"];
    return 0;
}
