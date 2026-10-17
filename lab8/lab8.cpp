#include "forlab8.h"
#include <iostream>


int main(int argc, char** argv){
    
    Matrix a({{1, 2}, {3, 4}});
    Matrix b(1, 2);

    std::cout << "a\n" << a;
    std::cout << "b\n" << b;
    
    b.FillMatrix();
    std::cout << "b after person input\n" << b;

    b = a;
    std::cout << "b = a\n" << b;
    
    a = {{4, 3, 2}, {1, 0, -1}};
    std::cout << "a from initializer_list\n" << a;
    
    a = std::move(b);
    std::cout << "a move(b)\n" << a;
    
    a[0][0] = 1024;
    std::cout << "chnge el\n" << a;
    std::cout << "double " << double(a) << std::endl;;
    return 0;
}