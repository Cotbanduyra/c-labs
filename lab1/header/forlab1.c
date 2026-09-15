#include "forlab1.h"

void EnterArray(int** arr, short* length){
    printf("len of arr: ");
    scanf("%hd", length);
    *arr = (int*) calloc(*length, sizeof(int));
    printf("elems: ");
    for (int i = 0; i < *length; i++){
        scanf("%d", &(*arr)[i]);
    }
    return;
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

int GetIndFN(int* arr, short length){
    short idx = -1;
    for (int i =0; i < length && (idx == -1); i++){
        if (arr[i] == 0)
            idx = i;
    }
    return idx;
}

int SumAfterNull(int* arr, short length, int idx){
    int sum = 0;
    for (int i = idx; i < length; i++){
        sum += arr[i];
    }
    return sum;
}