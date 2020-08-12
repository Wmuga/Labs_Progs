#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>
#include <thread>

template<class Type>
class quickSort
{
    std::vector<Type>& array;
public:
    void set_array(std::vector<Type>);
    void full_sort();
    void sort_step();
};

#endif //QUICK_SORT_H
