#include "forlab5.h"

void EnterArray(FILE* f, int** arr, short* length){
    fscanf(f, "%hd", length);
    *arr = (int*) calloc(*length, sizeof(int));
    for (int i = 0; i < *length; i++){
        fscanf(f, "%d", &(*arr)[i]);
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

int CalcArray(int* arr, short length, int lg, int hg, int (*op)(int)){
    int p = 1;
    for (int i = 0; i < length; i++){
        if (arr[i] < lg || arr[i] > hg)
            p *= op(arr[i]);
    }
    return p;
}


/*
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
    //*/