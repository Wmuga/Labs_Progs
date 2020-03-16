void PreInit(int** matrix, int n)
{
    for (int i=0; i<n;i++) matrix[i]=new int[n];
}

void MatrixInit(int** matrix, int n, FILE* pFile)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)  fscanf(pFile,"%d",&matrix[i][j]);
        printf("\n");
    }
}


void fgetSeq(FILE *pFileIn,int* seq,int n)
{
    for (int i =0; i<n; i++) fscanf(pFileIn,"%d",&seq[i]);
}

void foutSeq(FILE* pFile,int* seq,int length, char delim)
{
    fprintf(pFile,"%3d",seq[0]);
    for (int i=1;i<length;i++) fprintf(pFile,"%c%3d",delim,seq[i]);
    fprintf(pFile,"\n");
}

int Count(int* line, int n)
{
    int sum=0;
    for (int i=0;i<n;i++) sum+=line[i];
    return sum;
}

bool CheckAndEdit(int** matrix, int n,int* buf,FILE* pFile)
{
    int sum,i=0;
    bool flag=true;
    while (i < n && flag)
    {
        sum=Count(matrix[i],n);
        if (sum >= buf[i]) flag=false;
        i++;
    }
    if (flag)
        for (i = 0; i < n; i++) buf[i] = Count(matrix[i], n);
    if (!flag)  fprintf(pFile,"%d-й элемент последовательности не превосходит сумму элемнтов соответствующей строки",i);
    return flag;
}

void Finallization(int** matrix, int n,int* buf)
{
    for (int i=0; i<n;i++) delete []matrix[i];
    delete []buf;
}