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
    Matrix(int val);
    Matrix(const Matrix& other, int gap = 0);
    Matrix(Matrix&& other) noexcept;

    ~Matrix();
    ///*
    Matrix& operator= (const Matrix& other);
    Matrix& operator= (Matrix&& other) noexcept;
    Vector& operator[] (size_t idx);
    Vector const& operator[] (size_t idx) const;
    
    friend Matrix operator+ (const Matrix& first, const Matrix& second);
    friend Matrix operator- (const Matrix& first, const Matrix& second);
    friend Matrix operator* (const Matrix& first, const Matrix& second);

    friend bool operator== (const Matrix& first, const Matrix& second);
    friend bool operator!= (const Matrix& first, const Matrix& second);
    friend bool operator> (const Matrix& first, const Matrix& second);
    friend bool operator< (const Matrix& first, const Matrix& second);
    friend bool operator<= (const Matrix& first, const Matrix& second);
    friend bool operator>= (const Matrix& first, const Matrix& second);
    //bool operator== (const int& k) const;
    //bool operator!= (const int& k) const;
    
    Matrix& operator-= (const int& k);
    Matrix& operator+= (const int& k);
    Matrix& operator*= (const int& k);
    Matrix& operator-= (const Matrix& k);
    Matrix& operator+= (const Matrix& k);
    Matrix& operator*= (const Matrix& k);
    Matrix operator~() const;


    friend std::ostream& operator<< (std::ostream& os, const Matrix& obj);
    friend std::istream& operator>> (std::istream& is, Matrix& obj);

//*/
};
///*
//*/