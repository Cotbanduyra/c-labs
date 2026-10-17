#pragma once
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> mat;

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
    Matrix(std::initializer_list<std::initializer_list<int>> init);
    Matrix(Matrix&& other) noexcept;

    ~Matrix();
    
    void FillMatrix();

    explicit operator double() const;
    Matrix& operator= (const Matrix& other);
    Matrix& operator= (Matrix&& other) noexcept;
    std::vector<int>& operator[] (size_t idx);
    const std::vector<int>& operator[] (size_t idx) const;
};

std::ostream& operator<< (std::ostream& os, const Matrix& obj);