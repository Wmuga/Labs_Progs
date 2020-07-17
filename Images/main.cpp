#include <iostream>
#include <ctime>
#include <fstream>
#include "bmp_writer.h"

const int width = 16, height = 16;

//ppm
/*
#include "ppm_writer.h"
struct sudoku_header
{
    size_t cell_size_w;
    size_t cell_size_h;
    size_t cells_count_w;
    size_t cells_count_h;
};

void draw_standart_sudoku(char* filename)
{
    std::ifstream fin(filename);
    sudoku_header f{};
    fin >> f.cell_size_w;
    fin >> f.cell_size_h;
    fin >> f.cells_count_w;
    fin >> f.cells_count_h;

    size_t s_height = f.cell_size_h*f.cells_count_h*8;
    size_t s_width = f.cell_size_w*f.cells_count_w*6;

    color_t color_red("ff0000");
    color_t color_white("ffffff");

    ppm_writer sudoku((char*)R"(D:\Documents\GitHub\Labs_Progs\BitMap\test.bmp)", s_width, s_height, 256, false);

    for (size_t y=0;y<f.cell_size_h*f.cells_count_h;y++)
    {
        for (size_t x=0;x<f.cell_size_w*f.cells_count_w;x++)
        {
            int digit;
            fin>>digit;
            if (!digit) digit=-1;
            sudoku.write_digit(x*6+1,y*8+1,digit,color_red);
            color_t w_color =  ((x+1)%f.cell_size_w) ? color_red : color_white;
            size_t line_y = (y==0) ? 0 : y*8;
            sudoku.write_line((x+1)*6-1,line_y,
                              (x+1)*6-1,line_y+6+1,w_color);

            size_t line_x = (x==0) ? 0 : x*6;
            sudoku.write_line(line_x,(y+1)*8-1,line_x+4,(y+1)*8-1,color_red);
        }
        if ((y+1)%f.cell_size_h==0) sudoku.write_line(0,((y+1)*8-1),s_width-1,((y+1)*8-1),color_white);
    }

}

int main() {
    //draw_standart_sudoku((char*)R"(D:\Documents\GitHub\Labs_Progs\BitMap\test_easy_33.txt)");
    size_t max_color = 256;
    ppm_writer testg((char*)R"(D:\Documents\GitHub\Labs_Progs\BitMap\test_gradient.bmp)", width, height, max_color, false);

std::ofstream g("test.txt");
g.write((char*)"test message",sizeof(char*));

return 0;
}
*/

#define pi 3.1415

void draw()
{
    size_t s_width = 1920, s_height = 1200;
    bmp_writer draw((char*)"D:\\Desktop\\drawing.bmp",s_width,s_height,32);
    tagRGBQUAD _color1 {0,0,125,0};
    tagRGBQUAD _color2 {0,165,255,0};
    draw.write_gradient(0,0,s_width/2-1,s_height/2-1,_color1,_color2);
    draw.write_gradient(s_width-1,0,s_width/2,s_height/2-1,_color1,_color2);
    draw.write_gradient(0,s_height-1,s_width/2-1,s_height/2,_color1,_color2);
    draw.write_gradient(s_width-1,s_height-1,s_width/2,s_height/2,_color1,_color2);
}

int main() {
    draw();
    return 0;
}