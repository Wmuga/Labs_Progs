#include <iostream>
#include <Windows.h>
#include <fstream>


int main() {
    while (true)
    {
        Sleep(20000);
        std::ofstream title(R"(D:\Documents\GitHub\Labs_Progs\Test\GetWin\title.txt)");
        HWND hwnd ;
        hwnd = GetForegroundWindow();
        char s_title[256];
        GetWindowTextA(hwnd,s_title,256);
        std::cout << s_title <<std::endl;
        title << s_title;
    }
    return 0;
}