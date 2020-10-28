#include "tInt.h"
#include <malloc.h>

tInt::tInt() {
    value = (int*)malloc(sizeof(int));
    *value = 0;
}

tInt::tInt(const int& start_value) {
    value = (int*)malloc(sizeof(int));
    *value = start_value;
}

tInt& tInt::operator++() {
    ++(*value);
    return *this;
}

tInt tInt::operator++(int) {
    tInt temp(*this->value);
    (*value)++;
    return temp;
}

tInt &operator--(tInt& in) {
    --(*in.value);
    return in;
}

tInt operator--(tInt& in, int) {
    tInt temp(*in.value);
    (*in.value)--;
    return temp;
}

tInt::~tInt() {
    free(value);
}

std::ostream& operator<<(std::ostream& os,const tInt& out) {
    os << *out.value;
    return os;
}
