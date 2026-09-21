#include "forlab2_s.h"

void enter_matrix(int (*matr)[MAX_LEN][MAX_LEN], size_t* row, size_t* col) {
    printf("Enter rows and cols: ");
    bool correct_dims = 0;
    while (!correct_dims) {
        scanf("%d %d", row, col);
        if (row <= 0 || row > MAX_LEN || col <= 0 || col > MAX_LEN)
            printf("Wrong dims. Try again\n");
        else
            correct_dims = 1;
    }
    
    for (size_t i = 0; i < *row; i++) {
        for (size_t j = 0; j < *col; j++) {
            scanf("%d", &(*matr)[i][j]);
        }
    }
    return;
}

///////////Vectors/////////////////

int* CalcMatrixInRow(int matr[MAX_LEN][MAX_LEN], size_t row, size_t col){
    int* res;
    res = (int*) calloc(row, sizeof(int));
    for (size_t i = 0; i < row; i++) {
        res[i] = Calc_row(matr[i], col);
    }
    return res;
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


int* CalcMatrix(int mat[MAX_LEN][MAX_LEN], size_t row, size_t col){
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