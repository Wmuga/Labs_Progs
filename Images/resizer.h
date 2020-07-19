#include <vector>
#include "bmp.h"
class resizer
{
public:
    void resize(char* img_in, char* img_out,size_t new_width,size_t new_height);

    void increase_height_smart(char* img_in, char* img_out);

    void increase_width_smart(char* img_in, char* img_out);

    void increase_smart(char* img_in, char* img_out);

    void liquid_resize(char*,char*);
private:
    std::vector<std::vector<int> > energy_array;
    std::vector<std::vector<int> > energy_path_array;
    std::vector<std::pair<int,int> > line_coords;

    void draw_energy_pallet(bmp_writer&);
    void get_energy_pallet(bmp_reader);
    void get_paths_array(size_t, size_t);
    void get_path(size_t, size_t);
    void write_line(bmp_reader,bmp_writer&);

};