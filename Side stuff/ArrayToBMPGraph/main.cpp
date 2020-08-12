#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "bmp.h"

void draw(const std::vector<std::pair<size_t,size_t> >& array);

const size_t width = 1920;
const size_t height = 1200;

size_t buf_s=0;
size_t buf_t=0;

char* name;

double coeff_x;
double coeff_y;

int main(int argc,char* argv[]) {
    std::vector<std::pair<size_t,size_t> > in_ar{};
    std::ifstream inp(argv[1]); if (!inp.is_open()) return 1;
    name = argv[2];
    while (!inp.eof())
    {
        size_t size; inp >> size;
        if (size==0) break;
        size_t time=0,buffer;
        for (size_t i=0;i<3;i++) {
            inp >> buffer;
            time+=(buffer/3);
        }
        if (size>buf_s) buf_s = size;
        if (time>buf_t) buf_t = time;
        in_ar.emplace_back(size,time);
    }
    coeff_x = (double)(width-1)/(double)buf_t;
    coeff_y = (double)(height-1)/(double)buf_s;

    //std::sort(in_ar.begin(),in_ar.end(),[](auto a,auto b) {return a.second < b.second;});

    draw(in_ar);
    return 0;
}

void draw(const std::vector<std::pair<size_t,size_t> >& array)
{
    bmp_writer graph;
    graph.create(name,width,height,24);

    for (auto el=array.begin(); el<array.end();el++)
    {
        graph.write_line(coeff_x*el->second,height-coeff_y*el->first,coeff_x*el->second,height-1,{255,255,255});
    }
    for (size_t i=50000;i<buf_s;i+=50000)
    {
        for (size_t j=0;j<5;j++) graph.write_line(1,height-coeff_y*i+j,20,height-coeff_y*i+j,{0,0,255});
    }

    for (size_t i=buf_t/20;i<buf_t-5/coeff_x;i+=buf_t/20)
    {
        for (size_t j=0;j<5;j++) graph.write_line(1+i*coeff_x+j,height-1,i*coeff_x+j,height-20,{0,0,255});
    }

    graph.wclose();
}
