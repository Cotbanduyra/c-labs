#include <stdio.h>

#define BITS  32

#if BITS == 64
#define DATA long long
#define SCAN "%lld"
#define LIT(x) (x##ull)
#define BIN "%#066b\n"
#define HEX "%#018llx\n"
#define OCT "%#023llo\n"

#elif BITS == 32
#define DATA int
#define SCAN "%d"
#define LIT(x) (x##u)
#define BIN "%#036b\n"
#define HEX "%#010x\n" 
#define OCT "%#012o\n"

#elif BITS == 16
#define DATA short
#define SCAN "%zd"
#define LIT(x) (x##u)
#define BIN "%#018zb\n"
#define HEX "%#06zx\n" 
#define OCT "%#07zo\n"

#elif BITS == 8
#define DATA char
#define SCAN "%c"
#define LIT(x) (x##u)
#define BIN "%#010b\n"
#define HEX "%#04xc\n"
#define OCT "%#04oc\n"

#else
#error "BITS must be 8, 16, 32, 64"
#endif

bool SetBits(DATA* x, int p, int n)
{
    bool sucsess = false;
    if (n < p && p < BITS){
        *x |= ((LIT(1) << n) - 1) << p;
        sucsess = true;
    }
    return sucsess;
}


bool InverBits(DATA* x, int n, int k){
    bool sucsess = false;
    if (k < n && n < BITS){
        DATA mask = ((LIT(1) << k) - 1 ) << n;
        DATA temp = *x & mask;
        temp = ~temp & mask;
        *x |= mask;
        *x &= temp;
        sucsess = true;
    }
    return sucsess;
}

void main(){
    DATA x;
    scanf(SCAN, &x);
    printf(BIN, x);
    if (InverBits(&x, 15, 4)){
        printf(BIN, x);
        printf(HEX, x);
        printf(OCT, x);
    }
}


/*
void SetBits(int* x, int n, int p){
    *x |= (((1u << n) - 1) << (32 - p));
    return;
}*/

// inver k bit afeter n