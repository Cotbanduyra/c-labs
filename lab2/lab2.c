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
    scanf("%d %d", &(matr->row), &(matr->col));
    Init_matrix(matr);
    for (int i = 0; i < matr -> row; i++){
        for (int j = 0; j < matr -> col; j++){
            scanf("%d", &matr->matr[i][j]);
        }
    }
}

struct matrix a;

void main(int argc, char** argv){
    a.col;
    struct matrix* aptr;
    aptr = &a;
    (*aptr).row;
    struct matrix mat1, mat2;
    enter_matrix(&mat1);
    enter_matrix(&mat2);
    printf("%d\n", Check_matrix(&mat1));
    printf("%d\n", Check_matrix(&mat2));
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
        for(int j = 0; j < ar -> col; j++){ ar -> matr[i][j] = 1;
        printf("%d ", ar -> matr[i][j]);}
    }
}