/*
 * 1. Я написал интерфейс, кмк он должен выглядеть.
 * 2. Кмк лучше переменные будут называться более громоздко, но код будет самокоментируюшимся
 * 3. Кмк лучше для переменных номеров вершин, начала и концов отрезков лучше использовать size_t
 * 4. Начальный массив придется хранить т.к. неизвестно как изменение аргумента function1 влияет
 * на ее значение
 * 5. Также я накинул еще обновления подотрезка и обновление через функции, если я слишком усложняю
 * напишите об этом.
 */

/*
 * Studying practise project
 * Code by Alexander Cherkasov
 * Algorithm by Anton Tatarintsev
 * Tested by Anzhelika Altueva
 * Managed by Daria Kulikova
*/

//Функциональный тип, в конструктор
//min,sum,max,nElems
#include <cstring>
template <typename StartArrayType, typename ArrayType>
class SearchElement
{
private:
    StartArrayType* _start_array;
    ArrayType* _array;

    ArrayType (*_function1)(StartArrayType);
    ArrayType (*_function2)(ArrayType, ArrayType);

    size_t _size;

    // функия создания
    void build(ArrayType* array[],
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
    SearchElement(StartArrayType* start_array[], size_t array_size,
                  ArrayType (*function1)(StartArrayType),
                  ArrayType (*_function2)(ArrayType, ArrayType));

    // деструктор
    ~SearchElement();

    // поиск по подотрезку
    ArrayType search(const size_t begin, const size_t end);

    //изменение подотрзка
    void change_with_new_value(size_t begin_changed_sub_section,
                               size_t end_changed_sub_section,
                               StartArrayType new_value);

    //изменение подотрзка (то же самое с типами
    void change_with_function(size_t begin_changed_sub_section,
                              size_t end_changed_sub_section,
                              /*
                               * эта функция будет обновлять элементы применяя функцию к элементам
                               * начального массива
                               */
                              StartArrayType (*function3)(StartArrayType));
};