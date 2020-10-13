#ifndef LAB2_3_COUNTER_H
#define LAB2_3_COUNTER_H
#include <string>

class counter {
protected:
//----Поля, содержащие текущее значение и ограничения счетчика----//
    const int minValue = -2048;
    const int maxValue = 2048;
    int currentValue;
//----Сообщение ошибки----//
    const std::string out_of_range_error = "counter::out_of_range";

public:
//----Конструкторы----//
    counter();
    explicit counter(const int&);
//----Виртуальные функции увеличения и уменьшения счетчика----//
    virtual void increase();
    virtual void decrease();
//----Получение значения счетчика----//
    [[nodiscard]] int get() const;

};

class counter1:public counter{

public:
//----Конструкторы дочернего класса----//
    counter1();
    explicit counter1(const int&);
//----Перезаписанные функции увеличения и уменьшения счетчика----//
    void increase(const int&);
    void decrease(const int&);
};

#endif //LAB2_3_COUNTER_H
