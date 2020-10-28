#include "tInt.h"
#include "queue.hpp"
#include "vector.h"
#include <istream>

class lab4Ui{
    std::ostream& os;
    std::istream& is;

    tInt* newInt;
    bool is_first_queue;
    queue<long>* firstQueue;
    queue<long>* secondQueue;
    vector* newVector;
    unsigned short type;

public:
    lab4Ui();
    lab4Ui(std::ostream&, std::istream&);
    ~lab4Ui();
    //Методы подготовки меню под определенный тип данных
    void set_tInt_ui();
    void set_queue_ui();
    void set_vector_ui();
    //Вывод меню
    void show_ui();

private:
    //Обработчики команд
    bool tInt_eventHandler(const int&);
    bool queue_eventHandler(const int&);
    bool vector_eventHandler(const int&);
    //Вывод меню и получение команд от пользователя
    int tInt_get_user_command();
    int queue_get_user_command();
    int vector_get_user_command();
};

lab4Ui::lab4Ui(): os(std::cout), is(std::cin), newInt(nullptr),
                                                      firstQueue(nullptr), secondQueue(nullptr), newVector(nullptr), type(0), is_first_queue(false) {
}

lab4Ui::lab4Ui(std::ostream& _os, std::istream& _is): os(_os), is(_is), newInt(nullptr),
                                                      firstQueue(nullptr), secondQueue(nullptr), newVector(nullptr), type(0), is_first_queue(false) {
}

//Все меню работают одинаково: обработчик событий выдает завершилась программа или нет,
//а метод получения комманд возвращает их код, что позволяет обернуть их в виде
//цикл с предусловием(обработчик комманд(получение комманды()))
void lab4Ui::show_ui() {
    bool show_ui  = true;
    switch(type) {
        default:
            while (show_ui){
                try{
                   show_ui = tInt_eventHandler(tInt_get_user_command());
                } catch (std::exception& error) {
                    os<< error.what() << std::endl;
                }
            }
            delete newInt;
            break;
        case(1):
            while(show_ui){
                try{
                    show_ui = queue_eventHandler(queue_get_user_command());
                } catch (std::exception& error) {
                    os<< error.what() << std::endl;
                }
            }
            delete firstQueue;
            delete secondQueue;
            break;
        case(2):
            while(show_ui){
                try{
                    show_ui = vector_eventHandler(vector_get_user_command());
                } catch (std::exception& error) {
                    os<< error.what() << std::endl;
                }
            }
            delete newVector;
            break;
    }
}

void lab4Ui::set_tInt_ui() {
    newInt = new tInt;
    type = 0;
}

void lab4Ui::set_queue_ui() {
    firstQueue = new queue<long>;
    secondQueue = new queue<long>;
    is_first_queue=true;
    type = 1;
}

void lab4Ui::set_vector_ui() {
    newVector = new vector;
    type=2;
}

int lab4Ui::tInt_get_user_command() {
    os << "Task1 Integer type. Current value: " << (*newInt) << std::endl <<
    "create: to recreate Integer"<< std::endl <<
    "+value: to prefix increment"<< std::endl <<
    "value+: to postfix increment"<< std::endl <<
    "-value: to prefix decrement"<< std::endl <<
    "value-: to postfix decrement"<< std::endl<<
    "exit:   to exit the menu"<< std::endl;

    int command_code=0;
    std::string command;
    is>>command;

    if (command=="create") command_code=1;
    else if (command=="+value") command_code=2;
    else if (command=="value+") command_code=3;
    else if (command=="-value") command_code=4;
    else if (command=="value-") command_code=5;
    else if (command=="exit") command_code=6;

    return command_code;
}


bool lab4Ui::tInt_eventHandler(const int& command) {
    switch (command) {
        default:
            os << "Unknown command" << std::endl;
            break;
        case (1): {
            std::string buffer;
            int startValue = 0;

            try {
                is >> buffer;
                startValue = std::stoi(buffer);

            }
            catch (const std::exception &) {
                os << "Wrong argument. Value set to 0" << std::endl;
            }
            delete newInt;
            newInt = new tInt(startValue);
        }
            break;
        case (2):
            ++(*newInt);
            break;
        case (3):
            (*newInt)++;
            break;
        case (4):
            --(*newInt);
            break;
        case (5):
            (*newInt)--;
            break;
        case (6):
            return false;
    }
    return true;
}

lab4Ui::~lab4Ui() {
    delete newInt;
    delete firstQueue;
    delete secondQueue;
    delete newVector;
}

int lab4Ui::queue_get_user_command() {
    queue<long>* current_queue = (is_first_queue) ? firstQueue : secondQueue;
    os << "Task2 Queue. Current queue" << static_cast<int>(!is_first_queue) + 1 << ":\n" << (*current_queue) << std::endl <<
       "create: to recreate queue" << std::endl <<
       "switch: to switch between first and second queue"<< std::endl <<
       "add:    to add new element to queue"<< std::endl <<
       "pop:    to pop first element from queue"<< std::endl <<
       "sum:    to sum first and second queue"<< std::endl <<
       "sub:    to subtract second queue from first"<< std::endl<<
       "exit:   to exit the menu"<< std::endl;

    int command_code=0;
    std::string command;
    is>>command;

    if (command=="create") command_code=1;
    else if (command=="add") command_code=2;
    else if (command=="pop") command_code=3;
    else if (command=="sum") command_code=4;
    else if (command=="sub") command_code=5;
    else if (command=="exit") command_code=6;
    else if (command=="switch") command_code=7;

    return command_code;
}

