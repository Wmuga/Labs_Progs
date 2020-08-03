#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>

union i4b{
    unsigned int w;
    char b[4]{};
    i4b()= default;
    i4b(int h):w(h){};
    i4b(char* h){
        for (int i=0;i<4;i++) b[i]=h[i];
    }
};

void set_timer(unsigned int total_time,std::ofstream* fout)
{
    while (total_time) {
        fout->seekp(0);
        *fout << total_time / 60 << ":" << std::setw(2) << std::right << std::setfill('0') << total_time % 60;
        fout->flush();
        total_time--;
        Sleep(1000);
    }
}

int main() {
    unsigned int total_time = 0;
    for (int i = 1; i <= 2; i++) {
        char* filename = new char[256];
        sprintf(filename,"..\\Music\\%d.wav",i);
        FILE *_file = fopen(filename, "rb");
        if (_file) {
            i4b conv;
            fseek(_file, 28, SEEK_SET);
            fread(conv.b, 4, 1, _file);
            unsigned int bps = conv.w;
            fseek(_file, 0, SEEK_END);
            unsigned int size = ftell(_file) - 44;
            total_time+=size/bps;
        }
        std::ofstream fout("..\\timer.txt");
        if (fout) set_timer(total_time,&fout);
        fout.close();
        fclose(_file);
        delete []filename;
    }
    system("D:\\Programs\\AIMP3\\aimp3.exe \"D:\\Documents\\GitHub\\Labs_Progs\\Side stuff\\TestWav\\Music\\1.wav\"");
    return 0;
}
