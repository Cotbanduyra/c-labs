#include "static/forlab2_s.h"


int main(int argc, char** argv) {
    int mat1[MAX_LEN][MAX_LEN], mat2[MAX_LEN][MAX_LEN];
    size_t row1, col1, row2, col2;

    printf("Matrix 1:\n");
    enter_matrix(&mat1, &row1, &col1);

    printf("Matrix 2:\n");
    enter_matrix(&mat2, &row2, &col2);

    if (Check_matrix_rows(mat1, row1, col1))
        PrintRowProd(CalcMatrixInRow(mat1, row1, col1), row1);

    if (Check_matrix_rows(mat2, row2, col2))
        PrintRowProd(CalcMatrixInRow(mat2, row2, col2), row2);

    if (!Check_matrix_rows(mat1, row1, col1) && !Check_matrix_rows(mat2, row2, col2))
        printf("No zeros in either matrix\n");

    return 0;
}