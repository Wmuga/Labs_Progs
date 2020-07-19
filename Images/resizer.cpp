#include "resizer.h"
#include <iostream>

void resizer::resize(char* img_in, char* img_out,size_t new_width,size_t new_height)
{
    bmp_reader fin(img_in);
    size_t s_width = fin.get_info_header().biWidth,s_height = fin.get_info_header().biHeight;
    size_t bit_count = fin.get_info_header().biBitCount;
    bmp_writer fout(img_out,new_width,new_height,bit_count);
    double step_x = (double)s_width/(double)new_width;
    double step_y = (double)s_height/(double)new_height;
    std::clog << step_x << " " << step_y;
    size_t y=0;
    double j=0;
    while(y<new_height)
    {
        size_t x=0;
        double i=0;
        while(x<new_width)
        {
            fout.write_pixel((size_t)x, (size_t)y, fin.get_pixel((size_t)i, (size_t)j));
            x++;
            i+=step_x; if (i>s_width) i = s_width-1;
        }
        y++;
        j+=step_y; if (j>s_height) j = s_height-1;
    }
}

void resizer::increase_width_smart(char* img_in, char* img_out)
{
    bmp_reader fin(img_in);
    size_t s_width = fin.get_info_header().biWidth,s_height = fin.get_info_header().biHeight;
    size_t bit_count = fin.get_info_header().biBitCount;
    bmp_writer fout(img_out,s_width*2,s_height,bit_count);
    for (size_t j=0;j<s_height;j++) fout.write_pixel(0,j,fin.get_pixel(0,j));
    for (size_t j=0;j<s_height;j++) {
        size_t i1=2;
        for (size_t i = 1; i < s_width; i++)
        {
            fout.write_pixel(i1,j,fin.get_pixel(i,j));
            tagRGBQUAD new_color{0,0,0,0};
            new_color.rgbBlue = fin.get_pixel(i-1,j).rgbBlue/2+fin.get_pixel(i,j).rgbBlue/2;
            new_color.rgbRed = fin.get_pixel(i-1,j).rgbRed/2+fin.get_pixel(i,j).rgbRed/2;
            new_color.rgbGreen = fin.get_pixel(i-1,j).rgbGreen/2+fin.get_pixel(i,j).rgbGreen/2;
            new_color.rgbReserved = fin.get_pixel(i-1,j).rgbReserved/2+fin.get_pixel(i,j).rgbReserved/2;
            fout.write_pixel(i1-1,j,new_color);
            i1+=2;
        }
    }
}

void resizer::increase_height_smart(char* img_in, char* img_out)
{
    bmp_reader fin(img_in);
    size_t s_width = fin.get_info_header().biWidth,s_height = fin.get_info_header().biHeight;
    size_t bit_count = fin.get_info_header().biBitCount;
    bmp_writer fout(img_out,s_width,s_height*2,bit_count);
    for (size_t i = 1; i < s_width; i++) fout.write_pixel(i,0,fin.get_pixel(i,0));
    for (size_t i = 0; i < s_width; i++) {
        size_t j1=2;
        for (size_t j=1;j<s_height;j++)
        {
            fout.write_pixel(i,j1,fin.get_pixel(i,j));
            tagRGBQUAD new_color{0,0,0,0};
            new_color.rgbBlue = fin.get_pixel(i,j-1).rgbBlue/2+fin.get_pixel(i,j).rgbBlue/2;
            new_color.rgbRed = fin.get_pixel(i,j-1).rgbRed/2+fin.get_pixel(i,j).rgbRed/2;
            new_color.rgbGreen = fin.get_pixel(i,j-1).rgbGreen/2+fin.get_pixel(i,j).rgbGreen/2;
            new_color.rgbReserved = fin.get_pixel(i,j-1).rgbReserved/2+fin.get_pixel(i,j).rgbReserved/2;
            fout.write_pixel(i,j1-1,new_color);
            j1+=2;
        }
    }
}

void resizer::increase_smart(char *img_in, char *img_out) {
    increase_width_smart(img_in, (char *) "buffer.bmp");
    increase_height_smart((char *) "buffer.bmp", img_out);
    remove((char *) "buffer.bmp");
}

void resizer::liquid_resize(char* img_in, char* img_out) {
    bmp_reader fin(img_in);
    size_t s_width = fin.get_info_header().biWidth+4,s_height = fin.get_info_header().biHeight;
    size_t bit_count = fin.get_info_header().biBitCount;
    bmp_writer fout(img_out,s_width,s_height,bit_count);
    get_energy_pallet(fin);
    get_paths_array(s_width-4, s_height);
    get_path(s_width-4, s_height);
    for (size_t j=fin.get_info_header().biHeight;j>0;j--) {
        fout.write_pixel(fin.get_info_header().biWidth, fin.get_info_header().biHeight - j,
                         fin.get_pixel(line_coords[j - 1].first, line_coords[j - 1].second));
    }
}

