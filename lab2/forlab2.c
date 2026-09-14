#include "forlab2.h"


void Init_matrix(int ***matr, size_t row, size_t col) {
    *matr = (int**)malloc(sizeof(int*) * row);
    for (size_t i = 0; i < row; i++) {
        (*matr)[i] = (int*)malloc(sizeof(int) * col);
        for (size_t j = 0; j < col; j++)
            (*matr)[i][j] = 1;
    }
}

// Ввод матрицы
void enter_matrix(int** matr, size_t* row, size_t* col) {
    printf("Enter rows and cols: ");
    bool correct_dims = 0;
    int r, c;
    while (!correct_dims) {
        scanf("%d %d", &r, &c);
        if (r <= 0 || c <= 0)
            printf("Wrong dims. Try again\n");
        else
            correct_dims = 1;
    }
    *row = (size_t)r;
    *col = (size_t)c;

    Init_matrix(matr, *row, *col);
    for (size_t i = 0; i < *row; i++) {
        for (size_t j = 0; j < *col; j++) {
            scanf("%d", &(matr)[i][j]);
        }
    }
}

// Вычисление произведения ненулевых элементов строки
int Calc_row(const int* row, size_t cols) {
    int proizved = 1;
    bool has_not_null = false;
    for (size_t i = 0; !has_not_null && i < cols; i++) {
        if (row[i] != 0) has_not_null = true;
    }
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

// Проверка наличия нулей в матрице
bool Check_matrix(int **mat, size_t row, size_t col) {
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