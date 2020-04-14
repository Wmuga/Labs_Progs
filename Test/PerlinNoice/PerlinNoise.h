#include <algorithm>
#include <string>
#include <cstdio>
#include "Drawing.h"
#include <ctime>
class Perlin2d
{
public:
    void GenerateNoise()
    {
        UserCreate();
        PerlinNoise1D(nOutputSize, fNoiseSeed1D, 8, fPerlinNoise1D);
        DrawFloatLine(3,fPerlinNoise1D,25);
    }
private:
    float *fNoiseSeed1D = nullptr;
    float *fPerlinNoise1D = nullptr;
    int nOutputSize = 256;
    //int nOctaveCount = 1;

    bool UserCreate()
    {
        fNoiseSeed1D = new float[nOutputSize];
        fPerlinNoise1D = new float[nOutputSize];
        srand(time(0));
        for (int i=0;i<nOutputSize;i++) fNoiseSeed1D[i] = (float)rand() / (float)RAND_MAX;

        return  true;
    }

    void PerlinNoise1D(int nCount, float *fSeed, int nOctaves, float *fOutput)
    {
        //1D
        for(int x=0;x<nCount;x++)
        {
           float fNoise = 0.0f;
           float fScale = 1.0f;
           float fScaleAcc =0.0f;
           for (int o=0;o<nOctaves;o++)
           {
               int nPitch = nCount >> o;
               int nSample1 = (x/nPitch)*nPitch;
               int nSample2 = (nSample1 + nPitch) % nCount;

               float fBlend = (float)(x-nSample1)/(float)nPitch;
               float fSample = (1.0f - fBlend)*fSeed[nSample1]+fBlend*fSeed[nSample2];
               fNoise += fSample * fScale;
               fScaleAcc += fScale;
               fScale = fScale /2.0f;
           }
           fOutput[x] = fNoise/fScaleAcc;
        }
    }

};