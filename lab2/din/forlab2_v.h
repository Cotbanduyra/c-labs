#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void enter_matrix(FILE* from, int*** matr, size_t* row, size_t* col);

void PrintRowProd(int* res, size_t row);

int Calc_row(int* row, size_t cols);

void CalcMatrixInRow(int** matr, size_t row, size_t col);

bool CheckRow(int* row, size_t col);

bool Check_matrix_rows(int** mat, size_t row, size_t col);

bool Check_matrix(int** mat, size_t row, size_t col);

void CalcMatrix(int** mat, size_t row, size_t col, int** res);

bool CheckDims( size_t row, size_t col);

int ClalcDiag(int** mat, size_t row, size_t col);

void SwapDiag(int*** mat, size_t row, size_t col);

void PrintMatr(int** mat, size_t row, size_t col);