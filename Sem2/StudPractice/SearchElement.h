/*
 * Studying practise project
 * Code by Alexander Cherkasov
 * Algorithm by Anton Tatarincev
 * Tested by Anzhelika Altueva
 * Managed by Daria Kulikova
*/

//Функциональный тип, в конструктор
//min,sum,max,nElems

template <typename arrayType>
class SearchElement
{
private:
    arrayType* array;
    int seg_start;
    int seg_end;

    void build (arrayType a[], int v, int tl, int tr) {
        if (tl == tr)
            array[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            array[v] = array[v*2]+array[v*2+1];
        }
    }

    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            array[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            array[v] = array[v*2] + array[v*2+1];
        }
    }

public:
    SearchElement(arrayType* ar,int length, int start, int end)
    {
        //Инициализация массива, начала и конца сегмента
        seg_start=start;
        seg_end=end;
        array = new arrayType[4*(end-start)];
        build(ar,1,0,length-1);
    }
    ~SearchElement() {delete []array;}
    arrayType SearchMinTree(int v,int sp=0, int ep=0)
    {
        if (sp==ep && sp==0) {sp=seg_start; ep=seg_end;}
        if (sp==ep) return array[sp];
        int mp = (ep+sp)/2;
        return SearchMinTree(v*2,sp,mp)>SearchMinTree(mp+1,ep) ? SearchMinTree(v*2,sp,mp) : SearchMinTree(mp+1,ep);
    }
    //На случай, если пользователю понадобится изменить начало, конец и сам массив
    void ChangeSegment(int start, int end) {
        seg_start=start; seg_end=end;
        //updTree();
    }
    void ChangeArray(arrayType* ar) {array=ar;}
};

/*
//Parse Table
class SearchParse
{
private:
    arrayType* array;
    int seg_start;
    int seg_end;
public:
    SearchParse()
    {}
    ~SearchParse()
    {}
    arrayType FindMin()
    {
    }
};*/