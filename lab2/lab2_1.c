#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "forlab2.h"

int main(int argc, char** argv) {
    int **mat1, **mat2;
    size_t col1, col2, row1, row2;

    // Ввод первой матрицы
    enter_matrix(&mat1, &row1, &col1);
    // Ввод второй матрицы
    enter_matrix(&mat2, &row2, &col2);

    if (Check_matrix(mat1, row1, col1)) {
        int pr;
        for (size_t i = 0; i < row1; i++) {
            pr = Calc_row(mat1[i], col1);
            if (pr != 0)
                printf("Proizved of %zu row of mat1 is: %d\n", i, pr);
            else
                printf("in row %zu of mat1 no elem exept nulls\n", i);
        }
    }

    if (Check_matrix(mat2, row2, col2)) {
        int pr;
        for (size_t i = 0; i < row2; i++) {
            pr = Calc_row(mat2[i], col2);
            if (pr != 0)
                printf("Proizved of %zu row of mat2 is: %d\n", i, pr);
            else
                printf("in row %zu of mat2 no elem exept nulls\n", i);
        }
    }
    else
        printf("no zeros in both matrix\n");

    return 0;
}