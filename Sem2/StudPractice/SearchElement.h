/*
 * Studying practise project
 * Code by Alexander Cherkasov
 * Algorithm by Anton Tatarincev
 * Tested by Anzhelika Altueva
 * Managed by Daria Kulikova
*/

#ifndef STUDPRACTICE_SEARCHELEMENT_H
#define STUDPRACTICE_SEARCHELEMENT_H

#endif //STUDPRACTICE_SEARCHELEMENT_H
#include <string>

typedef double arrayType;
class SearchElement
{
private:
    arrayType* array;
    int seg_start;
    int seg_end;

public:
    SearchElement(arrayType* ar, int start, int end)
    {
        //Инициализация массива, начала и конца сегмента
        array=ar;
        seg_start=start;
        seg_end=end;
    }
    arrayType SearchByKey(arrayType key,int position=0)
    {
        if (!position) position=seg_start;
        if (position!=seg_end+1) return array[position]==key ? key : SearchByKey(key,position+1);
        return 0;
    }
    //На случай, если пользователю понадобится изменить начало, конец и сам массив
    void ChangeSegmentStart(int start) {seg_start=start;}
    void ChangeSegmentEnd(int end) {seg_end=end;}
    void ChangeArray(arrayType* ar) {array=ar;}
};

class SearchMin:SearchElement
{
public:
    arrayType FindMin() {return 1.0;}
};

class SearchMax:SearchElement
{
public:
    arrayType FindMin() {return 1.0;}
};
