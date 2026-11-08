#include "forlab9.h"
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
    b = a;
    std::cout << "b = a\n" << b;
    
    
    a = std::move(b);
    std::cout << "a move(b)\n" << a;
    //*/
    a.GetAt(0, 0) = 1024;
    std::cout << "chnge el\n" << a;
    std::cout << "double " << double(a) << std::endl;

    a.FillMatrix();
        std::cout << "Inverted matrix:\n";
        a.Invert().PrintMatrix();
    return 0;
}