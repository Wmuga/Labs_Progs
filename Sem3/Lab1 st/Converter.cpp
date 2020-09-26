#include "Converter.h"
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cctype>

double converter::stod(const std::string& in, const int& radix)
{
    isI = true;
    std::string iPart,fPart;
    std::partition_copy(in.begin(), in.end(), std::back_inserter(iPart), std::back_inserter(fPart),isIPart);
    if (iPart.empty()) iPart = "0";
    if (fPart.empty()) fPart = ".0";
    fPart = fPart.substr(1,fPart.size()-1);
    double f1 = static_cast<double>(convert_integer(iPart, radix));
    double f2= convert_fractional(fPart, radix);
    return (std::abs(f1)==f1) ? f1+f2 : f1-f2;
}

int converter::stoi(const std::string& in, const int& radix) {
    return convert_integer(in,radix);
}

std::string converter::itos(const int& in, const int& radix) {
    if (in == 0) return "0";
    char* res = new char[256];
    itoa(std::abs(in), res, radix);
    std::string result = res;
    delete []res;
    if (std::abs(in) != in) result = '-' + result;
    return result;
}

std::string converter::dtos(const double& in, const int& radix) {
    int iPart = (double)static_cast<int>(in);

    std::string result = itos(iPart, radix);

    if (static_cast<double>(iPart) != in) {
        result += '.';
        double fPart = (in - static_cast<double>(iPart));
        while (static_cast<int>(fPart * radix) != 0) {
            int cur = static_cast<int>(fPart * radix); 
            if (cur >= 10) cur = cur - '0' + 'A';
            result += cur + '0';
            fPart = fPart * radix - (double)static_cast<int>(fPart * radix);
        }
    }
    return result;
}