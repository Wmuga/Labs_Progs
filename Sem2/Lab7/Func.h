#include <cstdlib>

char* catType[] = {(char*)"Siam",(char*)"Test"};

struct Cat
{
    int     type;
    char    name[30];
    char    color[30];
    int     age;
    char    OSName[30];
    int     place;
};

void CreateNew(char* in, char* out)
{
    FILE* inp  = fopen(in,"r");
    FILE* outp = fopen(out,"wb");
    int count = 0;
    while (true)
    {
        Cat newCat;
        char buffer[3];
        fscanf(inp,"%s",buffer);  newCat.type = atoi(buffer);
        if (newCat.type==0 || feof(inp)) break;
        fscanf(inp,"%30s",newCat.name);
        fscanf(inp,"%30s",newCat.color);
        fscanf(inp,"%s",buffer); newCat.age = atoi(buffer);
        fscanf(inp,"%30s",newCat.OSName);
        fscanf(inp,"%s",buffer); newCat.place = atoi(buffer);
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
    FILE* pFBin = fopen(file,"rb");
    int count=0;
    while (true)
    {
        Cat newCat;
        fread(&newCat, sizeof(newCat),1,pFBin);
        if (feof(pFBin)) break;
        printf("Cat N %d:\n  Name:%s\n  Type:%s\n  Age:%d\n  Owner name:%s\n  Place:%d\n",
                count+1,newCat.name,catType[newCat.type-1],newCat.age,newCat.OSName,newCat.place);
        count++;
    }
    fclose(pFBin);
    if (count==0) printf("EmptyFile\n");
    printf("-------------------------------\nPress any key to continue");
    fgetc(stdin); fflush(stdin);
}

void SearchContent(char* file)
{
    int i=-1,count=0;
    Cat newCat;
    FILE* pFBin = fopen(file,"rb");
    int av_age=0;
    do
    {
        i++;
        fread(&newCat, sizeof(newCat),1,pFBin);
        if (newCat.type==1 and newCat.place<=10) {
            count++;
            printf("Found cat:\n  Name:%s\n  Type:%s\n  Age:%d\n  Owner name:%s\n  Place:%d\n",
                    newCat.name,"Siam",newCat.age,newCat.OSName,newCat.place);
            av_age+=newCat.age;
        }
    }while(!feof(pFBin));
    fclose(pFBin);
    if (i==0) printf("EmptyFile\n");
    else printf("Average age of these cats is %d\n",av_age/count);
    printf("-------------------------------\nPress any key to continue");
    fgetc(stdin); fflush(stdin);
}

void ChangeContent(char* file)
{
    int i=-1,count=0;
    Cat newCat;
    FILE* pFBin = fopen(file,"rb+");
    do
    {
        bool flag=false;
        i++;
        fread(&newCat, sizeof(newCat),1,pFBin);
        if (newCat.age<0)   {newCat.age=0; flag=true;}
        if (newCat.age>15)  {newCat.age=15; flag=true;}
        if (newCat.place<0) {newCat.place=abs(newCat.place); flag=true;}
        if (flag)
        {
            printf("Corrected %d record:\n  Name:%s\n  Type:%s\n  Age:%d\n  Owner name:%s\n  Place:%d\n",
                    i,newCat.name,catType[newCat.type-1],newCat.age,newCat.OSName,newCat.place);
            count++;
        }
    }while(!feof(pFBin));
    fclose(pFBin);
    if (i==0) printf("EmptyFile\n");
    if (count==0) printf("Needless in correction\n");
    else printf("Mad %d corrections\n",count);
    printf("-------------------------------\nPress any key to continue");
    fgetc(stdin); fflush(stdin);
}