#include <cmath>
#include <cstdio>
#include <cstdlib>

struct data
{
    char* i;
};

int main() {
    int pos =2;
    FILE *pTest = fopen("D:\\Documents\\GitHub\\Labs_Progs\\Test\\RadomTest\\test.bin","wb+");
    data pog = {(char*)"Pepega"};
    /*
    fseek(pTest,sizeof(data),SEEK_SET);
    fwrite(&pog, sizeof(data),1,pTest);
    fseek(pTest,3*sizeof(data),SEEK_SET);
    fwrite(&pog, sizeof(data),1,pTest);
    fseek(pTest, 6*sizeof(data),SEEK_SET);
    data poggers;
    fread(&poggers,sizeof(data),1,pTest);
    if (poggers.i==nullptr) printf("poggers");
     */
    fseek(pTest,pos*sizeof(data),SEEK_SET);
    fwrite(&pog, sizeof(data),1,pTest);
    fseek(pTest,(pos*2+1)*sizeof(data),SEEK_SET);
    data poggers;
    fread(&poggers,sizeof(data),1,pTest);
    if (!poggers.i) printf("poggers");
    else printf("%s",poggers.i);
    fclose(pTest);
    return 0;
}
