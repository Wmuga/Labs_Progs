#include <iostream>
#include "counter.h"

int main() {
//----Переменная на цикл интрефейса----//
    bool is_ui_cycled = true;
//----Тип счетчика 0 - counter, 1 - counter1----//
    bool is_second_type = false;
//----Для возможности пересоздания счетчиков без перегрузки оператора= делаем через указатели----//
    counter *c = new counter;
    counter1 *c1 = new counter1;
//----Основной цикл интерфейса с отловкой ошибок----//

    while (is_ui_cycled) {
        try {
            std::cout << (is_second_type ? "Counter1" : "Counter") << ": Range [-2048,2048]. Current value: " <<
            ((is_second_type) ? c1->get() : c->get()) << std::endl
            << "Commands:" << std::endl <<
                      "c: Create new counter" << std::endl <<
                      "i: Increase counter value " << std::endl <<
                      "d: Decrease counter value" << std::endl <<
                      "s: Switch between Counter and Counter1" << std::endl <<
                      "x: Exit" << std::endl;

            //----Считывание команд и их обработка----//
            int command = getc(stdin);
            fflush(stdin);

            switch (static_cast<char>(command)) {
                case 'x':
                    is_ui_cycled = false;
                    break;
                case 'c': {
                    std::cout << "Specify start value? 1/0" << std::endl;
                    int startValue = 0;

                    if (getc(stdin) - '0') {
                        std::cout << "Enter value" << std::endl;
                        std::string buffer;
                        //----Дополнительная проверка на правильность введенных данных----//
                        while (!startValue) {
                            try {
                                std::cin >> buffer;
                                startValue = std::stoi(buffer);

                                fflush(stdin);
                                //----Проверка на выбранный тип счетчика и выполнение команды----//
                            }
                            catch (const std::invalid_argument &) {
                                std::cout << "Wrong argument" << std::endl;
                            }
                        }

                    }

                    if (is_second_type) {
                        delete c1;
                        try {
                            !(startValue) ? c1 = new counter1 : c1 = new counter1(startValue);
                        }
                        catch (...) {
                            std::cout << "Out of range. Value set to zero\n";
                            c1 = new counter1;
                        }
                    } else {
                        delete c;
                        try {
                            !(startValue) ? c = new counter : c = new counter(startValue);
                        }
                        catch (...) {
                            std::cout << "Out of range. Value set to zero\n";
                            c = new counter;
                        }
                    }

                    break;
                }

                case 'i':
                    //----Проверка на выбранный тип счетчика и выполнение команды----//
                    if (is_second_type) {
                        std::cout << "Type value by which to increase" << std::endl;
                        std::string buffer;
                        std::cin >> buffer;
                        int value;
                        fflush(stdin);
                        //----Дополнительная проверка на правильность введенных данных----//
                        try {
                            value = std::stoi(buffer);
                            c1->increase(value);
                        }
                        catch (const std::invalid_argument &) {
                            std::cout << "Wrong argument" << std::endl;
                        }
                    } else c->increase();
                    break;

                case 'd':
                    //----Проверка на выбранный тип счетчика и выполнение команды----//
                    if (is_second_type) {
                        std::cout << "Type value by which to decrease" << std::endl;
                        std::string buffer;
                        std::cin >> buffer;
                        int value;
                        fflush(stdin);
                        //----Дополнительная проверка на правильность введенных данных----//
                        try {
                            value = std::stoi(buffer);
                            c1->decrease(value);
                        }
                        catch (const std::invalid_argument &) {
                            std::cout << "Wrong argument" << std::endl;
                        }
                    } else c->decrease();
                    break;

                case 's':
                    is_second_type = !is_second_type;
                    break;

                default:
                    std::cout << "Unknown command" << std::endl;
                    break;
            }
        }
            //----Ввывод ошибки----//
        catch (const std::exception &error) {
            std::cout << "Caught error: " << error.what() << std::endl;
        }
    }


//----Освобождение памяти----//
    delete c;
    delete c1;

    return 0;
}
