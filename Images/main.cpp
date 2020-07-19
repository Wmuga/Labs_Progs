#include "bmp.h"
#include "resizer.h"
#include "test_func.h"


int main() {
    resizer rs;
    /*
    rs.increase_smart("D:\\Documents\\GitHub\\Labs_Progs\\Images\\tests\\imp.bmp",
                      "D:\\Documents\\GitHub\\Labs_Progs\\Images\\tests\\imp_resized_smart.bmp");
    rs.resize("D:\\Documents\\GitHub\\Labs_Progs\\Images\\tests\\imp.bmp",
                       "D:\\Documents\\GitHub\\Labs_Progs\\Images\\tests\\imp_resized.bmp",1640,1434);
    */
    rs.liquid_resize("D:\\Documents\\GitHub\\Labs_Progs\\Images\\tests\\beepu.bmp","D:\\Documents\\GitHub\\Labs_Progs\\Images\\tests\\girl_test.bmp");
     return 0;
}