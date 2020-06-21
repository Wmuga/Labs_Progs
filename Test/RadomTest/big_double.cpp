//
// Created by Alex on 03.06.2020.
//

#include "big_double.h"

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
                //If there's smaller then base_digits_count digits, pushing them all
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
    unsigned long long integer_digits = static_cast<unsigned long long>(floor(conv_double));
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
            while (fractional_digits<base) fractional_digits*=10;
            _fractional_digits.push_back(fractional_digits);
            fractional_digits=0;
        } else
        {
            _fractional_digits.push_back(fractional_digits%base);
            fractional_digits/=base;
        }
    }
}

big_double::big_double(float conv_float)
{
    big_double buffer = big_double(static_cast<double>(conv_float));
    this->_integer_digits=(buffer._integer_digits);
    this->_fractional_digits=buffer._fractional_digits;
    this->_is_negative=buffer._is_negative;
}

big_double::big_double(signed int conv_int)
{
    big_double buffer = big_double(static_cast<double>(conv_int));
    this->_integer_digits=(buffer._integer_digits);
    this->_fractional_digits=buffer._fractional_digits;
    this->_is_negative=buffer._is_negative;
}

big_double::big_double(unsigned int conv_int)
{
    big_double buffer = big_double(static_cast<signed>(conv_int));
    this->_integer_digits=(buffer._integer_digits);
    this->_fractional_digits=buffer._fractional_digits;
    this->_is_negative=buffer._is_negative;
}

big_double& big_double::operator =(const big_double& external)
{
    _integer_digits = external._integer_digits;
    _fractional_digits= external._fractional_digits;
    _is_negative = external._is_negative;
    return *this;
}

//Making two of the bool operators standalone, other will work using them

bool operator ==(const big_double& first, const big_double& second)
{
    return (first._is_negative==second._is_negative and
    first._fractional_digits==second._fractional_digits and
    first._integer_digits==second._integer_digits);
}

bool operator !=(const big_double& first, const big_double& second)
{
    return !(first==second);
}

bool operator <(const big_double& first, const big_double& second)
{
    if (first._is_negative>second._is_negative) return false;
    if (first._is_negative<second._is_negative) return true;
    if (first._integer_digits.size() > second._integer_digits.size()) return false;
    if (first._integer_digits.size() < second._integer_digits.size()) return true;
    for (size_t i =first._integer_digits.size()-1; i>=0;i--)
    {
        if (first._integer_digits[i]>second._integer_digits[i]) return false;
        if (first._integer_digits[i]<second._integer_digits[i]) return true;
    }
    for (size_t i = 0; i<std::min(first._fractional_digits.size(),second._fractional_digits.size());i++)
    {
        if (first._fractional_digits[i]>=second._fractional_digits[i]) return false;
    }
    return true;
}

bool operator <=(const big_double& first, const big_double& second)
{
    return ((first<second) or (first==second));
}

bool operator >(const big_double& first, const big_double& second)
{
    return (!(first<second) and (first!=second));
}

bool operator >=(const big_double& first, const big_double& second)
{
    return !(first<second);
}

//Streams
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
            int fractional_digit = bd._fractional_digits[i-1];
            while (i==1 and fractional_digit%10==0) fractional_digit/=10;
            os << fractional_digit;
        }
    }
    return os;
}
std::istream& operator >>(std::istream& is, big_double& value) {
    double buffer;
    is >> buffer;
    value = big_double(buffer);
    return is;
}

//arithmetic operators

const big_double operator +(const big_double& first, const big_double& second){
    big_double value;
    //if (first._is_negative or second._is_negative) return first-second;
    value._is_negative=0;
    if (first._fractional_digits.size()<second._fractional_digits.size())
    {
        value._fractional_digits = second._fractional_digits;
        for (size_t i=0;i<first._fractional_digits.size();i++)
            value._fractional_digits[i]+=first._fractional_digits[i];
    } else{
        value._fractional_digits = first._fractional_digits;
        for (size_t i=0;i<second._fractional_digits.size();i++)
            value._fractional_digits[i]+=second._fractional_digits[i];
    }
    if (first._integer_digits.size()<second._integer_digits.size())
    {
        value._integer_digits = second._integer_digits;
        for (size_t i=0;i<first._integer_digits.size();i++)
            value._integer_digits[i]+=first._integer_digits[i];
    } else
    {
        value._integer_digits = first._integer_digits;
        for (size_t i=0;i<second._integer_digits.size();i++)
            value._integer_digits[i]+=second._integer_digits[i];
    }
    value.fix_containtment();
    return value;
}
big_double abs(const big_double& value) {
    big_double abs_value = value;
    abs_value._is_negative = 0;
    return abs_value;
}
void big_double::_remove_leading_zeros() {
    while (this->_integer_digits.size() > 1 && this->_integer_digits.back() == 0) {
        this->_integer_digits.pop_back();
    }
    // to make sure no negative zeros
    if (this->_integer_digits.size() == 1 && this->_integer_digits[0] == 0 && this->_fractional_digits.size() == 1 && this->_fractional_digits[0] == 0) this->_is_negative = false;
}
//Check for containtemnt more than base
void big_double::fix_containtment() {
    int excess_value=0;
    for (auto _fractional_digit=_fractional_digits.end();_fractional_digit!=_fractional_digits.begin();_fractional_digit--)
    {
        *_fractional_digit+=excess_value;
        excess_value=*_fractional_digit/(int)base;
        *_fractional_digit%=base;
    }
    for (size_t i=0;i<_integer_digits.size();i++)
    {
        _integer_digits[i]+=excess_value;
        excess_value=_integer_digits[i]/(int)base;
        _integer_digits[i]%=base;
    }
    while (excess_value) {
        _integer_digits.push_back(excess_value);
        excess_value=*_integer_digits.end()/(int)base;
        *_integer_digits.end()%=base;
    }
}