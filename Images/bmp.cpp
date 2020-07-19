#include "bmp.h"
#include "digits_bool_array.h"
#include <cmath>
#include <iostream>

bmp_writer::bmp_writer(char *filename, size_t width, size_t height, size_t color_bit)
{
    this->img_out = fopen(filename,"wb+");


    this->bfh.bfType = 0x4D42;
    this->bfh.bfSize=sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER)+width*height*color_bit/8;
    this->bfh.bfReserved1=0;
    this->bfh.bfReserved2=0;
    this->bfh.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);

    this->bih.biSize=sizeof(BITMAPINFOHEADER);
    this->bih.biWidth = (long)width;
    this->bih.biHeight = (long)height;
    this->bih.biPlanes=1;
    this->bih.biBitCount=color_bit;
    this->bih.biCompression=0;
    this->bih.biSizeImage=0;
    this->bih.biXPelsPerMeter =2975;
    this->bih.biYPelsPerMeter =2975;
    this->bih.biClrUsed=0;
    this->bih.biClrImportant=0;

    fwrite(&bfh,sizeof(bfh),1,this->img_out);
    fwrite(&bih,sizeof(bih),1,this->img_out);

    for (long i =0; i < bih.biWidth;i++)
    {
        for (long j=0;j< bih.biHeight;j++)
        {
            write_pixel(i,j,back_color);
        }
    }

}

void bmp_writer::write_pixel(size_t x, size_t y, tagRGBQUAD _color) {

    size_t sizeofcolor = this->bih.biBitCount/8;
    size_t y1 = this->bih.biHeight-y-1;
    size_t line = this->bih.biWidth;
    fseek(this->img_out,sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+sizeofcolor*(x+y1*line),SEEK_SET);
    fwrite(&_color,sizeof(tagRGBQUAD),1,this->img_out);

}

void bmp_writer::write_line(size_t x1, size_t y1, size_t x2, size_t y2, tagRGBQUAD _color) {

    double step_count = std::max(std::abs((int)(x2-x1)),std::abs((int)(y2-y1)));
    double step_x = ((double)x2-(double)x1)/step_count;
    double step_y = ((double)y2-(double)y1)/step_count;
    size_t x=x1,y=y1;
    for(size_t i=0;i<=(size_t)step_count;i++)
    {
        write_pixel(x,y,_color);
        x=ceil(x+step_x);
        y=ceil(y+step_y);
    }
}


void bmp_writer::write_digit(size_t x, size_t y, int digit, tagRGBQUAD _color) {
    bool* digit_array;
    switch (digit)
    {
        default:
            digit_array = (bool*)&d_null;
            break;
        case(0):
            digit_array = (bool*)&d_zero;
            break;
        case (1):
            digit_array = (bool*)&d_one;
            break;
        case (2):
            digit_array = (bool*)&d_two;
            break;
        case (3):
            digit_array = (bool*)&d_three;
            break;
        case (4):
            digit_array = (bool*)&d_four;
            break;
        case (5):
            digit_array = (bool*)&d_five;
            break;
        case (6):
            digit_array = (bool*)&d_six;
            break;
        case (7):
            digit_array = (bool*)&d_seven;
            break;
        case (8):
            digit_array = (bool*)&d_eight;
            break;
        case (9):
            digit_array = (bool*)&d_nine;
            break;
    }
    for (size_t _y=0;_y<5;_y++)
    {
        for (size_t _x=0;_x<3;_x++)
        {
            if(*digit_array) write_pixel(x+_x,y+_y,_color);
            digit_array++;
        }
    }
}

void bmp_writer::write_circle(size_t x, size_t y, size_t r, tagRGBQUAD color , bool is_hollow) {
    for (size_t i=x-r-1;i<x+r+1;i++)
    {
        for (size_t j=y-r-1;j<y+r+1;j++)
        {
            if (ceil(pow((i-x)*(i-x)+(j-y)*(j-y),0.5))==r ||
                (!is_hollow && ceil(pow((i-x)*(i-x)+(j-y)*(j-y),0.5))<r))
                write_pixel(i,j,color);
        }
    }
}

void bmp_writer::swap_pixel(size_t x1, size_t y1, size_t x2, size_t y2) {
    size_t sizeofcolor = this->bih.biBitCount/8;
    size_t y = this->bih.biHeight-y1-1;
    size_t line = this->bih.biWidth;
    fseek(this->img_out,sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+sizeofcolor*(x1+y*line),SEEK_SET);
    tagRGBQUAD buffer1; fread(&buffer1,sizeof(tagRGBQUAD),1,this->img_out);
    y = this->bih.biHeight-y2-1;
    fseek(this->img_out,sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+sizeofcolor*(x2+y*line),SEEK_SET);
    tagRGBQUAD buffer2; fread(&buffer2,sizeof(tagRGBQUAD),1,this->img_out);
    write_pixel(x1,y1,buffer1);
    write_pixel(x2,y2,buffer2);
}

void bmp_writer::flip_horizontal(size_t x1, size_t y1, size_t x2, size_t y2) {
    for (size_t y=y1;y<=y2;y++)
    {
        for (size_t x=x1;x<=(x2+x1)/2;x++) swap_pixel(x,y,x2-x+x1,y);
    }
}

void bmp_writer::flip_vertical(size_t x1, size_t y1, size_t x2, size_t y2) {
    for (size_t x=x1;x<=x2;x++)
    {
        for (size_t y=x1;y<=(y2+y1)/2;y++) swap_pixel(x,y,x,y2-y+y1);
    }
}

void bmp_writer::flip(size_t x1, size_t y1, size_t x2, size_t y2) {
    for (size_t y=y1;y<=y2;y++)
    {
        for (size_t x=x1;x<=(x2+x1)/2;x++) swap_pixel(x,y,x2-x+x1,y2-y+y1);
    }
}

