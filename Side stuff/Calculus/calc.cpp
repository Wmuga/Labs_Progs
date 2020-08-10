//
// Created by Alex on 09.08.2020.
//

#include "calc.h"
#include <algorithm>
#include <iostream>
#include <cctype>

calculator::calculator(const std::string& sin):iteration(0) {
    for (const std::string& str : split_by(sin,';')) {
        _sin.str(to_lower(str));
        if (iteration==0 && !str.empty()) set_variables();
        if (iteration) calculate();
        iteration++;
    }
}



double calculator::get_value() {
    if (isalpha(_sin.get())) {_sin.unget(); return variables[get_name()];}
    _sin.unget();
    std::string buffer_value;
    while(std::find(act_symbols,act_symbols+6,_sin.get())==act_symbols+6 and !_sin.eof())
    {
        _sin.unget();
        char symb = _sin.get();
        if (!isalpha(symb)) buffer_value+=symb;
        else
        {
            _sin.unget();
            break;
        }
    }
    return atof(buffer_value.c_str());
}

double calculator::get_prev_value(std::string in) {
    if (isalpha(*in.rbegin())) return variables[get_prev_name(in)];
    std::string buffer_value;
    for (auto it = in.rbegin(); it<in.rend();it++)
    {
        if (std::find(act_symbols,act_symbols+6,*it)==act_symbols+6) break;
        buffer_value+=*it;
    }
    return atof(buffer_value.c_str());
}

std::string calculator::get_name()
{
    std::string name;
    while(std::find(act_symbols,act_symbols+6,_sin.get())==act_symbols+6 and !_sin.eof())
    {
        _sin.unget();
        name+=(char)_sin.get();
    }
    _sin.unget();
    return name;
}

std::string calculator::get_prev_name(std::string in)
{
    std::string name;
    for (auto it = in.rbegin(); it<in.rend();it++)
    {
        if (std::find(act_symbols,act_symbols+6,*it)==act_symbols+6) break;
        name+=*it;
    }
    return name;
}

std::vector<std::string> calculator::split_by(const std::string& in,char delim) {
    std::vector<std::string> str_ar;
    std::string acts;
    for (char c : in)
    {
        if (c==delim) {str_ar.push_back(acts);acts="";}
        else acts+=c;
    }
    if (!acts.empty()) str_ar.push_back(acts);
    return str_ar;
}

void calculator::calculate() {
    double result=0;
    std::string st; _sin >> st;
    /*while(!_sin.eof())
    {
        //split by * then / then + then -
    }*/
    auto spl1 = split_by(st,'*');
    for (size_t i=0;i<spl1.size();i++) {

    }
    std::string res = "result"; res+=((char)iteration+'0');
    std::cout << res<< " = " << result<<std::endl;
    variables[res] = result;
}

void calculator::set_variables() {
    while(!_sin.eof())
    {
        std::string name = get_name();
        _sin.get();
        variables[name] = get_value();
        std::clog << name << "=" << variables[name]<<std::endl;
    }
}

std::string calculator::to_lower(const std::string& str_in) {
    std::string res;
    for (char c : str_in) {
        res += (isalpha(c)) ? tolower(c) : c;
    };
    return res;
}

calculator::~calculator() = default;
