#include <iostream>
#include "Converter.h"

int main() {
    /*
    std::cout << //converter::dtos(
            converter::stod("1.a",12) << " " << converter::stod("-0.b",12);
            //,12);
            */
    std::cout << converter::stod("1.a",12) << " " << converter::dtos(
            converter::stod("1.a",12)-converter::stod("-0.a",12),12
            );
    return 0;
}
