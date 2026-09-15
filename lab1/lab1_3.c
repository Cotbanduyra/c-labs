#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void EnterArray(int** arr, short* length);

bool CheckArray(int* arr, short length, int lg, int hg);

int CalcArray(int* arr, short length, int lg, int hg);

void main(int argc, char* argv[]){
    short int length1, length2, length3;
    int low_gran, high_gran;

    printf("low_edge: ");
    scanf("%d", &low_gran);
    printf("high_edge: ");
    scanf("%d", &high_gran);

    int* arr1;
    int* arr2;
    int* arr3;

    EnterArray(&arr1, &length1);
    EnterArray(&arr2, &length2);
    EnterArray(&arr3, &length3);

    //Chek arr1
    bool was_1 = CheckArray(arr1, length1, low_gran, high_gran);
    
    //Check arr2
    bool was_2 = CheckArray(arr2, length2, low_gran, high_gran);
    
    //Check arr3
    bool was_3 = CheckArray(arr3, length3, low_gran, high_gran);
    

    
    if (was_1 && was_2 && was_3) {
        int p_1 = CalcArray(arr1, length1, low_gran, high_gran); 
        int p_2 = CalcArray(arr2, length2, low_gran, high_gran);
        int p_3 = CalcArray(arr3, length3, low_gran, high_gran);
    if (p_1 == p_2 && p_2 == p_3)
        printf("all 3 arrs have same proizved\n");
    else if (p_1 == p_2 && p_1 > p_3)
        printf("arr 1 and 2 have same proizved\n");
    else if (p_1 == p_3 && p_1 > p_2)
        printf("arr 1 and 3 have same prozved\n");
    else if (p_2 == p_3 && p_2 > p_1)
        printf("arr 2 and 3 have same proizved\n");
    else if (p_1 > p_2 && p_1 > p_3)
        printf("arr 1 have most proizved\n");
    else if (p_2 > p_1 && p_2 > p_3)
        printf("arr 2 have most proizved\n");
    else
        printf("arr 3 have most proizved\n");
    } else if (was_1 && was_2) {
        int p_1 = CalcArray(arr1, length1, low_gran, high_gran); 
        int p_2 = CalcArray(arr2, length2, low_gran, high_gran);

        if (p_1 == p_2)
            printf("arr 1 and 2 have same proizved\n");
        else if (p_1 > p_2)
            printf("arr 1 have most proizved\n");
        else
            printf("arr 2 have most proizved\n");
    } else if (was_1 && was_3) {
        int p_1 = CalcArray(arr1, length1, low_gran, high_gran);
        int p_3 = CalcArray(arr3, length3, low_gran, high_gran);

        if (p_1 == p_3)
            printf("arr 1 and 3 have same prozved\n");
        else if (p_1 > p_3)
            printf("arr 1 have most proizved\n");
        else
            printf("arr 3 have most proizved\n");
    } else if (was_2 && was_3) {
        int p_2 = CalcArray(arr2, length2, low_gran, high_gran);
        int p_3 = CalcArray(arr3, length3, low_gran, high_gran);

        if (p_2 == p_3)
            printf("arr 2 and 3 have same proizved\n");
        else if (p_2 > p_3)
            printf("arr 2 have most proizved\n");
        else
            printf("arr 3 have most proizved\n");
    } else if (was_1) {
        int p_1 = CalcArray(arr1, length1, low_gran, high_gran); 
        printf("arr 1 have most proizved\n");
    } else if (was_2) {
        int p_2 = CalcArray(arr2, length2, low_gran, high_gran);
        printf("arr 2 have most proizved\n");
    } else if (was_3) {
        int p_3 = CalcArray(arr3, length3, low_gran, high_gran);
        printf("arr 3 have most proizved\n");
    } else {
        printf("no arrs have elements in range\n");
    }

    return;
}


void EnterArray(int** arr, short* length){
    printf("len of arr: ");
    scanf("%hd", length);
    *arr = (int*) calloc(*length, sizeof(int));
    printf("elems: ");
    for (int i = 0; i < *length; i++){
        scanf("%d", &(*arr)[i]);
    }

}

bool CheckArray(int* arr, short length, int lg, int hg){
    bool was = false;
    for (int i = 0; i < length && !was; i++){
        if (arr[i] < lg || arr[i] > hg)
            was = true;
    }
    return was;
}

int CalcArray(int* arr, short length, int lg, int hg){
    int p = 1;
    for (int i = 0; i < length; i++){
        if (arr[i] < lg || arr[i] > hg)
            p *= arr[i];
    }
    return p;
}