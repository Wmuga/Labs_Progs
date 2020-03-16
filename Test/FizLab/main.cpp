#include <iostream>
#include <cmath>

int main() {
    double Umv,Uv,Ud;
    std::cin>>Umv>>Uv>>Ud;
    double e,dle,de;
    e = Uv*(Umv-Ud)/(Ud*(Umv-Uv));
    dle= sqrt(
            pow(Umv*0.03/(Uv*(Umv-Uv)),2) + pow(Umv*0.03/(Ud*(Umv-Ud)),2) + pow((Uv-Ud)*0.03/((Umv-Uv)*(Umv-Ud)),2)
            );
    de = e*dle;
    std::cout<< e << std::endl << dle << std::endl << de;
    return 0;
}