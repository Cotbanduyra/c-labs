#include "forlab5.h"

void main(int argc, char* argv[]){
    short len1, len2, len3;
    int *arr1, *arr2, *arr3;
    int low_gran, high_gran;
    FILE* f = fopen(argv[1], "r");

    fscanf(f, "%d %d", &low_gran, &high_gran);
    EnterArray(f, &arr1, len1);
    EnterArray(f, &arr2, len2);
    EnterArray(f, &arr3, len3);
    bool was_1 = CheckArray(arr1, len1, low_gran, high_gran);
    
    //Check arr2
    bool was_2 = CheckArray(arr2, len2, low_gran, high_gran);
    
    //Check arr3
    bool was_3 = CheckArray(arr3, len3, low_gran, high_gran);
       
    return;
}