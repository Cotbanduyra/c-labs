#include "forlab2_v.h"


void Init_matrix(int*** matr, size_t row, size_t col) {
    *matr = (int**)calloc(row, sizeof(int*));
    for (size_t i = 0; i < row; i++)
        (*matr)[i] = (int*)calloc(col, sizeof(int));
    return;
}

void enter_matrix(int*** matr, size_t* row, size_t* col) {
    printf("Enter rows and cols: ");
    bool correct_dims = 0;
    while (!correct_dims) {
        scanf("%d %d", row, col);
        if (row <= 0 || col <= 0)
            printf("Wrong dims. Try again\n");
        else
            correct_dims = 1;
    }

    Init_matrix(&matr, *row, *col);
    for (size_t i = 0; i < *row; i++) {
        for (size_t j = 0; j < *col; j++) {
            scanf("%d", &(*matr)[i][j]);
        }
    }
    return;
}


void PrintRowProd(int* res, size_t row){
    for (size_t i = 0; i < row; i++){
        if (res[i] != 0)
            printf("Proizved of %zu row of mat2 is: %d\n", i, res[i]);
        else
            printf("in row %zu of mat2 no elem exept nulls\n", i);
    }
}

///////////Vectors/////////////////

int* CalcMatrixInRow(int** matr, size_t row, size_t col){
    int* res;
    res = (int*) calloc(row, sizeof(int));
    for (size_t i = 0; i < row; i++) {
        res[i] = Calc_row(matr[i], col);
    }
    return res;
}


int Calc_row(int* row, size_t cols) {
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


bool CheckRow(int* row, size_t col){
    bool was_find = false;
    for (size_t j = 0; !was_find && j < col; j++) {
        if (row[j] == 0) {
            was_find = true;
        }
    }
    return was_find;
}


bool Check_matrix_rows(int** mat, size_t row, size_t col) {
    bool was_find = false;
    for (size_t i = 0; !was_find && i < row; i++) {
        if (CheckRow(mat[i], col))
            was_find = true;
    }
    return was_find;
}

//////////////////Matrix//////////////////////

bool Check_matrix(int** mat, size_t row, size_t col) {
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


int* CalcMatrix(int** mat, size_t row, size_t col){
    int* res = (int*) calloc(row, sizeof(int));
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
    return res;
}