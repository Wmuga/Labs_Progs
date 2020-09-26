#include <iostream>
#include "lab_ui.hpp"

int main() {
    lab4Ui ui(std::cout,std::cin);

    //ui.set_tInt_ui();
    //ui.set_stack_ui();
    ui.set_vector_ui();

    ui.show_ui();
    return 0;
}
