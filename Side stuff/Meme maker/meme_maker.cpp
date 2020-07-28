#include "meme_maker.h"
#include "resizer.h"
#include "bmp.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

unsigned int meme_maker::lat_letters_array[6][5]{};
unsigned int meme_maker::cir_letters_array[6][5]{};


meme_maker::meme_maker() {
    get_font_lat();
    get_font_cir();
}

void meme_maker::black_screen_meme(char* image_filename,bool is_cirillic,char* text_big,char* text_small) {

    char* meme_filename = new char[256];
    sprintf(meme_filename,"%sblack screen text meme.bmp",buffer_file_path);

    char* text_name = new char[256];
    sprintf(text_name,"%stxt.bmp",buffer_file_path);

    char* text_big_name = new char[256];
    sprintf(text_big_name,"%stext_big.bmp",buffer_file_path);

    char *text_small_name = new char[256];
    sprintf(text_small_name, "%stext_small.bmp", buffer_file_path);

    void (*text_creator)(char*, char*);
    size_t count = strlen(text_big);
    if (is_cirillic) count/=2;
    if (is_cirillic) text_creator = meme_maker::make_cir_text;
    else text_creator = meme_maker::make_lat_text;

    //getting image
    bmp_reader fin;
    fin.open(image_filename);
    size_t image_width = fin.get_info_header().biWidth, image_height = fin.get_info_header().biHeight;

    //making and scaling text
    text_creator(text_big,text_name);
    resizer res;
    res.resize(text_name,text_big_name,(size_t)image_width*1.07, (size_t)image_width*1.07/(6 * count + 1)*6);

    if (text_small!=nullptr) {


        count = strlen(text_small);
        if (is_cirillic) count/=2;
        text_creator(text_small, text_name);

        res.resize(text_name, text_small_name, (size_t)image_width*0.8, (size_t)image_width*0.8/(6 * count + 1)*6);
    }

    //setting upp meme
    bmp_writer fout;
    size_t height_b = (size_t)image_width*1.87/(6 * count + 1)*6;
    fout.create(meme_filename,(size_t)image_width*1.334,(size_t)image_height*1.2+(size_t)image_width*1.87/(6 * count + 1)*6,24);
    //placing image with outline
    for (int j=-(int)image_height*0.007;j<image_height+(int)image_height*0.007;j++)
    {
        for (int i=-(int)image_width*0.007;i<image_width+(int)image_width*0.007;i++)
        {
            if (j>=0 && j< image_height && i>=0 && i<image_width) fout.write_pixel(i+image_width*0.16,j+image_height*0.08,fin.get_pixel(i,j));
            else fout.write_pixel(i+image_width*0.16,j+image_height*0.08,{255,255,255,0});
        }
    }
    fin.rclose();
    //placing text
    fin.open(text_big_name);
    for (size_t j=0;j<fin.get_info_header().biHeight;j++)
    {
        for (size_t i=0;i<fin.get_info_header().biWidth;i++)
        {
            fout.write_pixel(i+image_width*0.146-(size_t)image_width*0.8/(6 * count + 1),j+image_height*1.1,fin.get_pixel(i,j));
        }
    }
    fin.rclose();
    if (text_small!=nullptr) {
        fin.open(text_small_name);
        for (size_t j=0;j<fin.get_info_header().biHeight;j++)
        {
            for (size_t i=0;i<fin.get_info_header().biWidth;i++)
            {
                fout.write_pixel(i+image_width*0.306-(size_t)image_width*0.8/(6 * count + 1),j+image_height*1.1+height_b,fin.get_pixel(i,j));
            }
        }
    }
    fout.wclose();
    remove(text_name);
    delete []meme_filename;
    delete []text_name;
    delete []text_big_name;
    delete[]text_small_name;
}

void meme_maker::make_lat_text(char * text,char* text_name) {
    size_t count = strlen(text);
    bmp_writer text_out;

    text_out.create(text_name,6*count+1,8,24);
    for (size_t ch=0;ch<count;ch++)
    {
        for (size_t j=0;j<6;j++)
        {
            for (size_t i=0;i<5;i++)
            {
                unsigned int num = meme_maker::lat_letters_array[j][i];
                if (text[ch]!=' ' && (size_t)(num/pow(2,(text[ch]-'a')))%2==1)
                    text_out.write_pixel(1+i+ch*6,j+1,{255,255,255,0});
            }
        }
    }
    text_out.wclose();
}

void meme_maker::make_cir_text(char *, char *) {}

void meme_maker::get_font_lat() {
    bmp_reader fin;
    char *lat_fonts_filename = new char[256];
    sprintf(lat_fonts_filename, "%sletters_lat.bmp", in_file_path);
    fin.open(lat_fonts_filename);
    for (auto & j : meme_maker::lat_letters_array) for (unsigned int & i : j) i=1;
    for (size_t j = 0; j < 6; j++) {
        for (size_t i = 0; i < 5; i++) {
            for (size_t ch = 26; ch > 0; ch--) {
                meme_maker::lat_letters_array[j][i] *= 2;
                if (fin.get_pixel(i + (ch - 1) * 6, j).rgbRed == 0) meme_maker::lat_letters_array[j][i]++;
            }
        }
    }
    fin.rclose();
    delete[]lat_fonts_filename;
}

void meme_maker::get_font_cir() {
    bmp_reader fin;
    char *lat_fonts_filename = new char[256];
    sprintf(lat_fonts_filename, "%sletters_cir.bmp", in_file_path);
    fin.open(lat_fonts_filename);
    for (auto & j : meme_maker::cir_letters_array) for (unsigned int & i : j) i=1;
    for (size_t j = 0; j < 6; j++) {
        for (size_t i = 0; i < 5; i++) {
            for (size_t ch = 32; ch > 0; ch--) {
                meme_maker::cir_letters_array[j][i] *= 2;
                if (fin.get_pixel(i + (ch - 1) * 6, j).rgbRed == 0) meme_maker::cir_letters_array[j][i]++;
            }
        }
    }
    fin.rclose();
    delete[]lat_fonts_filename;
}