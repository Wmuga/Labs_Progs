#include <iostream>
#include "lab_ui.hpp"
#include <ctime>
//#include "tester_framework.hpp"

int main() {
    /*
    srand(time(0));
    for (size_t i=0;i<4;i++) {
        std::ofstream out(R"(D:\ADD_LINK\Git\Labs_Progs\Sem3\Lab5\t\out)" + std::to_string(i) + ".txt");
        std::ifstream in(R"(D:\ADD_LINK\Git\Labs_Progs\Sem3\Lab5\t\in)" + std::to_string(i) + ".txt");
        if (!(out.is_open() && in.is_open())) std::cout << "No " << i;
        else {
            char type;
            in>>type;
            switch (type) {
                case('i'):
                    test<int>(out,in);
                    break;
                case('f'):
                    test<float>(out,in);
                    break;
                case('d'):
                    test<double>(out,in);
                    break;
            }

        }
    }
    */
    lab_ui ui;
    ui.showUI();
    return 0;
}