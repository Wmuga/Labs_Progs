#ifndef LAB5_TASK_FUNCTIONS_HPP
#define LAB5_TASK_FUNCTIONS_HPP
#include <vector>
#include <algorithm>
#include <cmath>


template<class T>
T sumOfNegative(const std::vector<T>&);

template<class T>
T mulFromMinToMax(const std::vector<T>&);

template<class T>
void bubbleSort(std::vector<T>&);

template<class T>
T sumOfNegative(const std::vector<T>& array){
    T sum = 0;
    for (const T& item:array) if (item<0) sum+=item;
    return sum;
}

template<class T>
T mulFromMinToMax(const std::vector<T>& array){
    if (array.empty()) throw std::runtime_error("no_elements");

    auto minElementIterator = std::min_element(array.begin(),array.end());
    auto maxElementIterator = std::max_element(array.begin(),array.end());

    size_t minElementIndex = std::distance(array.begin(),minElementIterator);
    size_t maxElementIndex = std::distance(array.begin(),maxElementIterator);

    if(std::abs((int)minElementIndex-(int)maxElementIndex)<=1) throw std::runtime_error("min_and_max_too_close");

    T mult = 1;

    for (size_t i = std::min(minElementIndex,maxElementIndex)+1;i<std::max(minElementIndex,maxElementIndex);i++)
        mult*=array[i];
    return mult;
}

template<class T>
void bubbleSort(std::vector<T>& array){
    if (!array.empty()) {
        size_t start = 0, end = array.size();
        bool isChanged =true;

        while (isChanged && start != end) {
            isChanged = false;

            for (size_t i = start++; i < end-1; i++) {
                if (array[i]>array[i+1]) {
                    T temp = array[i];
                    array[i]=array[i+1];
                    array[i+1] = temp;
                    isChanged=true;
                }
            }

            for (size_t i = --end-1; i >= start && isChanged; i--) {
                if (array[i-1]>array[i]) {
                    T temp = array[i];
                    array[i]=array[i-1];
                    array[i-1] = temp;
                    isChanged= true;
                }
            }
        }
    }
    else{
        throw std::invalid_argument("empty_array");
    }
}

#endif //LAB5_TASK_FUNCTIONS_HPP
