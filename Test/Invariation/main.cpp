#include <iostream>
#include <vector>
#include <set>
template <class T>
class invariants
{
    std::vector<T> vec;
    std::set<std::vector<T> > inv_set;
private:
    void get_all_invariants(size_t pos)
    {
    if (pos!=vec.size()-1)
    {
        for (int it=0;it<=vec.size()-pos;it++)
        {
            inv_set.emplace(vec);
            get_all_invariants(pos+1);
            v_swap(pos+0,pos+1);
            }
        }
    }
    void v_swap( size_t p1, size_t p2){
    T buffer = vec[p1];
    vec[p1]=vec[p2];
    vec[p2] = buffer;
    }

public:
    invariants(std::vector<T> start){
        vec = start;
        get_all_invariants(0);
    }
    void show_ivariants()
    {
        int cnt=1;
        for (std::vector<T> i: inv_set){
            printf("%*d: ",4,cnt);
            for (T j: i) std::cout<<j<<" ";
            std::cout<<std::endl;
            cnt++;
        }
    }
};

int main()
{
    std::vector<int> v = {1,2,3,4,5};
    invariants<int> b(v);
    b.show_ivariants();
    return 0;
}
