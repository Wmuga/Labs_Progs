#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <iomanip>

#define get_func_collisions(hash_throw,hash_func,key_array,array_size) std::cout << "Function " << #hash_func << "\n"; hash_throw(hash_func,key_array,array_size)

typedef unsigned long long key_type;

size_t hash1(std::string,size_t);
size_t hash2(std::string,size_t);

void hash_throw(size_t (*hashfunc)(std::string,size_t), std::string key[],size_t max_size) {
    std::set<size_t> hkeys;
    for (int i = 0; i < max_size; i++) {
        std::cout<< std::setw(ceil(log(max_size)/log(10))) << std::right << std::setfill(' ')<<hashfunc(key[i],max_size) << "|";
        hkeys.emplace(hashfunc(key[i],max_size));
    }
    std::cout << "\ncollisions: " << max_size-hkeys.size() << "\n\n";
}

int main() {
    size_t ar_s = 5;
    std::string key[] = {"abc","acb","bac","bca","cab","cba","Absolutely","bbb","Behold","Kermit","Karmik"};

    get_func_collisions(hash_throw,hash1,key,ar_s);
    get_func_collisions(hash_throw,hash2,key,ar_s);

    return 0;
}

size_t hash1(std::string value,size_t max_size)
{
    key_type hash_key=0;
    for (char c : value)
    {
        hash_key=(hash_key*128)+(int)c;
    }
    size_t hash_key_size = ceil(log(hash_key)/log(2));
    hash_key*=2; hash_key^=hash_key_size;
    return hash_key%max_size;
}

size_t hash2(std::string value,size_t max_size)
{
    key_type hash_key=0;
    for (auto c = value.rbegin();c<value.rend();c++)
    {
        hash_key=(hash_key*256)+(int)*c;
    }
    size_t hash_key_size = ceil(log(hash_key)/log(2));
    hash_key*=2; hash_key^=hash_key_size;
    return hash_key%max_size;
}
