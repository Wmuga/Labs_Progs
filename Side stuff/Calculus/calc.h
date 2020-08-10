//
// Created by Alex on 09.08.2020.
//

#ifndef CALCULUS
#define CALCULUS


#include <map>
#include <fstream>
#include <vector>
#include <sstream>

class calculator{
    std::map<std::string,double> variables;
    char* act_symbols = (char*)"_+-*/=";
    double current_out=0;
    size_t iteration;
    std::stringstream _sin;
public:
    calculator(const std::string&);
    ~calculator();

private:
    void calculate();
    std::string get_name();
    std::string get_prev_name(std::string);
    void set_variables();
    double get_value();
    double get_prev_value(std::string);
    std::vector<std::string> split_by(const std::string&,char);
    std::string to_lower(const std::string& str_in);
};

#endif //CALCULUS_CALC_H
