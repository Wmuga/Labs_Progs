#pragma once
#include<string>
#include<stdexcept>
#include<cmath>

namespace converter{

	double stod(const std::string&,const int&);
	int stoi(const std::string&, const int&);
	std::string itos(const int&, const int&);
	std::string dtos(const double&, const int&);

	namespace {
		int convert_integer(const std::string& in, const int& radix) {
			int result = 0;
			bool isNegative = false;
			for (size_t i = 0; i < in.size(); i++) {
				const char& buffer = in[i];
				if (buffer == '-' && i==0) isNegative = true;
				else {
					int cur;
					if (buffer != '0') 
					{
						if (isdigit(buffer)) {
							cur = static_cast<int>(buffer - '0');
							if (cur >= radix) throw(std::invalid_argument("Wrong Argument"));
						}
						else if (isalpha(buffer)){
							cur = static_cast<int>(tolower(buffer) - 'a') + 10;
							if (cur >= radix) throw(std::invalid_argument("Wrong Argument"));
						}
						else throw(std::invalid_argument("Wrong Argument"));
						result += static_cast<int>(cur * pow(radix, in.size() - 1 - i));
					}
				}
			}
			if (isNegative) result *= -1;
			return result;
		}

		double convert_fractional(const std::string& in, const int& radix) {
			double res = 0.0;
			for (size_t i = 0; i < in.size(); i++) {
				char buffer = in[i];
				double cur;
				if (buffer != '0')
				{
					if (isdigit(buffer)) {
						cur = static_cast<int>(buffer - '0');
						if (cur >= radix) throw(std::invalid_argument("Wrong Argument"));
					}
					else if (isalpha(buffer)) {
						cur = static_cast<int>(tolower(buffer) - 'a') + 10;
						if (cur >= radix) throw(std::invalid_argument("Wrong Argument"));
					}
					else throw(std::invalid_argument("Wrong Argument"));
					res += cur / pow(radix, in.size() - 1 - i);
				}
			}
			return res/pow(10,
			        ceil(log(res)/log(10))+1);
		}

		static bool isI;

		static bool isIPart(const char& c) {
			if (c == '.') isI = false;
			return isI;
		}
	}
};

