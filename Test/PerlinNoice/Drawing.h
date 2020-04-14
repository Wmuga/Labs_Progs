#include <cmath>
void DrawFloatLine(int expanding, float* fArray, int arraySize=256){
    for (int i=0;i<arraySize;i++){
        for (int j=0;j<floor(fArray[i]*pow(10, expanding)); j++) printf("@");
        printf("\n");
    }
}
