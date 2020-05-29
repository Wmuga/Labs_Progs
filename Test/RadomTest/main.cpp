#include <cmath>
#include <cstdio>
#include <cstdlib>

struct data
{
    char* i;
};

int main() {
    data pepega = {(char*)"pepega"};
    delete []pepega.i;
    pepega.i = nullptr;
    if (!pepega.i) printf("pepega");
    return 0;
}
