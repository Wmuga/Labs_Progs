#include "counter.h"
#include <stdexcept>

//----Стандратный констуктор----//
counter::counter():currentValue(0) {
}
//----Конструктор с указанием текущего значения для счетчика----//
counter::counter(const int& curVal):currentValue(curVal) {
    if (currentValue<minValue || currentValue>maxValue) {
        currentValue=0;
        throw std::runtime_error(out_of_range_error);
    }
}

//----Увеличение и уменьшение счетчика на единицу с проверкой на выход за пределы диапазона----//
void counter::increase() {
    if(++currentValue>maxValue) {
        --currentValue;
        throw std::runtime_error(out_of_range_error);
    }
}

void counter::decrease() {
    if (--currentValue<minValue) {
        ++currentValue;
        throw std::runtime_error(out_of_range_error);
    }
}
//----Получение значения----//
int counter::get() const {
    return currentValue;
}

//----Констукторы дочернего класса, вызывающий родительский----//
counter1::counter1():counter(){

}

counter1::counter1(const int& curVal) : counter(curVal){
}

//----Увеличение и уменьшение на произвольное значение с проверкой на выход за пределы----//
void counter1::increase(const int& value) {
    currentValue+=value;
    if (currentValue<minValue || currentValue>maxValue) {
        currentValue-=value;
        throw std::runtime_error(out_of_range_error);
    }
}

void counter1::decrease(const int& value) {
    currentValue-=value;
    if (currentValue<minValue || currentValue>maxValue) {
        currentValue+=value;
        throw std::runtime_error(out_of_range_error);
    }
}
