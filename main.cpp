#include <iostream>
#include "rational.h"


int main(int argc, char** argv)
{	
    Rational r1(1, 2);
    Rational r2(4, 8);
    Rational r3(10);

    std::cout << (+r1).to_double() << std::endl; //0.5
    std::cout << (-r2).to_double() << std::endl; //-0.5
    std::cout << (r1 + r2).to_double() << std::endl; //1
    std::cout << (r1 + r3).to_double() << std::endl; //10.5
    std::cout << (r1 - r3).to_double() << std::endl; //-9.5
    std::cout << (r1 * r3).to_double() << std::endl; //5
    std::cout << (r3 / r2).to_double() << std::endl; //20

    std::cout << (r3 > r2) << std::endl; //true
    std::cout << (r2 < r1) << std::endl; //false
    std::cout << (r2 >= r1) << std::endl; //true
    std::cout << (r3 != r2) << std::endl; //true
}
