#pragma once
#include <iostream>
#include "labvector.h"

typedef Vector* mat;

class Matrix{
private:
    mat matrix;
    int rows, cols;
public:
    int GetRows() const;
    int GetCols() const;
    mat GetMat()  const;
    
    Matrix();
    Matrix(int rows, int cols);
    explicit Matrix(int val);
    Matrix(const Matrix& other, int gap = 0);
    Matrix(Matrix&& other) noexcept;

    ~Matrix();
    Matrix& Invert();//obratnay matrix

    ///*
    Matrix& operator= (const Matrix& other);
    Matrix& operator= (Matrix&& other) noexcept;
    Vector& operator[] (size_t idx);
    Vector const& operator[] (size_t idx) const;
    Matrix operator+ (const Matrix& other) const;
    Matrix operator- (const Matrix& other) const;
    Matrix operator* (const Matrix& other) const;
    Matrix& operator+= (const int& k);

//*/
};
///*
std::ostream& operator<< (std::ostream& os, const Matrix& obj);
std::istream& operator>> (std::istream& is, Matrix& obj);
//*/