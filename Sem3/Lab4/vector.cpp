#include "vector.h"
#include <malloc.h>

std::invalid_argument vector::no_element = std::invalid_argument("vector::unable_to_find_element");

vector::vector():array(nullptr),length(0),element_count(0) {
}

vector::vector(const size_t& new_size):array(nullptr),length(0),element_count(0) {
    reallocate_memory(new_size);
}

void vector::reallocate_memory(const size_t& new_size) {
    long* new_array = (long*)malloc(sizeof(long)*new_size);
    copy(array,element_count,new_array);
    for(size_t i=element_count;i<new_size;i++) new_array[i] = long();
    free(array);
    array=new_array;
    length=new_size;
}

void vector::copy(const long* source,const size_t& source_size,long* new_array) {
    for (size_t i=0;i<source_size;i++){
        new_array[i]=source[i];
    }
}


vector::vector(long* new_array, const size_t& new_size) {
    reallocate_memory(new_size+length_step);
    copy(new_array,new_size,array);
    element_count=new_size;
}

vector::vector(const vector& source):array(nullptr),length(0),element_count(0) {
    *this = source;
}

vector &vector::operator=(const vector& source) {
    if (source.array!=this->array) {
        free(array);
        array = (long *) malloc(source.length * sizeof(long));
        copy(source.array, source.element_count, this->array);
        for (size_t i = source.element_count; i < source.length; i++) this->array[i] = long();
        this->element_count = source.element_count;
        this->length = source.length;
    }
    return *this;
}

vector::~vector() {
    free(array);
}

void vector::push_back(const long& new_element) {
    if (element_count==length)
        reallocate_memory(length + length_step);
    array[element_count]=new_element;
    element_count++;
}

long vector::pop() {
    if (element_count) {
        long value = array[--element_count];
        if (element_count + length_step == length)
            reallocate_memory(element_count);
        return value;
    }
    throw no_element;
}

long &vector::operator[](const size_t& position) {
    if (position>=length) {
        reallocate_memory(position+length_step);
        element_count=position;
    }
    else if (position>=element_count) element_count=position;
    return array[position];
}

vector& vector::operator=(const long& element) {
    *this = vector();
    push_back(element);
    return *this;
}

std::ostream &operator<<(std::ostream& os,const vector& out) {
    os << "{ ";
    for (size_t i=0;i<out.element_count;i++) os << out.array[i] << " ";
    os << "}";
    return os;
}

vector &vector::operator+=(const long& new_element) {
    push_back(new_element);
    return *this;
}

vector& vector::operator-=(const long& decr_element) {
    size_t index = element_count;
    for (size_t i=0; i < element_count && index == element_count; i++)
        if (array[i] == decr_element) index=i;
    if (index == element_count) throw vector::no_element;

    for (size_t i=index;i+1 < element_count; i++)
        array[i]=array[i + 1];
    array[--element_count] = long();
    return *this;
}

vector operator-(const vector& in, const long& decr_element) {
    vector mod_vector = in;
    mod_vector-=decr_element;
    return mod_vector;
}

vector operator+(const vector& in, const long& new_element) {
    vector mod_vector = in;

    mod_vector+=new_element;
    return mod_vector;
}

vector operator*(const vector& in, const long& coeff) {
    vector mod_vector = in;
    mod_vector*=coeff;
    return mod_vector;
}

vector& vector::operator*=(const long& coeff) {
    for (size_t i=0;i<element_count;i++) (*this)[i]*=coeff;
    return *this;
}

vector vector::operator--(int) {
    vector temp = *this;
    pop();
    return temp;
}

vector& vector::operator--() {
    pop();
    return *this;
}

vector &vector::operator++() {
    push_back(long());
    return *this;
}

vector vector::operator++(int) {
    vector temp = *this;
    push_back(long());
    return temp;
}

std::istream &operator>>(std::istream& is, vector& new_vector) {
    std::string buffer;
    size_t elements_count;
    is >> buffer;
    elements_count = std::stoul(buffer);
    new_vector = vector(elements_count + vector::length_step);
    for (size_t i = 0; i < elements_count; i++) {
        is >> buffer;
        new_vector += std::stol(buffer);
    }
    return is;
}