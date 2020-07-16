#include "bmp_writer.h"
#include <iostream>

bmp_writer::bmp_writer(char *filename, size_t width, size_t height, size_t color_bit)
{
    this->img_out.open(filename,std::ios::binary);

    this->bih.biSize[0] = ((int_to4b)sizeof(BITMAPINFOHEADER)).size_char[0];
    this->bih.biSize[1] = ((int_to4b)sizeof(BITMAPINFOHEADER)).size_char[1];
    this->bih.biSize[2] = ((int_to4b)sizeof(BITMAPINFOHEADER)).size_char[2];
    this->bih.biSize[3] = ((int_to4b)sizeof(BITMAPINFOHEADER)).size_char[3];

    this->bih.biPlanes[0] = (int_to2b(1)).size_char[0];
    this->bih.biPlanes[1] = (int_to2b(1)).size_char[1];

    this->bih.biWidth = (long)width;
    this->bih.biHeight = (long)height;

    this->bih.biBitCount[0] = ((int_to2b)color_bit).size_char[0];
    this->bih.biBitCount[1] = ((int_to2b)color_bit).size_char[1];

    this->bih.biCompression[0] = 0;
    this->bih.biCompression[1] = 0;
    this->bih.biCompression[2] = 0;
    this->bih.biCompression[3] = 0;

    this->bih.biXPelsPerMeter =2975;
    this->bih.biYPelsPerMeter =2975;

    this->bih.biClrUsed[0] = 0;
    this->bih.biClrUsed[1] = 0;
    this->bih.biClrUsed[2] = 0;
    this->bih.biClrUsed[3] = 0;

    this->bih.biClrImportant[0] = 0;
    this->bih.biClrImportant[1] = 0;
    this->bih.biClrImportant[2] = 0;
    this->bih.biClrImportant[3] = 0;

    this->bfh.bfSize[0] = ((int_to4b)(sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER)+width*height*color_bit/8)).size_char[0];
    this->bfh.bfSize[1] = ((int_to4b)(sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER)+width*height*color_bit/8)).size_char[1];
    this->bfh.bfSize[2] = ((int_to4b)(sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER)+width*height*color_bit/8)).size_char[2];
    this->bfh.bfSize[3] = ((int_to4b)(sizeof(BITMAPINFOHEADER)+sizeof(BITMAPFILEHEADER)+width*height*color_bit/8)).size_char[3];

    this->bfh.bfType[0] = 'B';
    this->bfh.bfType[1] = 'M';

    this->bfh.bfReserved1[0] = 0;
    this->bfh.bfReserved2[1] = 0;
    this->bfh.bfReserved1[0] = 0;
    this->bfh.bfReserved2[1] = 0;

    this->bfh.bfOffBits[0] = ((int_to4b)(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER))).size_char[0];
    this->bfh.bfOffBits[1] = ((int_to4b)(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER))).size_char[1];
    this->bfh.bfOffBits[2] = ((int_to4b)(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER))).size_char[2];
    this->bfh.bfOffBits[3] = ((int_to4b)(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER))).size_char[3];

    this->img_out.write(reinterpret_cast<char*>(&this->bfh.bfType),2);
    this->img_out.write(reinterpret_cast<char*>(&this->bfh.bfSize),4);
    this->img_out.write(reinterpret_cast<char*>(&this->bfh.bfReserved1),2);
    this->img_out.write(reinterpret_cast<char*>(&this->bfh.bfReserved2),2);
    this->img_out.write(reinterpret_cast<char*>(&this->bfh.bfOffBits),4);

    this->img_out.write(reinterpret_cast<char*>(&this->bih.biSize),4);
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biWidth),sizeof(long));
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biHeight),sizeof(long));
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biPlanes),2);
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biBitCount),2);
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biCompression),4);
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biSizeImage),4);
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biXPelsPerMeter),sizeof(long));
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biYPelsPerMeter),sizeof(long));
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biClrUsed),4);
    this->img_out.write(reinterpret_cast<char*>(&this->bih.biClrImportant),4);

    for (long i =0; i < bih.biWidth;i++)
    {
        for (long j=0;j< bih.biHeight;j++)
        {
            this->img_out.write(reinterpret_cast<char*>(&back_color.rgbBlue), 1);
            this->img_out.write(reinterpret_cast<char*>(&back_color.rgbGreen), 1);
            this->img_out.write(reinterpret_cast<char*>(&back_color.rgbRed), 1);
            this->img_out.write(reinterpret_cast<char*>(&back_color.rgbReserved), 1);
        }
    }

}

void bmp_writer::write_pixel(size_t x, size_t y, tagRGBQUAD _color) {
    this->img_out.clear();
    std::cout << this->bih.biBitCount;
    /*
    size_t sizeofcolor = std::stoi(this->bih.biBitCount, nullptr,16)/8;
    size_t y1 = this->bih.biHeight-y-1;
    size_t line = this->bih.biWidth;
    std::clog << sizeofcolor << " " << line;
    std:: clog << "[" << x << " " << y1 << " " << sizeofcolor*(x+y1*line) << "] ";
    this->img_out.seekp(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+sizeofcolor*(x+y1*line),std::ios::beg);
    this->img_out.write(reinterpret_cast<char*>(&_color.rgbBlue),1);
    this->img_out.write(reinterpret_cast<char*>(&_color.rgbGreen),1);
    this->img_out.write(reinterpret_cast<char*>(&_color.rgbRed),1);
    this->img_out.write(reinterpret_cast<char*>(&_color.rgbReserved),1);
     */
}

void bmp_writer::write_line(size_t x1, size_t y1, size_t x2, size_t y2, tagRGBQUAD _color) {

    double step_count = std::max(std::abs((int)(x2-x1)),std::abs((int)(y2-y1)));
    double step_x = ((double)x2-(double)x1)/step_count;
    double step_y = ((double)y2-(double)y1)/step_count;
    double x=x1,y=y1;
    for(size_t i=0;i<=(size_t)step_count;i++)
    {
        write_pixel(x,y,_color);
        std::clog<< "(" << x << " " << y <<  ") ";
        x+=step_x;
        y+=step_y;
    }
}

bmp_writer::~bmp_writer() {
    this->img_out.close();
}
