#include "forlab2_v.h"

int main(int argc, char** argv) {
    int **mat1 = NULL, **mat2 = NULL;
    size_t row1, col1, row2, col2;

    printf("Matrix 1:\n");
    enter_matrix(&mat1, &row1, &col1);

    printf("Matrix 2:\n");
    enter_matrix(&mat2, &row2, &col2);

    if (Check_matrix(mat1, row1, col1))
        PrintRowProd(CalcMatrix(mat1, row1, col1), row1);

    if (Check_matrix(mat2, row2, col2)) 
        PrintRowProd(CalcMatrix(mat2, row2, col2), row2);

    if (!Check_matrix(mat1, row1, col1) && !Check_matrix(mat2, row2, col2))
        printf("No zeros in either matrix\n");

    return 0;
}