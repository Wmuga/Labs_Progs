//
// Created by Alex on 03.06.2020.
//

#include "big_double.h"
#include <iostream>

big_double::big_double() {}

big_double::big_double(std::string str) {
    //If empty - no digits, initializing _is_negative
    if (str.length()==0)
    {
        this->_is_negative=0;
    } else
    {
        //first - checking for minus
        if (str[0]=='-')
        {
            str = str.substr(1);
            this->_is_negative=1;
        } else
        {
            this->_is_negative=0;
        }
        //Checking for dot position
        size_t dot_position = str.find('.');

        //If there's dot
        if (dot_position!=std::string::npos) {
            //Getting digits from fractional part
            size_t i = str.length();
            while (i>dot_position){
                //If there's smaller then 9 digits, pushing them all
                if (i < base_digits_count + dot_position) {
                    const char* substring = str.substr(dot_position + 1, i).c_str();
                    this->_fractional_digits.push_back(atoi(substring));
                    i = dot_position;
                    delete []substring;
                }
                else {
                    const char* substring = str.substr(i - base_digits_count, i).c_str();
                    this->_fractional_digits.push_back(atoi(substring));
                    i -= base_digits_count;
                    delete []substring;
                }
            }
            //Then rest of them
            while (i>0){
                //If there's smaller then 9 digits, pushing them all
                if (i < base_digits_count) {
                    this->_integer_digits.push_back(atoi(str.substr(0, i).c_str()));
                    i = 0;
                }
                else {
                    this->_integer_digits.push_back(atoi(str.substr(i - base_digits_count, i).c_str()));
                    i-=base_digits_count;
                }
            }
        }

        else{
            //Else everything goes to integer part
            size_t i = str.length();
            while (i>0){
                if (i < base_digits_count) {
                    this->_integer_digits.push_back(atoi(str.substr(0, i).c_str()));
                    i = 0;
                }
                else {
                    this->_integer_digits.push_back(atoi(str.substr(i - base_digits_count, i).c_str()));
                    i-=base_digits_count;
                }
            }
            //pushing zero to fractional part
            _fractional_digits.push_back(0);
        }
        this->_remove_leading_zeros();
    }
}

big_double::big_double(double conv_double) {

    _is_negative = std::abs(conv_double) != conv_double;
    conv_double=std::abs(conv_double);
    //Diving to two parts
    unsigned long long integer_digits    = static_cast<unsigned long long>(floor(conv_double));
    double fractional = conv_double;
    unsigned long long fractional_digits=0;
    while (fractional>floor(fractional))
    {
        fractional*=10;
        fractional_digits=fractional_digits*10+static_cast<unsigned long long>(fractional)%10;
    }
    while(integer_digits>0)
    {
        if (ceil(log(integer_digits)/log(10))<base_digits_count)
        {
            _integer_digits.push_back(integer_digits);
            integer_digits=0;
        } else
        {
            _integer_digits.push_back(integer_digits%base);
            integer_digits/=base;
        }
    }
    while(fractional_digits>0)
    {
        if (ceil(log(fractional_digits)/log(10))<base_digits_count)
        {
            _fractional_digits.push_back(fractional_digits);
            fractional_digits=0;
        } else
        {
            _fractional_digits.push_back(fractional_digits%base);
            fractional_digits/=base;
        }
    }
}

void big_double::_remove_leading_zeros() {
    while (this->_integer_digits.size() > 1 && this->_integer_digits.back() == 0) {
        this->_integer_digits.pop_back();
    }
    // to make sure no negative zeros
    if (this->_integer_digits.size() == 1 && this->_integer_digits[0] == 0 && this->_fractional_digits.size() == 1 && this->_fractional_digits[0] == 0) this->_is_negative = false;
}

std::ostream& operator <<(std::ostream& os, const big_double& bd)
{
    //Check for zero
    if (bd._integer_digits.empty()) os << 0.0;
    else {

        //Printing minus if negative
        if (bd._is_negative) os << '-';
        /*
        //we printing with groups by 9 digits, so saving filler, then restore
        char filling = os.fill('0');
        */

        //First, printing integer part
        for (size_t i = bd._integer_digits.size(); i > 0; i--) {
            os << bd._integer_digits[i-1];
        }

        //Then, dot and fractional
        os << '.';
        for (size_t i = bd._fractional_digits.size(); i > 0; i--) {
            os << bd._fractional_digits[i-1];
        }
    }
    return os;
}
/*
std::istream& operator >>(std::istream& is, big_double& value){
    double buffer;
    is>>buffer;
    value._integer_digits.push_back(buffer);
    return is;
}*/