#include "forlab2_v.h"


void Init_matrix(int*** matr, size_t row, size_t col) {
    *matr = (int**)calloc(row, sizeof(int*));
    for (size_t i = 0; i < row; i++)
        (*matr)[i] = (int*)calloc(col, sizeof(int));
    return;
}

void enter_matrix(FILE* from, int*** matr, size_t* row, size_t* col) {
    fscanf(from, "%zu %zu", row, col);

    Init_matrix(matr, *row, *col);
    for (size_t i = 0; i < *row; i++) {
        for (size_t j = 0; j < *col; j++) {
            fscanf(from, "%d", &(*matr)[i][j]);
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
    return;
}

///////////Vectors/////////////////

void CalcMatrixInRow(int** matr, size_t row, size_t col){
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


void CalcMatrix(int** mat, size_t row, size_t col, int** res){
    *res = (int*) calloc(row, sizeof(int));
    for (int i = 0; i < row; i++){
        int pr = 1;
        bool has_not_null = false;
        for (int j = 0; j < col; j++ ){
            if (mat[i][j] != 0){
                has_not_null = true;
                pr *= mat[i][j];
            }
        }
        (*res)[i] = has_not_null ? pr : 0;
    }
    return;
}


///////////////////////////////////////////////
///////////////// ZASHITA /////////////////////
///////////////////////////////////////////////

bool CheckDims( size_t row, size_t col){
    return (row == col) && (row > 1);
}

int ClalcDiag(int** mat, size_t row, size_t col){
    int res = 0;
    for (int i = 0; i < row - 1; i++){
        for(int j = i + 1; j < col; j++){
            res += mat[i][j];
        }
    }
    return res;
}

void SwapDiag(int*** mat, size_t row, size_t col){
    int buf = 0;
    for (int i = 0; i < row; i++){
        buf = (*mat)[i][i];
        (*mat)[i][i] = (*mat)[row - 1 - i] [i];
        (*mat)[row - 1 - i][i] = buf;
    }
    return;
}

int CalcDiagRow(int** mat, size_t row, size_t col){
    int sum = 0;
    for (int i = 0; i < row - 1; i++)
        sum += CalcDiagInRow(mat[i], i, col);
    return sum;
}

int CalcDiagInRow(int* row, int idx, size_t col){
    int sum = 0;
    for (int i = idx + 1; i < col; i++)
        sum += row[i];
    return sum;
}

void SwapInRow(int*** mat, size_t row, size_t col){
    for (int i = 0; i < row; i++)
        SwapRow(&(*mat)[i], col, i);
}

void SwapRow(int** row, int col, int idx){
    int temp = (*row)[idx];
    (*row)[idx] = (*row)[(col - 1) - idx];
    (*row)[(col - 1) - idx] = temp;
    return;
}

void PrintMatr(int** mat, size_t row, size_t col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return;
}