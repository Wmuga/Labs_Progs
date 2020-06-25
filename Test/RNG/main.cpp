#include <cstdio>
#include <ctime>
#include <cstdlib>
int main() {
    srand(time(nullptr));
    //Путь измени на свой (первое) два слеша т.к. первый отвечает за то, что указывается спец сиивол, второй - какой
    FILE *out = fopen("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractiseLog\\input.txt","w");
    // размер массива
    size_t array_size;
    array_size = 10000000; //вручную
    fprintf(out,"%d\n",array_size);
    for (size_t i = 0; i<array_size;i++)
    {
        fprintf(out,"%d ",rand()%200-100);
    }
    fclose(out);
    return 0;
}
