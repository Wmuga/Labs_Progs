//
// Created by Alex on 18.09.2020.
//

#ifndef LAB4_STACK_HPP
#define LAB4_STACK_HPP
#include <malloc.h>
#include <istream>
#include <vector>
#include <algorithm>

template<class T>
class stack {
    std::vector<T> array;
public:
    stack();
    ~stack();
    //Standart push and pop
    void push_back(const T&);
    T pop();
    //Overloaded+= acting as push
    stack& operator+=(const T&);
    //Prefix and postfix -- acting as pop
    stack& operator--();
    stack operator--(int);

    stack operator+(const stack&);

    //Error if elements in second are not in first
    stack operator-(const stack&);

    stack& operator=(const stack&);

    template<class T1>
    friend std::ostream& operator<<(std::ostream&,const stack<T1>&);

};

template<class T>
stack<T>::~stack() = default;

template<class T>
stack<T>::stack() = default;

template<class T>
void stack<T>::push_back(const T& item) {
    array.push_back(item);
}

template<class T>
T stack<T>::pop() {
    T item = array[array.size()-1];
    array.pop_back();
    return item;
}

template<class T>
stack<T>& stack<T>::operator+=(const T& item) {
    push_back(item);
    return *this;
}

template<class T>
stack<T>& stack<T>::operator=(const stack& in) {
    this->array=in.array;
    return *this;
}

template<class T>
stack<T>& stack<T>::operator--() {
    pop();
    return *this;
}

template<class T>
stack<T> stack<T>::operator--(int) {
    stack<T> prev_stack = (*this);
    pop();
    return prev_stack;
}

template<class T>
stack<T> stack<T>::operator-(const stack& decr) {
    stack<T> new_stack = *this;
    for (const T& item : decr.array){
        auto item_position = std::find(new_stack.array.begin(),new_stack.array.end(),item);
        if (item_position==new_stack.array.end()) throw std::invalid_argument("Unable find element in first stack");
        new_stack.array.erase(item_position);
    }
    return new_stack;
}

template<class T>
stack<T> stack<T>::operator+(const stack& incr) {
    stack<T> new_stack = *this;
    for (auto item_iter = incr.array.rbegin(); item_iter<incr.array.rend();item_iter++)
        new_stack.push_back(*item_iter);
    return new_stack;
}

template<class T>
std::ostream &operator<<(std::ostream& os, const stack<T>& out) {
    os << "[ ";
    for (const T& item: out.array) os << item << " ";
    os << "]";
    return os;
}


#endif //LAB4_STACK_HPP