//
// Created by Alex on 10.10.2020.
//

#ifndef LAB5_LAB_UI_HPP
#define LAB5_LAB_UI_HPP
#include <ctime>
#include <map>
#include "task_functions.hpp"


template<class T>
std::ostream& operator<<(std::ostream& os,const std::vector<T>& v){
    os << "{ ";
    for (const auto& item :v) os << item << " ";
    os << "}";
    return os;
}

class lab_ui {
//First task for int float and double
    std::vector<int>* vInt;
    std::vector<float>* vFloat;
    std::vector<double>* vDouble;

    std::map<std::string,short>* commands;

    int vType;

public:
    lab_ui();
    ~lab_ui() = default;

    void showUI();
    template<class T>
    static void generate_vector(std::vector<T>&);
private:
    short get_command();
    bool event_handler(short);

    template<class T>
    static void get_vector(std::vector<T>&);
    template<class T>
    static void show_vector(std::vector<T>&);

    static double get_num();

#define execute(function) if (vType==1) function(*vFloat); else if (vType==2) function(*vDouble); else function(*vInt)
};




template<class T>
void lab_ui::generate_vector(std::vector<T>& v) {
    srand(10);
    const double max_number = 15;

    size_t vector_size = rand()%20;
    for (size_t i=0;i<vector_size;i++){
        double value = (double)rand()/RAND_MAX*max_number * (rand()%2 ? 1 : -1);
        v.push_back(static_cast<T>(value));
    }
}

lab_ui::lab_ui(): vInt(nullptr), vDouble(nullptr), vFloat(nullptr), vType(0){}

void lab_ui::showUI() {
    vInt = new std::vector<int>;
    commands = new std::map<std::string,short>;
    *commands = {{"generate",1},{"type",2},{"sum",3},{"mult",4},{"sort",5},{"switch",6},{"exit",7}};
    while(event_handler(get_command()));

    delete vInt;
    delete vFloat;
    delete vDouble;
    delete commands;
}

bool lab_ui::event_handler(short command) {
    switch (command) {
        default:
            std::cout << "Unknown command\n";
            break;
        case(1):
            execute(generate_vector);
            break;
        case(2):
            execute(get_vector);
            break;
        case(3):
            execute(sumOfNegative);
            break;
        case(4):
            try {
                execute(mulFromMinToMax);
            } catch (std::exception& error) {
                std::cout << error.what() << std::endl;
            }
            break;
        case(5):
            execute(bubbleSort);
            break;
        case(6): {
            execute(bubbleSort);
            std::cout << "Which type to use? int float double?";
            std::string newType;
            std::cin>> newType;
            for (auto& item: newType) item=tolower(item);
            if (newType=="int"){
                delete vDouble;
                delete vFloat;
                vInt = new std::vector<int>;
                vType=0;
            }
            if (newType=="float"){
                delete vDouble;
                delete vInt;
                vFloat = new std::vector<float>;
                vType=1;
            }
            if (newType=="double"){
                delete vInt;
                delete vFloat;
                vDouble = new std::vector<double>;
                vType=2;
            }
            else std::cout << "Wrong command\n";
        }
            break;
        case(7): return false;
    }
    return true;
}

short lab_ui::get_command() {
    std::cout << "Current Vector:\n";
    execute(show_vector);
    std::string command;
    std::cin>>command;
    for (auto& item: command) item=tolower(item);
    try{
        return commands->at(command);
    }
    catch (...) {
        return 0;
    }
}

template<class T>
void lab_ui::get_vector(std::vector<T> &) {

}

template<class T>
void lab_ui::show_vector(std::vector<T> & v) {
    std::cout << v;
}

double lab_ui::get_num() {
    double num;
    std::string sNum;
    bool isCorrect = false;
    while(!isCorrect) {
        std::cin>>sNum;
        try {
            num= std::stod(sNum);
            isCorrect = true;
        }
        catch (...) {
            std::cout << "Wrong argument. Try again.\n";
        }
    }
    return num;
}


#endif //LAB5_LAB_UI_HPP
