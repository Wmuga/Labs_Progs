#include <iostream>
#include <cmath>

bool RCheckElems(double *a,int start, int end)
{
    bool  res = false;
    if (start>end) start=end;
    if (start==end) {
        res = pow((int)a[start],2)/(end+1)>2;
        if (res) {
            std::cout << start + 1 << " element is cool\n";
        }else{}
        }
    else
    {
        double oot = (end-start)/3.0;
        res = RCheckElems(a,start,(trunc(oot))+start);
        if (!res) res = RCheckElems(a,ceil(oot)+start,trunc(oot*2)+start);
        if (!res) res = RCheckElems(a,ceil(oot*2)+start,end);
    }
    return res;
}

int main() {
    double* a = new double[9]; a[0]=0.9; a[1]=0.1; a[2]=1.4; a[3]=1.9; a[4]=1.0; a[5]=0.1; a[6]=3.2; a[7]=0.1; a[8]=2;
    if(!RCheckElems(a,0,8)) std::cout<<"Welp";
    return 0;
}