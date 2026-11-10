#include "forlab9.h"
#include <iostream>


int main(int argc, char** argv){
    
    Matrix a(3, 3);
    Matrix b(a, 5);

    std::cout << "a\n" << a;
    std::cout << "b\n" << b;

    std::cin >> b;

    std::cout << "b after person input\n" << b;

    ///*
    a = b;
    std::cout << "a = b\n" << a;
    
    
    a = std::move(b);
    std::cout << "a move(b)\n" << a;
    //*/
    a[1][2] = -564;
    b = Matrix(a, 10);
    a += 5;
    std::cout << "chnge el\n" << a;
    std::cout << "a\n" << a << "b\n" << b;
    std::cout << "a + b\n" << a+b;
    std::cout << "(a + b) * a\n" << (a + b) * a;

    return 0;
}