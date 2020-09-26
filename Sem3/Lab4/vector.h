//
// Created by Alex on 19.09.2020.
//

#ifndef LAB4_VECTOR_H
#define LAB4_VECTOR_H
#include <istream>

class vector {
    long* array;
    size_t length;
    size_t element_count;

    static const size_t length_step = 10;

    static std::invalid_argument no_element;
public:
    vector();
    explicit vector(const size_t&);
    vector(long*,const size_t&);
    vector(const vector&);
    ~vector();

    void push_back(const long&);
    long pop();

    friend vector operator+(const vector&,const long&);
    friend vector operator-(const vector&,const long&);
    friend vector operator*(const vector&,const long&);

    vector& operator=(const long&);
    vector& operator+=(const long&);
    vector& operator-=(const long&);
    vector& operator*=(const long&);

    long& operator[](const size_t&);

    vector& operator++();
    vector operator++(int);

    vector& operator--();
    vector operator--(int);

    friend std::ostream& operator<<(std::ostream&,const vector&);
    friend std::istream& operator>>(std::istream&,vector&);

    vector& operator=(const vector&);
private:
    void reallocate_memory(const size_t&);

    static void copy(const long*,const size_t&,long*);
};

#endif //LAB4_VECTOR_H