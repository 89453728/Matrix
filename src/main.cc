#include "cmplx.h"
#include <iostream>

using ff::Complex;
int main(){
    Complex a = 3 + 4*j;
    Complex c = a^3.44;
    Complex k = 10.223 ^ a;
    Complex b = (1-3*i) ^ (1 + 3*j);
    std::cout << "c: " << c << "\n";
    std::cout << "a: " << a << "\n" << "k: " << k << "\n";
    std::cout << "b: " << b << "\n";
    return 0;
}
