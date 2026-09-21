#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 20


void enter_matrix(int (*matr)[MAX_LEN][MAX_LEN], size_t* row, size_t* col);

int* CalcMatrixInRow(int matr[MAX_LEN][MAX_LEN], size_t row, size_t col);

int Calc_row(int row[MAX_LEN], size_t cols);

bool CheckRow(int row[MAX_LEN], size_t col);

bool Check_matrix_rows(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col);

bool Check_matrix(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col);

int* CalcMatrix(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col);