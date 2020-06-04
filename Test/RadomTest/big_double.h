/*
 * Created by Alex on 03.06.2020.
 * Guided by realization of big_int by hatred1993 from habr.com
*/
#ifndef BIG_DOUBLE
#define BIG_DOUBLE 1
#endif

#pragma once

#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

class big_double{
    //System base
    static const int base = 1000000;
    const size_t base_digits_count = ceil(log(base)/log(10));

    //container for integer and fractional parts
    std::vector<int> _integer_digits;
    std::vector<int> _fractional_digits;

    //is the number negative
    int _is_negative;

    void _remove_leading_zeros();
public:
    // exception if dividing by zero
    class divide_by_zero: public std::exception {  };
    //constructors
    big_double();
    big_double(std::string);
    big_double(signed char);
    big_double(unsigned char);
    big_double(signed short);
    big_double(unsigned short);
    big_double(signed int);
    big_double(unsigned int);
    big_double(signed long);
    big_double(unsigned long);
    big_double(signed long long);
    big_double(unsigned long long);
    big_double(double);
    //Put in stream
    friend std::ostream& operator <<(std::ostream&, const big_double&);
    operator std::string() const;
};