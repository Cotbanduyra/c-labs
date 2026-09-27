#include "din/forlab2_v.h"

void main(int argc, char* argv[]){
    int **mat1 , **mat2 ;
    size_t row1, col1, row2, col2;

    FILE* f = fopen(argv[1], "r");

    enter_matrix(f, &mat1, &row1, &col1);

    enter_matrix(f, &mat2, &row2, &col2);

    bool corr1 = CheckDims(row1, col1);
    bool corr2 = CheckDims(row2, col2);

    if (corr1 && corr2){
        int sum1;
        sum1 = ClalcDiag(mat1, row1, col1);

        int sum2;
        sum2 = ClalcDiag(mat2, row2, col2);
        if(sum1 == sum2){
            SwapDiag(&mat1, row1, col1);
            SwapDiag(&mat2, row2, col2);
            PrintMatr(mat1, row1, col1);
            printf("\n");
            PrintMatr(mat2, row2, col2);
        }
        else if (sum1 > sum2){
            SwapDiag(&mat1, row1, col1);
            PrintMatr(mat1, row1, col1);
        }
        else{
            SwapDiag(&mat2, row2, col2);
            PrintMatr(mat2, row2, col2);
        }
    } else if (corr1){
        SwapDiag(&mat1, row1, col1);
        PrintMatr(mat1, row1, col1);
    }
    else if (corr1){
        SwapDiag(&mat1, row1, col1);
        PrintMatr(mat1, row1, col1);
    } else if (corr2){
        SwapDiag(&mat2, row2, col2);
        PrintMatr(mat2, row2, col2);
    } else{
        printf("NO");
    }
    
}