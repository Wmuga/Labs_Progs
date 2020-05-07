//
// Created by Alex on 07.05.2020.
//
#include "SearchInArray.h"
SearchElement::SearchElement(StartArrayType* start_array[], size_t array_size,
                             ArrayType (*function1)(StartArrayType),
                             ArrayType (*_function2)(ArrayType, ArrayType)
{
    _start_array=start_array;

}

SearchElement::~SearchElement
{

};

SearchElement::build(ArrayType* array[],
        size_t current_peak,
        size_t begin_sub_section,
        size_t end_sub_section)
{

}