void resizer::get_energy_pallet(bmp_reader fin) {
    for (size_t i=0;i<fin.get_info_header().biWidth-1;i++)
    {
        std::vector<int> energy_line;
        for (size_t j=0;j<fin.get_info_header().biHeight-1;j++)
        {
            tagRGBQUAD current_color = fin.get_pixel(i,j);
            tagRGBQUAD down_color = fin.get_pixel(i,j+1);
            tagRGBQUAD next_color = fin.get_pixel(i+1,j);
            energy_line.push_back(
                    std::abs(current_color.rgbReserved-down_color.rgbReserved)/8+std::abs(current_color.rgbReserved-next_color.rgbReserved)/8+
                            std::abs(current_color.rgbRed-down_color.rgbRed)/8+std::abs(current_color.rgbRed-next_color.rgbRed)/8+
                            std::abs(current_color.rgbBlue-down_color.rgbBlue)/8+std::abs(current_color.rgbBlue-next_color.rgbBlue)/8+
                            std::abs(current_color.rgbGreen-down_color.rgbGreen)/8+std::abs(current_color.rgbGreen-next_color.rgbGreen)/8
                    );
        }
        tagRGBQUAD current_color = fin.get_pixel(i,fin.get_info_header().biHeight-1);
        tagRGBQUAD next_color = fin.get_pixel(i+1,fin.get_info_header().biHeight-1);
        energy_line.push_back(
                std::abs(current_color.rgbReserved-next_color.rgbReserved)/8+
                std::abs(current_color.rgbRed-next_color.rgbRed)/8+
                std::abs(current_color.rgbBlue-next_color.rgbBlue)/8+
                std::abs(current_color.rgbGreen-next_color.rgbGreen)/8
        );
        energy_array.push_back(energy_line);
    }
    std::vector<int> energy_line;
    for (size_t j=0;j<fin.get_info_header().biHeight-1;j++)
    {
        tagRGBQUAD current_color = fin.get_pixel(fin.get_info_header().biWidth-1,fin.get_info_header().biHeight-2);
        tagRGBQUAD down_color = fin.get_pixel(fin.get_info_header().biWidth-1,fin.get_info_header().biHeight-1);
        energy_line.push_back(
                std::abs(current_color.rgbReserved-down_color.rgbReserved)/8+
                std::abs(current_color.rgbRed-down_color.rgbRed)/8+
                std::abs(current_color.rgbBlue-down_color.rgbBlue)/8+
                std::abs(current_color.rgbGreen-down_color.rgbGreen)/8
        );
    }
    energy_line.push_back(0);
    energy_array.push_back(energy_line);

}

void resizer::draw_energy_pallet(bmp_writer& fout) {
    for (size_t i=0;i<fout.get_info_header().biWidth;i++)
    {
        for (size_t j=0;j<fout.get_info_header().biHeight;j++)
        {
            tagRGBQUAD _color {0,0,0,0};
            _color.rgbBlue = 255-energy_array[i][j];
            _color.rgbRed = 255-energy_array[i][j];
            _color.rgbGreen = 255-energy_array[i][j];
            fout.write_pixel(i,j,_color);
        }
    }
}

void resizer::get_paths_array(size_t xmax, size_t ymax) {
    for (size_t i=0;i<xmax;i++) energy_path_array.push_back(energy_array[i]);
    for (size_t j=1;j<ymax;j++)
    {
        std::vector<int> energy_line;
        energy_line.push_back(energy_array[0][j-1]+energy_array[1][j-1]+energy_array[0][j]);
        for (size_t i=1;i<xmax-1;i++) energy_line.push_back(energy_array[i-1][j-1]+energy_array[i][j-1]+energy_array[i+1][j-1]+energy_array[i][j]);
        energy_line.push_back(energy_array[xmax-1-1][j-1]+energy_array[xmax-1][j-1]+energy_array[xmax-1][j]);
        energy_path_array.push_back(energy_line);
    }
}

void resizer::get_path(size_t xmax, size_t ymax)
{
    for (size_t j=ymax-1;j!=0;j--)
    {
        std::pair<int,int> dot{0,j};
        if (j==ymax-1) for (size_t i=0;i<xmax;i++) {if (energy_path_array[dot.first][j]>energy_path_array[i][j]) dot.first=i;}
        else{
            size_t start_pos = line_coords[ymax-2-j].first==0 ? 0 : line_coords[ymax-2-j].first-1;
            dot.first=start_pos;
            size_t end_pos = line_coords[ymax-2-j].first==xmax-1 ? xmax-1 : line_coords[ymax-2-j].first+1;
            for (size_t i=start_pos;i<=end_pos;i++)
            {
                if (energy_path_array[dot.first][j]>energy_path_array[i][j]) dot.first=i;
            }
        }
        line_coords.push_back(dot);
    }
}