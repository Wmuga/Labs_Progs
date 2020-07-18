#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
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

void draw_1()
{
    size_t s_width = 1920, s_height = 1200;
    bmp_writer draw((char*)"D:\\Desktop\\drawing_1.bmp",s_width,s_height,32);
    tagRGBQUAD _color1 {0,0,200,0};
    tagRGBQUAD _color2 {0,165,255,0};
    draw.write_gradient(0,0,s_width/2-1,s_height/2-1,_color1,_color2);
    draw.write_gradient(s_width-1,0,s_width/2,s_height/2-1,_color1,_color2);
    draw.write_gradient(0,s_height-1,s_width/2-1,s_height/2,_color1,_color2);
    draw.write_gradient(s_width-1,s_height-1,s_width/2,s_height/2,_color1,_color2);
}

void draw()
{
    size_t s_width = 100, s_height = 100;
    bmp_writer draw((char*)"D:\\Desktop\\drawing_shit.bmp",s_width,s_height,32);
    tagRGBQUAD _color1 {200,10,10,0};
    tagRGBQUAD _color2 {10,10,200,0};
    for (size_t i=0;i<s_width;i++)
    {
        for (size_t j=0;j<s_height;j++)
        {
            tagRGBQUAD _color{0,0,0,0};
            _color.rgbBlue =  _color1.rgbBlue+i*((double)_color2.rgbBlue-(double)_color1.rgbBlue)/s_width;
            _color.rgbGreen = _color1.rgbGreen + j*((double)_color2.rgbGreen-(double)_color1.rgbGreen)/s_height;
            _color.rgbRed =  _color1.rgbRed + pow(pow(i,2)+pow(j,2),0.5)*((double)_color2.rgbRed-(double)_color1.rgbRed)/pow(pow(s_width,2)+pow(s_height,2),0.5);
            draw.write_pixel(i,j,_color);
        }
    }
}

void inc_wide(char* img_in, char* img_out){
    bmp_reader fin(img_in);
    size_t s_width = fin.get_info_header().biWidth*2,s_height = fin.get_info_header().biHeight;
    size_t bit_count = fin.get_info_header().biBitCount;
    bmp_writer fout(img_out,s_width,s_height,bit_count);
    for (size_t j=0;j<s_height;j++)
    {
        int i1=0;
        if (j%2) i1=1;
        for (size_t i=0;i<s_width/2;i++)
        {
            fout.write_pixel(i1,j,fin.get_pixel(i,j));
            if (i1==1) {
                fout.write_pixel(0,j,fin.get_pixel(0,j));
                fout.write_pixel(2,j,fin.get_pixel(1,j));
            }
            else
            {
                if (i1==s_width-2) fout.write_pixel(s_width-1,j,fin.get_pixel(s_width/2-1,j));
                else  if (i1!=s_width-1)
                {
                    tagRGBQUAD new_pixel{0,0,0,0};
                    new_pixel.rgbBlue  = ((int)fin.get_pixel(i,j).rgbBlue +(int)fin.get_pixel(i+1,j).rgbBlue)/2;
                    new_pixel.rgbGreen = ((int)fin.get_pixel(i,j).rgbGreen+(int)fin.get_pixel(i+1,j).rgbGreen)/2;
                    new_pixel.rgbRed   = ((int)fin.get_pixel(i,j).rgbRed  +(int)fin.get_pixel(i+1,j).rgbRed)/2;
                    fout.write_pixel(i1+1,j,new_pixel);
                }
            }
            i1+=2;
        }
    }
}

void inc_height(char* img_in, char* img_out){
    bmp_reader fin(img_in);
    size_t s_width = fin.get_info_header().biWidth,s_height = fin.get_info_header().biHeight*2;
    size_t bit_count = fin.get_info_header().biBitCount;
    bmp_writer fout(img_out,s_width,s_height,bit_count);
    for (size_t i=0;i<s_width;i++)
    {
        int j1 = (i%2) ? 1 : 0;
        for (size_t j=0;j<s_height/2;j++)
        {
            fout.write_pixel(i,j1,fin.get_pixel(i,j));
            if (j1==1) {
                fout.write_pixel(i,0,fin.get_pixel(i,0));
                fout.write_pixel(i,2,fin.get_pixel(i,1));
            }
            else
            {
                if (j1==s_height-2) fout.write_pixel(i,s_height-1,fin.get_pixel(i,s_height/2-1));
                else  if (j1!=s_height-1)
                {
                    tagRGBQUAD new_pixel{0,0,0,0};
                    new_pixel.rgbBlue  = ((int)fin.get_pixel(i,j).rgbBlue +(int)fin.get_pixel(i,j+1).rgbBlue)/2;
                    new_pixel.rgbGreen = ((int)fin.get_pixel(i,j).rgbGreen+(int)fin.get_pixel(i,j+1).rgbGreen)/2;
                    new_pixel.rgbRed   = ((int)fin.get_pixel(i,j).rgbRed  +(int)fin.get_pixel(i,j+1).rgbRed)/2;
                    fout.write_pixel(i,j1+1,new_pixel);
                }
            }
            j1+=2;
        }
    }
}

void inc_size(char* img_in, char* img_out)
{
    inc_wide(img_in,"buffer.bmp");
    inc_height("buffer.bmp",img_out);
    remove("buffer.bmp");
}
