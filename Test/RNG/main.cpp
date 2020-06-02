#include <cstdio>
#include <ctime>
#include <cstdlib>
int main() {
    srand(time(nullptr));
    //Путь измени на свой (первое) два слеша т.к. первый отвечает за то, что указывается спец сиивол, второй - какой
    FILE *out = fopen("D:\\Documents\\GitHub\\Labs_Progs\\Sem2\\StudPractice\\input.txt","w");
    // размер массива
    size_t array_size;
    //array_size = rand()%70+30; // от 30 до 100
    array_size = 100; //вручную
    fprintf(out,"%d\n",array_size);
    for (size_t i = 0; i<array_size;i++)
    {
        fprintf(out,"%d ",rand()%100+15); // выводим от +1 - нижний предел до %50 - верхний (изменить числа - другие пределы)
    }
    fclose(out);
    return 0;
}
