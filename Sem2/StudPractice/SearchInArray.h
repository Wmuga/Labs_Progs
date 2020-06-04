/*
 * Studying practise project
 * Code by Alexander Cherkasov
 * Algorithm by Anton Tatarintsev
 * Tested by Anzhelika Altueva
 * Managed by Daria Kulikova
*/

//Необходимые библиотеки
#include <cstring>
#include <algorithm>

template <class StartArrayType, class ArrayType>
class SearchElement
{
private:
    StartArrayType* _start_array; //Входной массив
    ArrayType* _array; //Само древо

    ArrayType (*_function1)(StartArrayType);       //Работа с элементом
    ArrayType (*_function2)(ArrayType, ArrayType); //min,max,sum

    size_t _size;


    // функия создания
    void build(size_t current_peak,
               size_t begin_sub_section,
               size_t end_sub_section);

    //функция обновления вершины
    void update(size_t current_peak,
                size_t begin_current_sub_section,
                size_t end_current_sub_section,
                size_t change_peak,
                StartArrayType new_value);

    std::pair<int,ArrayType> get_value(size_t current_peak, size_t search_start, size_t search_end, size_t current_start, size_t current_end);

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
                              size_t end_changed_sub_section, StartArrayType (*function3)(StartArrayType));
    //Просмотр текущего состояния массива
    void watch_contents();

    //Изменение типа дерева (min,max,sum и т.д.)
    void change_main_function(StartArrayType (*funcTypeTree)(ArrayType,ArrayType));
    //Изменение работы над эелементом
    void change_elem_function(StartArrayType (*funcValueChange)(ArrayType));
};


template<typename StartArrayType,typename ArrayType>
SearchElement<StartArrayType,ArrayType>::SearchElement(StartArrayType* start_array, size_t array_size,
                                                       ArrayType (*function1)(StartArrayType),
                                                       ArrayType (*function2)(ArrayType, ArrayType)):
        _start_array(start_array), _size(array_size),
        _function1(function1), _function2(function2)
{
    _array = new ArrayType[4*array_size];
    build(1,0,_size-1);
}


template<typename StartArrayType,typename ArrayType>
SearchElement<StartArrayType,ArrayType>::~SearchElement()
{
    delete []_start_array;
    delete[]_array;
}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::build(
        size_t current_peak,
        size_t begin_sub_section,
        size_t end_sub_section)
{
    //Если дошли до конкретного элемента, передаем его дереву
    if (begin_sub_section==end_sub_section) _array[current_peak] = _function1(_start_array[begin_sub_section]);

    else{
        //Иначе делим отрезок пополам и запускаем рекурсию
        size_t middle = (begin_sub_section + end_sub_section) / 2;

        build(current_peak*2,begin_sub_section,middle);
        build(current_peak*2+1,middle+1,end_sub_section);
        //Формируем "корень" из "листьев" в соответсвии с переданной функцией
        _array[current_peak]=_function2(_array[current_peak*2],_array[current_peak*2+1]);
    }
}


template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::update(size_t current_peak,
        size_t begin_current_sub_section,
        size_t end_current_sub_section,
        size_t change_peak,
        StartArrayType new_value)
{   //Если дошли до конкретного элемента, передаем его дереву
    if (begin_current_sub_section==end_current_sub_section) _array[current_peak] = _function1(new_value);
    else{
        //Иначе ищем его
        size_t middle = (begin_current_sub_section + end_current_sub_section)/2;
        change_peak<=middle ? update(current_peak*2,begin_current_sub_section,middle,change_peak,new_value)
                            : update(current_peak*2+1,middle+1,end_current_sub_section,change_peak,new_value);
        //Снова формируем дерево, т.к. изменен элемент
        _array[current_peak]=_function2(_array[current_peak*2],_array[current_peak*2+1]);
    }

}


//Применение функции
template<typename StartArrayType,typename ArrayType>
ArrayType SearchElement<StartArrayType,ArrayType>::search(size_t current_peak, size_t search_start, size_t search_end, size_t current_start, size_t current_end) {
    return get_value(current_peak, search_start,search_end,current_start,current_end).second;
}
template<typename StartArrayType,typename ArrayType>
std::pair<int,ArrayType> SearchElement<StartArrayType,ArrayType>::get_value(size_t current_peak, size_t search_start, size_t search_end, size_t current_start, size_t current_end)
{
    //Проверка на аномалию
    if (search_start > search_end) return std::make_pair(1,_array[current_peak]);
    //Дошли до элемента - возвращаем его
    if (current_start == search_start && current_end == search_end) return std::make_pair(0,_array[current_peak]);
    size_t middle = (current_start + current_end) / 2;
    //Рекурсия для поиска необходимого значения
    std::pair<int,ArrayType> val1 = get_value(current_peak*2, search_start, std::min(search_end,middle),current_start,middle);
    std::pair<int,ArrayType> val2 = get_value(current_peak*2+1, std::max(search_start,middle+1), search_end,middle+1,current_end);
    //Дополнительная проверка, чтобы не считали ноль значением "листа" дерева
    if (val1.first==1) return val2;
    if (val2.first==1) return val1;
    //И возвращаем результат function2
    return std::make_pair(0,_function2(val1.second,val2.second));
}

//Изменения
template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_with_new_values(size_t begin_changed_sub_section, size_t end_changed_sub_section, StartArrayType *new_values)
{
    //Циклом проходим по массиву и запускаем update с новыми значениям
    for (size_t position=begin_changed_sub_section; position<=end_changed_sub_section; position++)
    {
        update(1, 0, _size-1, position, new_values[position]);
        _start_array[position]=new_values[position];
    }
}

template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_with_function(size_t begin_changed_sub_section, size_t end_changed_sub_section, StartArrayType (*function3)(StartArrayType))
{
    //Циклом обновляем дерево с помощью функции
    for (size_t position=begin_changed_sub_section; position<=end_changed_sub_section; position++) {
        _start_array[position]=function3(_start_array[position]);
        update(1, 0, _size - 1, position,_start_array[position]);
    }
}
template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::watch_contents(){
    for (size_t i=0;i<_size;i++) std::cout<< _start_array[i] << " ";
    printf("\n");
}

template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_main_function(StartArrayType (*funcTypeTree)(ArrayType,ArrayType))
{
    //Изменяем функцию, по которой определяется "корень" и переформировываем дерево
    _function2=funcTypeTree;
    build(1,0,_size-1);
}

template<typename StartArrayType,typename ArrayType>
void SearchElement<StartArrayType,ArrayType>::change_elem_function(StartArrayType (*funcValueChange)(ArrayType))
{
    //Изменяем функцию для работы с отдельными элементами и переформировываем дерево
    _function1=funcValueChange;
    build(1,0,_size-1);
}