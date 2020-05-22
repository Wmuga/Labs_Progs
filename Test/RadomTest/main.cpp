#include <cmath>
#include <cstdio>
#include <cstdlib>

struct data
{
    char* i;
};

int main() {
    FILE *pTest = fopen("D:\\Documents\\GitHub\\Labs_Progs\\Test\\RadomTest\\test.bin","wb+");
    data pog = {(char*)"poggers"};
    fwrite(&pog, sizeof(data),1,pTest);
    fseek(pTest,sizeof(data),SEEK_CUR);
    fwrite(&pog, sizeof(data),1,pTest);
    fseek(pTest,0 - 2*sizeof(data),SEEK_CUR);
    data poggers;
    fread(&poggers,sizeof(data),1,pTest);
    if (poggers.i==nullptr) printf("poggers");
    fclose(pTest);
    return 0;
}
