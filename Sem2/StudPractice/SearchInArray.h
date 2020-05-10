
/*
 * Studying practise project
 * Code by Alexander Cherkasov
 * Algorithm by Anton Tatarintsev
 * Tested by Anzhelika Altueva
 * Managed by Daria Kulikova
*/

//min,sum,max,nElems
#include <cstring>
#include <algorithm>

template <class StartArrayType, class ArrayType>
class SearchElement
{
private:
    StartArrayType* _start_array;
    ArrayType* _array;

    ArrayType (*_function1)(StartArrayType);       //?
    ArrayType (*_function2)(ArrayType, ArrayType); //min,max,sum

    size_t _size;

    // функия создания
    void build(ArrayType* array,
               size_t current_peak,
               size_t begin_sub_section,
               size_t end_sub_section);

    //функция обновления вершины
    void update(size_t current_peak,
                size_t begin_current_sub_section,
                size_t end_current_sub_section,
                size_t change_peak,
                StartArrayType new_value);
/*
    // можно добавить обновление подотрезка, тогда возможно,
    // предудущую функцию можно заменить на следующую
    void update(size_t current_peak,
                size_t begin_sub_section,
                size_t end_sub_section,
                size_t begin_changed_sub_section,
                size_t end_changed_sub_section,
                StartArrayType new_val);
*/
    //функция обновления вершины
    void update(size_t current_peak,
                size_t begin_current_sub_section,
                size_t end_current_sub_section,
                size_t change_peak,
                StartArrayType (*function3)(StartArrayType));
/*
    // можно добавить обновление подотрезка, тогда возможно,
    // предудущую функцию можно заменить на следующую
    void update(size_t current_peak,
                size_t begin_sub_section,
                size_t end_sub_section,
                size_t begin_changed_sub_section,
                size_t end_changed_sub_section,
                StartArrayType (*function3)(StartArrayType));
*/
public:
    // конструктор
    SearchElement(StartArrayType* start_array, size_t array_size,
                  ArrayType (*function1)(StartArrayType),
                  ArrayType (*function2)(ArrayType, ArrayType));

    // деструктор
    ~SearchElement();

    // поиск по подотрезку
    ArrayType search(size_t current_peak, size_t search_start, size_t search_end, size_t current_start, size_t current_end);

    //изменение подотрзка
    void change_with_new_values(size_t begin_changed_sub_section,
                                size_t end_changed_sub_section,
                                StartArrayType *new_value);

    //изменение подотрзка (то же самое с типами
    void change_with_function(size_t begin_changed_sub_section,
                              size_t end_changed_sub_section,
                              /*
                               * эта функция будет обновлять элементы применяя функцию к элементам
                               * начального массива
                               */
                              StartArrayType (*function3)(StartArrayType));
};


template<typename StartArrayType,typename ArrayType>
SearchElement<StartArrayType,ArrayType>::SearchElement(StartArrayType* start_array, size_t array_size,
                                                       ArrayType (*function1)(StartArrayType),
                                                       ArrayType (*function2)(ArrayType, ArrayType))
{
    _start_array=start_array;
    _size = array_size;
    _function1=function1;
    _function2=function2;
    _array = new ArrayType[array_size];
    build(start_array,1,0,_size-1);
}


template<typename StartArrayType,typename ArrayType>
SearchElement<StartArrayType,ArrayType>::~SearchElement()
{
    //delete []_start_array;
    //delete[]_array;
}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::build(ArrayType* array,
        size_t current_peak,
        size_t begin_sub_section,
        size_t end_sub_section)
{
    if (begin_sub_section==end_sub_section) _array[current_peak] = array[begin_sub_section];

    else{
        size_t middle = (begin_sub_section + end_sub_section) / 2;

        build(array, current_peak*2,begin_sub_section,middle);
        build(array, current_peak*2+1,middle+1,end_sub_section);
        _array[current_peak]=_array[current_peak*2]+_array[current_peak*2+1];
    }
}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::update(size_t current_peak,
        size_t begin_current_sub_section,
        size_t end_current_sub_section,
        size_t change_peak,
        StartArrayType new_value)
{
    if (begin_current_sub_section==end_current_sub_section) _array[current_peak] = new_value;
    else{
        size_t middle = (begin_current_sub_section + end_current_sub_section)/2;
        change_peak<=middle ? update(current_peak*2,begin_current_sub_section,middle,change_peak,new_value)
                            : update(current_peak*2+1,middle+1,end_current_sub_section,change_peak,new_value);
        _array[current_peak]=_array[current_peak*2]+_array[current_peak*2+1];
    }

}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::update(size_t current_peak,
        size_t begin_current_sub_section,
        size_t end_current_sub_section,
        size_t change_peak,
        StartArrayType (*function3)(StartArrayType))
{
    if (begin_current_sub_section==end_current_sub_section) _array[current_peak] = function3(_array[current_peak]);

    else{
        size_t middle = (begin_current_sub_section + end_current_sub_section)/2;
        change_peak<=middle ? update(current_peak*2,begin_current_sub_section,middle,change_peak,function3)
        : update(current_peak*2+1,middle+1,end_current_sub_section,change_peak,function3);
        _array[current_peak]=_array[current_peak*2]+_array[current_peak*2+1];
    }
}

//Применение функции
template<typename StartArrayType,typename ArrayType>
ArrayType SearchElement<StartArrayType,ArrayType>::search(size_t current_peak, size_t search_start, size_t search_end, size_t current_start, size_t current_end) {
    if (search_start > search_end) return 0;
    if (current_start == search_start && current_end == search_end) return _array[current_peak];
    size_t middle = (current_start + current_end) / 2;
    ArrayType val1 = search(current_peak*2, search_start, std::min(search_end,middle),current_start,middle);
    ArrayType val2 = search(current_peak*2+1, std::max(search_start,middle+1), search_end,middle+1,current_end);
    if (val1==0 && _array[current_peak*2]!=0) return val2;
    if (val2==0 && _array[current_peak*2+1]!=0) return val1;
    return _function2(val1,val2);
}

//Изменения
template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_with_new_values(size_t begin_changed_sub_section, size_t end_changed_sub_section, StartArrayType *new_values)
{
    for (int position=0; position<=end_changed_sub_section-begin_changed_sub_section; position++) update(1, 0, _size-1, begin_changed_sub_section+position, new_values[position]);
}

template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_with_function(size_t begin_changed_sub_section, size_t end_changed_sub_section, StartArrayType (*function3)(StartArrayType))
{
    for (int position=0; position<=end_changed_sub_section-begin_changed_sub_section; position++) update(1, 0, _size-1, begin_changed_sub_section+position, function3);
}