#pragma once
#include <iostream>

typedef int** mat;

class Matrix{
private:
    mat matrix;
    int rows, cols;
public:
    int GetRows() const;
    int GetCols() const;
    mat GetMat()  const;
    int& GetAt(size_t i, size_t j);
    const int& GetAt(size_t i, size_t j) const;
    
    Matrix();
    Matrix(int rows, int cols);
    explicit Matrix(int val);
    Matrix(const Matrix& other, int gap = 0);
//  Matrix(std::initializer_list<std::initializer_list<int>> init);
    Matrix(Matrix&& other) noexcept;

    ~Matrix();
    
    void FillMatrix();
    void PrintMatrix();
    double GetAvarage();
    
    Matrix& Invert();//obratnay matrix

    ///*
    explicit operator double() const;
    Matrix& operator= (const Matrix& other);
    Matrix& operator= (Matrix&& other) noexcept;
    int*& operator[] (size_t idx);
    int* const& operator[] (size_t idx) const;
    Matrix operator+ (const Matrix& other);
    Matrix operator- (const Matrix& other);
    Matrix& operator+= (const int& k);
//*/
};
///*
std::ostream& operator<< (std::ostream& os, const Matrix& obj);
std::istream& operator>> (std::istream& os, Matrix& obj);
//*/