#include <fstream>
#include <vector>
#include "task_functions.hpp"
#include <map>

template<class T>
std::istream &operator>>(std::istream& is, std::vector<T>& new_vector) {
    size_t size;
    is>>size;
    new_vector = std::vector<T>();
    for (size_t i=0;i<size;i++){
        T buf;
        is>>buf;
        new_vector.push_back(buf);
    }
    return is;
}

template<class T>
std::ostream& operator<<(std::ostream& os,const std::vector<T>& v){
    os << "{ ";
    for (const auto& item :v) os << item << " ";
    os << "}";
    return os;
}

template<class T>
void generate_vector(std::vector<T>& v) {
    const double max_number = 15;

    size_t vector_size = rand()%10;
    v = std::vector<T>();
    for (size_t i=0;i<vector_size;i++){
        double value = (double)rand()/RAND_MAX*max_number * (rand()%2 ? 1 : -1);
        v.push_back(static_cast<T>(value));
    }
}

template<class T>
void get_vector(std::ostream& os,std::istream& is,std::vector<T>& v) {
    size_t size;
    is >> size;
    v = std::vector<T>();
    for (size_t i = 0; i < size; i++) {
        T num;
        is>>num;
        v.push_back(num);
    }
}

template<class T>
void test(std::ostream& os,std::istream& is){
    std::map<std::string,short> commands = {{"generate",1},{"type",2},{"sum",3},{"mult",4},{"sort",5},{"switch",6},{"exit",7}};
    bool go =true;
    std::vector<T> v;
    while(go){
        std::string buff;
        is>>buff;
        int command = commands[buff];
        switch (command) {
            default:
                std::cout << "Unknown command\n";
                break;
            case(1):
                generate_vector(v);
                os<< "Current array\n" << v << std::endl;
                break;
            case(2):
                get_vector(os,is,v);
                os<< "Current array\n" << v << std::endl;
                break;
            case(3):
                os << "Sum of negative elements in array:" << sumOfNegative(v) << std::endl;
                break;
            case(4):
                try {
                    os << "Result of multiplication of elements between min and max:"  << mulFromMinToMax(v) << std::endl;;
                } catch (std::exception& error) {
                    os << error.what() << std::endl;
                }
                break;
            case(5):
                bubbleSort(v);
                os<< "Current array\n" << v << std::endl;
                break;
            case(6):
                break;
            case(7): go=false;
        }
    }

}