void bmp_writer::write_gradient(size_t x1, size_t y1, size_t x2, size_t y2, tagRGBQUAD _color1, tagRGBQUAD _color2) {
    double step_r = ((double)_color2.rgbRed-(double)_color1.rgbRed)/(pow(pow((double)x2-(double)x1,2)+pow((double)y2-(double)y1,2),0.5));
    double step_g = ((double)_color2.rgbGreen-(double)_color1.rgbGreen)/(pow(pow((double)x2-(double)x1,2)+pow((double)y2-(double)y1,2),0.5));
    double step_b = ((double)_color2.rgbBlue-(double)_color1.rgbBlue)/(pow(pow((double)x2-(double)x1,2)+pow((double)y2-(double)y1,2),0.5));


    tagRGBQUAD new_color{0,0,0,0};

    int step_x = ((int)x2-(int)x1)/std::abs((int)x2-(int)x1);
    int step_y = ((int)y2-(int)y1)/std::abs((int)y2-(int)y1);
    for (size_t i=x1;i!=x2+step_x;i+=step_x)
    {
        for(size_t j=y1;j!=y2+step_y;j+=step_y)
        {
            new_color.rgbRed=_color1.rgbRed+step_r*(pow(pow((double)i-(double)x1,2)+pow((double)j-(double)y1,2),0.5));
            new_color.rgbGreen=_color1.rgbGreen+step_g*(pow(pow((double)i-(double)x1,2)+pow((double)j-(double)y1,2),0.5));
            new_color.rgbBlue=_color1.rgbBlue+step_b*(pow(pow((double)i-(double)x1,2)+pow((double)j-(double)y1,2),0.5));

            write_pixel(i,j,new_color);
        }
    }
}

void bmp_writer::write_gradient_horizontal(size_t x1, size_t y1, size_t x2, size_t y2, tagRGBQUAD _color1, tagRGBQUAD _color2) {
    double step_r = ((double)_color2.rgbRed-(double)_color1.rgbRed)/(x2-x1);
    double step_g = ((double)_color2.rgbGreen-(double)_color1.rgbGreen)/(x2-x1);
    double step_b = ((double)_color2.rgbBlue-(double)_color1.rgbBlue)/(x2-x1);

    tagRGBQUAD new_color{0,0,0,0};

    for (size_t i=x1;i<=x2;i++)
    {
        new_color.rgbRed=_color1.rgbRed+step_r*(i-x1);
        new_color.rgbGreen=_color1.rgbGreen+step_g*(i-x1);
        new_color.rgbBlue=_color1.rgbBlue+step_b*(i-x1);
        for(size_t j=y1;j<=y2;j++)
        {
            write_pixel(i,j,new_color);
        }
    }
}

void bmp_writer::write_gradient_vertical(size_t x1, size_t y1, size_t x2, size_t y2, tagRGBQUAD _color1, tagRGBQUAD _color2) {
    double step_r = ((double)_color2.rgbRed-(double)_color1.rgbRed)/(y2-y1);
    double step_g = ((double)_color2.rgbGreen-(double)_color1.rgbGreen)/(y2-y1);
    double step_b = ((double)_color2.rgbBlue-(double)_color1.rgbBlue)/(y2-y1);

    tagRGBQUAD new_color{0,0,0,0};

    for (size_t j=y1;j<=y2;j++)
    {
        new_color.rgbRed=_color1.rgbRed+step_r*(j-y1);
        new_color.rgbGreen=_color1.rgbGreen+step_g*(j-y1);
        new_color.rgbBlue=_color1.rgbBlue+step_b*(j-y1);
        for(size_t i=x1;i<=x2;i++)
        {
            write_pixel(i,j,new_color);
        }
    }
}

void bmp_writer::write_rectangle(size_t x, size_t y , size_t size_x, size_t size_y, size_t angle, tagRGBQUAD _color) {
    size_t x1=ceil(x+size_x*cos(angle));
    size_t y1=ceil(y+size_x*sin(angle));
    size_t x2=ceil(x-size_y*sin(angle));
    size_t y2=ceil(y+size_y*cos(angle));
    double step_x = ((double)x2-(double)x)/((double)y2-(double)y);
    for (;y<=y2;y++)
    {
        write_line(x,y,x1,y1,_color);
        y1++;
        x+=step_x;
        x1+=step_x;
    }
}

BITMAPINFOHEADER bmp_writer::get_info_header() {return this->bih;}
BITMAPFILEHEADER bmp_writer::get_file_header() {return this->bfh;}


bmp_writer::~bmp_writer() {
    fclose(this->img_out);
}

bmp_reader::bmp_reader(char *filename) {
    this->img_in = fopen(filename,"rb");
    fread(&this->bfh,sizeof(BITMAPFILEHEADER),1,this->img_in);
    fread(&this->bih,sizeof(BITMAPINFOHEADER),1,this->img_in);
}

tagRGBQUAD bmp_reader::get_pixel(size_t x, size_t y) {
    size_t sizeofcolor = this->bih.biBitCount/8;
    size_t y1 = this->bih.biHeight-y-1;
    size_t line = this->bih.biWidth;
    fseek(this->img_in,sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+sizeofcolor*(x+y1*line),SEEK_SET);
    tagRGBQUAD _color{};
    fread(&_color,sizeof(tagRGBQUAD),1,this->img_in);
    return _color;
}

BITMAPINFOHEADER bmp_reader::get_info_header() {return this->bih;}
BITMAPFILEHEADER bmp_reader::get_file_header() {return this->bfh;}

bmp_reader::~bmp_reader() {
    fclose(this->img_in);
}