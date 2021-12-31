#include "cmplx.h"
#include <iostream>

using ff::Complex;
int main(){
    Complex a = Complex();
    Complex b(10,11);
    a = a + b;
    a *= a;
    a = a + 10.22;
    a = 12.33 + a;
    a *= i;
    std::cout << b;
    std::cout << a;
    return 0;
}
