#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_INT 1 << (sizeof(int) * 8) - 1
#define NULL_ 0

void main(int argc, char* argv[]){
    short int length1, length2, length3;
    int low_gran, high_gran;

    printf("low_edge: ");
    scanf("%d", &low_gran);
    //printf("high_edge: ");
    //scanf("%d", &high_gran);


    printf("l1 l2 l3\n");
    scanf("%hd %hd %hd", &length1, &length2, &length3);
    
    int* arr1;
    int* arr2;
    int* arr3;
    arr1 = (int*) malloc(length1 * sizeof(int));
    arr2 = (int*) malloc(length2 * sizeof(int));
    arr3 = (int*) malloc(length3 * sizeof(int));

    for (int i = 0; i < length1; i++){
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < length2; i++){
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < length3; i++){
        scanf("%d", &arr3[i]);
    }

    //Chek arr1
    bool was_1 = false;
    for (int i = 0; i < length1 && !was_1; i++){
        if (arr1[i] < low_gran)
            was_1 = true;
    }


    float sr_1 = 1;
    if (was_1){
        int k1 = 0;
        for (int i = 0; i < length1; i++){
            if (arr1[i] < low_gran){
                sr_1 *= arr1[i];
                k1++;
            }
        }
        sr_1 /= k1;
    }
///*  Check arr2
    bool was_2 = false;
    for (int i = 0; i < length2 && !was_2; i++){
        if (arr2[i] < low_gran)
            was_2 = true;
    }

    
    float sr_2 = 1;
    if (was_2){
        int k2;
        for (int i = 0; i < length2; i++){
            if (arr2[i] < low_gran){
                sr_2 *= arr2[i];
                k2++;
            }
        }
        sr_2 /= k2;
    }
    //Check arr3
    bool was_3 = false;
    for (int i = 0; i < length3 && !was_3; i++){
        if (arr3[i] < low_gran)
            was_3 = true;
    }
    float sr_3 = 1;
    if (was_3){
        int k3;
        for (int i = 0; i < length3; i++){
            if (arr3[i] < low_gran){
                sr_3 *= arr3[i];
                k3++;
            }
        }
        sr_3 /= k3; 
    }
//*/
    int min_val  = NULL_;  
    
    if (was_1 && (min_val  == NULL_ || sr_1 < min_val )) min_val  = sr_1;
    if (was_2 && (min_val  == NULL_ || sr_2 < min_val )) min_val  = sr_2;
    if (was_3 && (min_val  == NULL_ || sr_3 < min_val )) min_val  = sr_3;

    if (min_val  == NULL_) {
        printf("no arrs have elements in range\n");
    } else {
        int count = 0;

       
        if (was_1 && sr_1 == min_val ) count++;
        if (was_2 && sr_2 == min_val ) count++;
        if (was_3 && sr_3 == min_val ) count++;

        int has1 = was_1 && sr_1 == min_val ;
        int has2 = was_2 && sr_2 == min_val ;
        int has3 = was_3 && sr_3 == min_val ;

        if (count == 3) {
            printf("all 3 arrs have same proizved\n");
        } else if (count == 2) {
            if (has1 && has2) printf("arr 1 and 2 have same proizved\n");
            else if (has1 && has3) printf("arr 1 and 3 have same proizved\n");
            else if (has2 && has3) printf("arr 2 and 3 have same proizved\n");
        } else if (count == 1) {
            if (has1) printf("arr 1 have most proizved\n");
            else if (has2) printf("arr 2 have most proizved\n");
            else if (has3) printf("arr 3 have most proizved\n");
        }
    }
    return;
}
