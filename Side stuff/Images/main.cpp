#include "bmp.h"
#include "resizer.h"
#include "test_func.h"


int main() {
    resizer rs;
    rs.liquid_resize((char*)"..\\tests\\Waifu.bmp",(char*)"..\\tests\\Waifu2.bmp",100);
    return 0;
}