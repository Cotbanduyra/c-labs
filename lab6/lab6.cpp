#include <stdio.h>

void SetBits(int* x, int n, int p){
    *x |= (((1u << n) - 1) << (32 - p));
    return;
}

void main(){
    int x = 12;
    printf("%b\n", x);
    SetBits(&x, 5, 8);
    printf("%b\n", x);
}
