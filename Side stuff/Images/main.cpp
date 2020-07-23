#include "bmp.h"
#include "resizer.h"
#include "test_func.h"


int main() {
    resizer rs;
    rs.liquid_resize((char*)R"(D:\Documents\GitHub\Labs_Progs\Images\tests\m.bmp)",(char*)R"(D:\Documents\GitHub\Labs_Progs\Images\tests\m_test.bmp)",40);
    return 0;
}