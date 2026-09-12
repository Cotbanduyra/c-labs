#include "forlab2.h"

void EnterArray(int* arr, short* length){
    printf("len of arr: ");
    scanf("%hd", length);
    arr = (int*) calloc(*length, sizeof(int));
    printf("elems: ");
    for (int i = 0; i < *length; i++){
        scanf("%d", &arr[i]);
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

int CalcArray(const int const* arr, short length, int lg, int hg){
    int p = 1;
    for (int i = 0; i < length; i++){
        if (arr[i] < lg || arr[i] > hg)
            p *= arr[i];
    }
    return p;
}