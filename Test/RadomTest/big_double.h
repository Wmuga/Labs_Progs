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

    const static size_t base = 1000000;
    const size_t base_digits_count = ceil(log(base)/log(10));
    //container for integer and fractional parts
    std::vector<long long> _integer_digits;
    std::vector<long long> _fractional_digits;

    //is the number negative
    int _is_negative;

    void _remove_leading_zeros();

    void fix_containtment();
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
    big_double(float);
    //Working with stream
    friend std::ostream& operator <<(std::ostream&, const big_double&);
    friend std::istream& operator >>(std::istream&, big_double&);
    //bool operators
    friend bool operator ==(const big_double&, const big_double&);
    friend bool operator  <(const big_double&, const big_double&);
    friend bool operator !=(const big_double&, const big_double&);
    friend bool operator <=(const big_double&, const big_double&);
    friend bool operator  >(const big_double&, const big_double&);
    friend bool operator >=(const big_double&, const big_double&);
    //assignment
    big_double& operator =(const big_double&);
    //
    const big_double operator +() const;
    const big_double operator -() const;
    //Increment amd decrement
    const big_double operator ++();
    const big_double operator ++(int);
    const big_double operator --();
    const big_double operator --(int);
    //compound assignment
    big_double& operator +=(const big_double&);
    big_double& operator -=(const big_double&);
    big_double& operator *=(const big_double&);
    big_double& operator /=(const big_double&);
    big_double& operator %=(const big_double&);
    //arithmetic operators
    friend const big_double operator +(const big_double&, const big_double&);
    friend const big_double operator -(big_double, const big_double&);
    friend const big_double operator *(const big_double&, const big_double&);
    friend const big_double operator /(const big_double&, const big_double&);
    friend const big_double operator %(const big_double&, const big_double&);
    //absolute value
    friend big_double abs(const big_double&);
    /*
     * currently missing
     */
    //conv to string
    operator std::string() const;
};