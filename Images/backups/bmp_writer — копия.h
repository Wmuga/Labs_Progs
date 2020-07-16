#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

struct BITMAPFILEHEADER
{
    char bfType[2]; //4D42 or 424D == BM
    char bfSize[4]; // sizeof(file)
    char bfReserved1[2]; // 0
    char bfReserved2[2]; // 0
    char bfOffBits[4]; // location of pixels
};

struct BITMAPINFOHEADER
{
    char biSize[4]; //sizeof(BITMAPINFOHEADER)
    long biWidth; //file
    long biHeight; //file
    char biPlanes[2]; //always 1
    char biBitCount[2]; //bit to 1 pixel, 1(2clr),4(16clr),8(256clr),16(2^16(15)clr),24(2^24 clr)
    char biCompression[4]; //flag BI_RGB = 0
    char biSizeImage[4]; //Image size = Width*Height*biBitCount/8
    long biXPelsPerMeter; //pixels/meter 2795
    long biYPelsPerMeter; //pixels/meter 2795
    char biClrUsed[4]; //always 0 - max possible colors
    char biClrImportant[4]; //always 0 - all are important
};

struct tagRGBQUAD
{
    char rgbBlue;
    char rgbGreen;
    char rgbRed;
    char rgbReserved = 0;
    tagRGBQUAD(std::string hex_color)
    {
        char buffer[2];
        buffer[0]=hex_color[0]; buffer[1]=hex_color[1];
        rgbRed=(char)std::stoi(buffer, nullptr,16);
        buffer[0]=hex_color[2]; buffer[1]=hex_color[3];
        rgbGreen=(char)std::stoi(buffer, nullptr,16);
        buffer[0]=hex_color[4]; buffer[1]=hex_color[5];
        rgbBlue=(char)std::stoi(buffer, nullptr,16);
    }
};

union int_to4b
{
    int size_int;
    char size_char[4];
    int_to4b(int conv): size_int(conv){}
    int_to4b(char conv[4]) {
        std::copy(conv,conv+4,size_char);
    }
};

union int_to2b
{
    int size_int;
    char size_char[2];
    int_to2b(int conv): size_int(conv){}
    int_to2b(char conv[2]) {
        std::copy(conv,conv+2,size_char);
    }
};

class bmp_writer
{
    std::ofstream img_out;
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

public:
    bmp_writer(char*, size_t, size_t, size_t);
    //x,y,color
    void write_pixel(size_t, size_t, tagRGBQUAD);
    //start - end coords, color
    void write_line(size_t, size_t, size_t, size_t, tagRGBQUAD);
    //x,y of top-left corner, digit, color
    void write_digit(size_t,size_t,int,tagRGBQUAD);
    //x,y,r,color ,is hollow
    void write_circle(size_t,size_t,size_t,tagRGBQUAD,bool);
    /*
    void write_rectangle();

    void write_triangle();
     */
    //start - end coords
    void flip_horizontal(size_t, size_t, size_t, size_t);
    //start - end coords
    void flip_vertical(size_t, size_t, size_t, size_t);
    //start - end coords
    void flip(size_t, size_t, size_t, size_t);

    void write_gradient_horizontal(size_t, size_t, size_t, size_t,tagRGBQUAD,tagRGBQUAD);
    void write_gradient_vertical(size_t, size_t, size_t, size_t,tagRGBQUAD,tagRGBQUAD);
    void write_gradient(size_t, size_t, size_t, size_t,tagRGBQUAD,tagRGBQUAD);

    ~bmp_writer();

private:
    void swap_pixel(size_t, size_t, size_t, size_t);
    tagRGBQUAD back_color = (std::string)"ffffff";
};
