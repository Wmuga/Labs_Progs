#pragma once
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
#include "binary_tree.h"

enum actions { VAR = 0, SUM = '+', SUB = '-', DIV = '/', MUL = '*' };

struct var {
    actions act;
    double val;
};

ref class calculator
{
   
public:
    calculator(const std::string&,std::ostream&);
    ~calculator();

private:
    void calculate();
    std::string get_name();
    void set_variables();
    double get_value();
    std::vector<std::string> split_by(const std::string&, char);
    std::string to_lower(const std::string& str_in);
    void build_tree();
    double tree_get(binary_tree<var>::leaf);

    std::map<std::string, double>* variables;
    char* act_symbols = (char*)"_+-*/=";
    size_t iteration;
    std::stringstream* _sin;
    std::ostream& out_stream;

    binary_tree<var> tree;
    actions cur_act;
};

