#include "bmp.h"
#include "resizer.h"
#include "test_func.h"


int main() {
    resizer rs;
    //rs.liquid_resize((char*)"..\\tests\\Waifu.bmp",(char*)"..\\tests\\Waifu2.bmp",70);
    rs.resize((char*)"..\\tests\\Kromia.bmp",(char*)"..\\tests\\Kromia2.bmp",224,224);
    rs.increase_smart((char*)"..\\tests\\Kromia2.bmp",(char*)"..\\tests\\Kromia4.bmp");
    return 0;
}