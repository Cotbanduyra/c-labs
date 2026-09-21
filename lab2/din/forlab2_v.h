#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void enter_matrix(int*** matr, size_t* row, size_t* col);

void PrintRowProd(int* res, size_t row);

int Calc_row(int* row, size_t cols);

int* CalcMatrixInRow(int** matr, size_t row, size_t col);

bool CheckRow(int* row, size_t col);

bool Check_matrix_rows(int** mat, size_t row, size_t col);

bool Check_matrix(int** mat, size_t row, size_t col);

int* CalcMatrix(int** mat, size_t row, size_t col);