bool lab4Ui::queue_eventHandler(const int& command) {
    switch (command) {
        default:
            os << "Unknown command" << std::endl;
            break;
        case (1): {
            if (is_first_queue){
                delete firstQueue;
                firstQueue = new queue<long>;
            }
            else{
                delete secondQueue;
                secondQueue = new queue<long>;
            }
        }
            break;
        case (2): {
            std::string buffer;
            os<<"Type value to add" << std::endl;
            try {
                is >> buffer;
                (*((is_first_queue) ? firstQueue : secondQueue))+=(std::stol(buffer));
            }
            catch (const std::exception &) {
                os << "Wrong argument" << std::endl;
            }
        }
            break;
        case (3):
            --(*((is_first_queue) ? firstQueue : secondQueue));
            break;
        case (4):
        {
            queue<long> new_stack = (*firstQueue);
            (*((is_first_queue) ? firstQueue : secondQueue)) = new_stack;
        }
            break;
        case (5):
            try {
                (*((is_first_queue) ? firstQueue : secondQueue)) = ((*firstQueue) - (*secondQueue));
            }
            catch (const std::exception& error){
                os << error.what() << std::endl;
            }
            break;
        case (6):
            return false;
        case(7):
            is_first_queue=!is_first_queue;
            break;
    }
    return true;
}

int lab4Ui::vector_get_user_command() {
    os << "Task3 Vector. Current vector:\n" << (*newVector) << std::endl <<
       "create: to recreate vector" << std::endl <<
       "add:    to add new element to vector"<< std::endl <<
       "rem:    to remove element from vector"<< std::endl <<
       "pop:    to pop last element from vector"<< std::endl <<
       "exit:   to exit the menu"<< std::endl;

    int command_code=0;
    std::string command;
    is>>command;

    if (command=="create") command_code=1;
    else if (command=="add") command_code=2;
    else if (command=="pop") command_code=3;
    else if (command=="rem") command_code=4;
    else if (command=="exit") command_code=5;

    return command_code;
}

bool lab4Ui::vector_eventHandler(const int& command) {
    switch (command) {
        default:
            os << "Unknown command" << std::endl;
            break;
        case (1): {
            delete newVector;
            try{
                os << "How to create vector?\n1 - empty vector\n2 - with one element\n3 - with preallocated memory\n4 - type all elements" << std::endl;
                char ctype;
                is>>ctype;
                switch (ctype-'0') {
                    default:
                        throw std::invalid_argument("Unknown command");
                    case(1):
                        newVector = new vector;
                        break;
                    case(2): {
                        os << "Specify element" << std::endl;
                        std::string buffer;
                        long first_element;
                        is >> buffer;
                        first_element = std::stol(buffer);
                        newVector = new vector(first_element);
                    }
                        break;
                    case(3): {
                        os << "Specify count of elements for allocating memory" << std::endl;
                        std::string buffer;
                        size_t elements_count;
                        is >> buffer;
                        elements_count = std::stoul(buffer);
                        newVector = new vector(elements_count);
                    }
                        break;
                    case(4):{
                        newVector = new vector;
                        os << "Firstly specify count of elements, then type elements themselves" << std::endl;
                        is >> (*newVector);
                    }
                        break;
                }
            } catch (const std::exception& error) {
                os << error.what() << std::endl << "Created standart vector" << std::endl;
                newVector = new vector;
            }
        }
            break;
        case (2): {
            os << "Would you like to specify element? y/n" << std::endl;
            char command_char;
            is>>command_char;
            switch (command_char) {
                case('y'): {
                    os << "Type element" << std::endl;
                    long element=0;
                    try {
                        std::string buffer;
                        is >> buffer;
                        element = std::stol(buffer);
                    }
                    catch (const std::exception &) {
                        os << "Wrong argument. Value set to zero"<<std::endl;
                    }
                    (*newVector)+=element;
                }
                    break;
                case('n'):
                    (*newVector)++;
                    break;
                default:
                    os << "Unknown command" << std::endl;
                    break;
            }
        }
            break;
        case (3):
            --(*newVector);
            break;
        case (4):
        {
            os << "Type element to remove" << std::endl;
            long element=0;
            while(!element) {
                try {
                    std::string buffer;
                    is >> buffer;
                    element = std::stol(buffer);
                }
                catch (const std::exception &) {
                    os << "Wrong argument. Type again" << std::endl;
                }
            }
            try{
                (*newVector)-=element;
            }catch (const std::exception& error) {
                os << error.what() << std::endl;
            }
        }
            break;
        case (5):
            return false;
    }
    return true;
}


