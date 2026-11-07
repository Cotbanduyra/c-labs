#include "forlab10.h"
#include <iostream>


int main(int argc, char** argv){
    
    std::cout << argc << "  " << argv[0]; 

    Matrix a(3, 3);
    Matrix b(a, 5);

    std::cout << "a\n"; a.PrintMatrix();
    std::cout << "b\n"; b.PrintMatrix();
    
    b.FillMatrix();

    std::cout << "b after person input\n"; b.PrintMatrix();

    ///*
    a = b;
    std::cout << "a = b\n" << a;
    
    
    a = std::move(b);
    std::cout << "a move(b)\n" << a;
    //*/
    a.GetAt(0, 0) = 1024;
    a[1][2] = -564;
    b = Matrix(a, 10);
    a += 5;
    std::cout << "chnge el\n" << a;
    std::cout << "double " << double(a) << std::endl;

    std::cout << "a\n" << a << "b\n" << b;
    std::cout << "a + b" << a+b;

    return 0;
}