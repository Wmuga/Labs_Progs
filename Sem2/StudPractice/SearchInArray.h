
/*
 * Studying practise project
 * Code by Alexander Cherkasov
 * Algorithm by Anton Tatarintsev
 * Tested by Anzhelika Altueva
 * Managed by Daria Kulikova
*/

//min,sum,max,nElems
#include <cstring>
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
    ArrayType search(const size_t begin, const size_t end);

    //изменение подотрзка
    void change_with_new_value(size_t begin_changed_sub_section,
                               size_t end_changed_sub_section,
                               StartArrayType* new_value);

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
    build(start_array,1,0,0);
}


template<typename StartArrayType,typename ArrayType>
SearchElement<StartArrayType,ArrayType>::~SearchElement()
{
    //delete []_start_array;
    delete []_array;
}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::build(ArrayType* array,
        size_t current_peak,
        size_t begin_sub_section,
        size_t end_sub_section)
{
    if (begin_sub_section==end_sub_section) _array[begin_sub_section] = array[begin_sub_section];

    else{
        int middle = (begin_sub_section + end_sub_section) / 2;

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
    if (begin_current_sub_section==end_current_sub_section) _array[begin_current_sub_section] = new_value;

    else{
        int middle = (begin_current_sub_section + end_current_sub_section) / 2;
        change_peak<=middle ? update(current_peak*2,begin_current_sub_section,middle,change_peak,new_value) : update(current_peak*2,middle+1,end_current_sub_section,change_peak,new_value);

    }
    _array[current_peak]=_array[current_peak*2]+_array[current_peak*2+1];
}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::update(size_t current_peak,
        size_t begin_current_sub_section,
        size_t end_current_sub_section,
        size_t change_peak,
        StartArrayType (*function3)(StartArrayType))
{
    if (begin_current_sub_section==end_current_sub_section) _array[begin_current_sub_section] = function3( _array[begin_current_sub_section]);

    else{
        int middle = (begin_current_sub_section + end_current_sub_section)/2;
        change_peak<=middle ? update(current_peak*2,begin_current_sub_section,middle,change_peak,function3) : update(current_peak*2,middle+1,end_current_sub_section,change_peak,function3);

    }
    _array[current_peak]=_array[current_peak*2]+_array[current_peak*2+1];
}

//Применение функции
template<typename StartArrayType,typename ArrayType>
ArrayType SearchElement<StartArrayType,ArrayType>::search(const size_t begin, const size_t end) {

}

//Изменения
template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_with_new_value(size_t begin_changed_sub_section, size_t end_changed_sub_section, StartArrayType *new_value)
{
    for (int position=begin_changed_sub_section; position<end_changed_sub_section; position++) update(1, 0, 0, position, new_value[position]);
}

template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_with_function(size_t begin_changed_sub_section, size_t end_changed_sub_section, StartArrayType (*function3)(StartArrayType))
{
    for (int position=begin_changed_sub_section; position<end_changed_sub_section; position++) update(1, 0, 0, position, function3);
}