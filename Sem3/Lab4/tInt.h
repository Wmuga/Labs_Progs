//
// Created by Alex on 18.09.2020.
//

#ifndef LAB4_TINT_H
#define LAB4_TINT_H
#include <istream>

class tInt {
    int* value;
public:
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
