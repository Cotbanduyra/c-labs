#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define MIN_INT 1 << (sizeof(int) * 8) - 1
#define NULL_ 0

void main(int argc, char* argv[]){
    short int length1, length2, length3;
    int low_gran, high_gran;

    printf("low_edge: ");
    scanf("%d", &low_gran);
    printf("high_edge: ");
    scanf("%d", &high_gran);


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
        if (arr1[i] < low_gran || arr1[i] > high_gran)
            was_1 = true;
    }
    int p_1 = 1;
    if (was_1)
    for (int i = 0; i < length1; i++){
        if (arr1[i] < low_gran || arr1[i] > high_gran)
            p_1 *= arr1[i];
    }
///*  Check arr2
    bool was_2 = false;
    for (int i = 0; i < length2 && !was_2; i++){
        if (arr2[i] < low_gran || arr2[i] > high_gran)
            was_2 = true;
    }

    int p_2 = 1;
    if (was_2)
    for (int i = 0; i < length2; i++){
        if (arr2[i] < low_gran || arr2[i] > high_gran)
            p_2 *= arr2[i];
   }
    //Check arr3
    bool was_3 = false;
    for (int i = 0; i < length3 && !was_3; i++){
        if (arr3[i] < low_gran || arr3[i] > high_gran)
            was_3 = true;
    }
    int p_3 = 1;
    if (was_3)
    for (int i = 0; i < length3; i++){
        if (arr3[i] < low_gran || arr3[i] > high_gran)
            p_3 *= arr3[i];
    }
//*/
    int max_val = NULL_;  // Pointer to track which array has the max product

    // Check each valid array and update max_val
    if (was_1 && (max_val == NULL_ || p_1 > max_val)) max_val = p_1;
    if (was_2 && (max_val == NULL_ || p_2 > max_val)) max_val = p_2;
    if (was_3 && (max_val == NULL_ || p_3 > max_val)) max_val = p_3;

    // Now handle all cases based on which arrays exist and have the max value
    if (max_val == NULL_) {
        printf("no arrs have elements in range\n");
    } else {
        int count = 0;

        // Count how many arrays have the max value
        if (was_1 && p_1 == max_val) count++;
        if (was_2 && p_2 == max_val) count++;
        if (was_3 && p_3 == max_val) count++;

        // Determine which arrays have the max
        int has1 = was_1 && p_1 == max_val;
        int has2 = was_2 && p_2 == max_val;
        int has3 = was_3 && p_3 == max_val;

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

/*
if(p_1 > p_2 && p_1 > p_3 && was_1) printf("arr1 have most proizved ");
    else if (p_2 > p_3 && p_2 > p_1 && was_2) printf("arr2 have most proizved");
    else if (p_3 > p_1 && p_3 > p_2 && was_3) printf("arr3 have most proizved");
    else if ((p_1 == p_2 || p_1 == p_3 || p_2 == p_3) && ((was_1 && was_2) || (was_2 && was_3) || (was_1 && was_3))) 
        printf("some arrs have same proizved");
    else printf("all wrong");
    printf("\n");
    
*/
