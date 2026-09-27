#include "forlab2_s.h"

void enter_matrix(FILE* from, int (*matr)[MAX_LEN][MAX_LEN], size_t* row, size_t* col) {
    fscanf(from, "%zu %zu", row, col);
    
    for (size_t i = 0; i < *row; i++) {
        for (size_t j = 0; j < *col; j++) {
            fscanf(from, "%d", &(*matr)[i][j]);
        }
    }
    return;
}


void PrintRowProd(int res[MAX_LEN], size_t row){
    for (size_t i = 0; i < row; i++){
        if (res[i] != 0)
            printf("Proizved of %zu row of mat2 is: %d\n", i, res[i]);
        else
            printf("in row %zu of mat2 no elem exept nulls\n", i);
    }
    return;
}

///////////Vectors/////////////////


void CalcMatrixInRow(int matr[MAX_LEN][MAX_LEN], size_t row, size_t col){
    int res;
    for (size_t i = 0; i < row; i++) {
        res = Calc_row(matr[i], col);
        if (res != 0)
            printf("Proizved of %d row of mat2 is: %d\n", i, res);
        else
            printf("in row %d of mat2 no elem exept nulls\n", i);
    }
    return;
}


int Calc_row(int row[MAX_LEN], size_t cols) {
    int proizved = 1;
    bool has_not_null = CheckRow(row, cols);
    if (has_not_null) {
        for (size_t i = 0; i < cols; i++)
            if (row[i] != 0) {
                proizved *= row[i];
            }
    }
    else
        proizved = 0;
    return proizved;
}


bool CheckRow(int row[MAX_LEN], size_t col){
    bool was_find = false;
    for (size_t j = 0; !was_find && j < col; j++) {
        if (row[j] == 0) {
            was_find = true;
        }
    }
    return was_find;
}


bool Check_matrix_rows(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col) {
    bool was_find = false;
    for (size_t i = 0; !was_find && i < row; i++) {
        if (CheckRow(mat[i], col))
            was_find = true;
    }
    return was_find;
}

//////////////////Matrix//////////////////////

bool Check_matrix(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col) {
    bool was_find = false;
    for (size_t i = 0; !was_find && i < row; i++) {
        for (size_t j = 0; !was_find && j < col; j++) {
            if (mat[i][j] == 0) {
                was_find = true;
            }
        }
    }
    return was_find;
}


void CalcMatrix(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col, int res[MAX_LEN]){
    for (int i = 0; i < row; i++){
        int pr = 1;
        bool has_not_null = false;
        for (int j = 0; j < col; j++ ){
            if (mat[i][j] != 0){
                has_not_null = true;
                pr *= mat[i][j];
            }
        }
        res[i] = has_not_null ? pr : 0;
    }
    return;
}