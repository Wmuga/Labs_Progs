#ifndef LAB4_TINT_H
#define LAB4_TINT_H
#include <istream>

class tInt {
    //Текущее значение
    int* value;
public:
    //Конструкторы
    tInt();
    explicit tInt(const int&);
    //Prefix
    tInt& operator++();
    //Postfix
    tInt operator++(int);
    //Prefix
    friend tInt& operator--(tInt&);
    //Postfix
    friend tInt  operator--(tInt&,int);

    friend std::ostream& operator<<(std::ostream&,const tInt&);

    ~tInt();
};


#endif //LAB4_TINT_H
