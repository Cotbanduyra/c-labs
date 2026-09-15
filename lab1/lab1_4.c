#include "header/forlab1.h"

void main(int argc, char* argv[]){
    short int length1, length2, length3;
/*
    int low_gran, high_gran;

    printf("low_edge: ");
    scanf("%d", &low_gran);
    printf("high_edge: ");
    scanf("%d", &high_gran);
*/
    int* arr1;
    int* arr2;
    int* arr3;

    EnterArray(&arr1, &length1);
    EnterArray(&arr2, &length2);
    EnterArray(&arr3, &length3);

//Chek arr1
//    bool was_1 = CheckArray(arr1, length1 );
    int pos_1 = GetIndFN(arr1, length1);
    bool was_1 = (pos_1 != -1) && (pos_1 != length1 - 1);

//Check arr2
//    bool was_2 = CheckArray(arr2, length2 );
    int pos_2 = GetIndFN(arr1, length1);
    bool was_2 = (pos_2 != -1) && (pos_2 != length2 - 1);
//Check arr3
//    bool was_3 = CheckArray(arr3, length3 );
    int pos_3 = GetIndFN(arr1, length1);
    bool was_3 = (pos_3 != -1) && (pos_3 != length3 - 1);
    
    if (was_1 && was_2 && was_3) {
        int p_1 = SumAfterNull(arr1, length1, pos_1); 
        int p_2 = SumAfterNull(arr2, length2, pos_2);
        int p_3 = SumAfterNull(arr3, length3, pos_3);
    if (p_1 == p_2 && p_2 == p_3)
        printf("all 3 arrs have same proizved\n");
    else if (p_1 == p_2 && p_1 < p_3)
        printf("arr 1 and 2 have same proizved\n");
    else if (p_1 == p_3 && p_1 < p_2)
        printf("arr 1 and 3 have same prozved\n");
    else if (p_2 == p_3 && p_2 < p_1)
        printf("arr 2 and 3 have same proizved\n");
    else if (p_1 < p_2 && p_1 < p_3)
        printf("arr 1 have most proizved\n");
    else if (p_2 < p_1 && p_2 < p_3)
        printf("arr 2 have most proizved\n");
    else
        printf("arr 3 have most proizved\n");
    } else if (was_1 && was_2) {
        int p_1 = SumAfterNull  (arr1, length1, pos_1); 
        int p_2 = SumAfterNull  (arr2, length2, pos_2);

        if (p_1 == p_2)
            printf("arr 1 and 2 have same proizved\n");
        else if (p_1 < p_2)
            printf("arr 1 have most proizved\n");
        else
            printf("arr 2 have most proizved\n");
    } else if (was_1 && was_3) {
        int p_1 = SumAfterNull  (arr1, length1, pos_1);
        int p_3 = SumAfterNull  (arr3, length3, pos_3);

        if (p_1 == p_3)
            printf("arr 1 and 3 have same prozved\n");
        else if (p_1 < p_3)
            printf("arr 1 have most proizved\n");
        else
            printf("arr 3 have most proizved\n");
    } else if (was_2 && was_3) {
        int p_2 = SumAfterNull  (arr2, length2, pos_2);
        int p_3 = SumAfterNull  (arr3, length3, pos_3);

        if (p_2 == p_3)
            printf("arr 2 and 3 have same proizved\n");
        else if (p_2 < p_3)
            printf("arr 2 have most proizved\n");
        else
            printf("arr 3 have most proizved\n");
    } else if (was_1) {
        int p_1 = SumAfterNull  (arr1, length1, pos_1); 
        printf("arr 1 have most proizved\n");
    } else if (was_2) {
        int p_2 = SumAfterNull  (arr2, length2, pos_2);
        printf("arr 2 have most proizved\n");
    } else if (was_3) {
        int p_3 = SumAfterNull  (arr3, length3, pos_3);
        printf("arr 3 have most proizved\n");
    } else {
        printf("no arrs have elements in range\n");
    }

    return;
}

