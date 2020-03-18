#include <cstdlib>

struct Cat
{
    int type;
    char*    name;
    char*    color;
    int      age;
    char*    OSName;
    int      place;
};

void CreateNew(char* in, char* out)
{
    FILE* inp  = fopen(in,"r");
    FILE* outp = fopen(out,"wb");
    int count = 0;
    Cat newCat{};
    while (true)
    {
        char buffer[3];
        fscanf(inp,"%s",&buffer);  newCat.type = atoi(buffer);
        if (newCat.type==0 || feof(inp)) break;
        fscanf(inp,"%s",&newCat.name);
        fscanf(inp,"%s",&newCat.color);
        fscanf(inp,"%s",&buffer); newCat.age = atoi(buffer);
        fscanf(inp,"%s",&newCat.OSName);
        fscanf(inp,"%s",&buffer); newCat.place = atoi(buffer);
        fwrite(&newCat, sizeof(Cat),1,outp);
        count++;
    }
    fclose(inp);
    fclose(outp);
    if (count==0) printf("Created empty file\n");
    else printf("Created file with %d records\n",count);
    printf("-------------------------------\nPress any key to continue");
    fgetc(stdin); fflush(stdin);
}

void ViewBinary(char* file)
{
    char* catType[] = {(char*)"Siam",(char*)"Test"};
    FILE* pFBin = fopen(file,"rb");
    int count=0;
    while (true)
    {
        Cat newCat;
        fread(&newCat, sizeof(newCat),1,pFBin);
        if (feof(pFBin)) break;
        printf("Cat N %d:\n  Name:%s\n  Type:%s\n  Age:%d\n  Owner name:%s\n  Place:%d\n",
                count+1,newCat.name,catType[newCat.type],newCat.age,newCat.OSName,newCat.place);
        count++;
    }
    if (count==0) printf("EmptyFile\n");
    printf("-------------------------------\nPress any key to continue");
    fgetc(stdin); fflush(stdin);
}

void SearchContent(char* file)
{

}

void ChangeContent(char* file)
{

}