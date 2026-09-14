#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void enter_matrix(int** matr, size_t* row, size_t* col);

int Calc_row(const int* row, size_t cols);

bool Check_matrix(int **mat, size_t row, size_t col);