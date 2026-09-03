#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct matrix{
    int** matr;
    size_t row, col;
};

bool Check_matrix(const struct matrix* matr);

void Init_matrix(struct matrix* ar);

void enter_matrix(struct matrix* matr){
    printf("Enter rows and cols: ");
    bool correct_dims = 0;
    while (!correct_dims){
        scanf("%d %d", &(matr->row), &(matr->col));
        if(matr -> row <= 0 || matr -> col <= 0) printf("Wrong dims. Try again\n"); // size_t - беххнаковый и ввод числа <0 вызывает segment fault(на компе)
        else correct_dims = 1;
    }
    Init_matrix(matr);
    for (int i = 0; i < matr -> row; i++){
        for (int j = 0; j < matr -> col; j++){
            scanf("%d", &matr->matr[i][j]);
        }
    }
}

int Calc_row(const int* row, size_t cols);

void main(int argc, char** argv){
    struct matrix mat1, mat2;
    enter_matrix(&mat1);
    enter_matrix(&mat2);
    if (Check_matrix(&mat1)){
        int pr;
        for (int i = 0; i < mat1.row; i++ ){
            pr = Calc_row(mat1.matr[i], mat1.col);
            if (pr != 0)
                printf("Proizved of %d row of mat1 is: %d\n", i, Calc_row(mat1.matr[i], mat1.col));
            else
                printf("in row %d of mat1 no elem exept nulls\n`");
        }
    }
    if (Check_matrix(&mat2)){
        int pr;
        for (int i = 0; i < mat2.row; i++ ){
            pr = Calc_row(mat2.matr[i], mat2.col);
            if(pr != 0)
                printf("Proizved of %d row of mat2 is: %d\n", i, pr);
            else
                printf("in row %d of mat2 no elem exept nulls\n");
        }
    }
    else
        printf("no zeros in both matrix\n");
    return;
}

bool Check_matrix(const struct matrix* mat){
    bool was_find = false;
    for (int i = 0; !was_find && i < mat -> row; i++){
        for (int j = 0; !was_find && j < mat -> col; j++){
            if (mat -> matr[i][j] == 0){
                was_find = true;
            }
        }
    }
    return was_find;
}


void Init_matrix(struct matrix* ar ){
    ar -> matr = (int**) malloc(sizeof(int*) * ar->row);
    for (int i = 0; i < ar -> row; i++){
        ar -> matr[i] = (int*) malloc(sizeof(int) * ar->col);
        for(int j = 0; j < ar -> col; j++)
            ar -> matr[i][j] = 1;
    }
}

int Calc_row(const int* row, size_t cols){
    int proizved = 1;
    bool has_not_null = false;
    for (int i = 0; !has_not_null && i < cols; i++){
        if (row[i] != 0) has_not_null = true;
    }
    if (has_not_null)
        for (int i = 0; i < cols; i++)
            if (row[i] != 0){
              //printf("%d %d %d",cols, i, row[i]);
                proizved *= row[i];
            }
    else 
        proizved = 0;
    return proizved;
}