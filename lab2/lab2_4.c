#include "din/forlab2_v.h"

int main(int argc, char** argv) {
    int **mat1 , **mat2 ;
    size_t row1, col1, row2, col2;

    FILE* f = fopen(argv[1], "r");

    enter_matrix(f, &mat1, &row1, &col1);

    enter_matrix(f, &mat2, &row2, &col2);

    if (Check_matrix_rows(mat1, row1, col1))
        CalcMatrixInRow(mat1, row1, col1);

    if (Check_matrix_rows(mat2, row2, col2)) 
        CalcMatrixInRow(mat2, row2, col2);

    if (!Check_matrix_rows(mat1, row1, col1) && !Check_matrix_rows(mat2, row2, col2))
        printf("No zeros in either matrix\n");

    return 0;
}