#include "forlab5.h"


double PersFunc(double x) {return x + 5;}
double Self(double x) {return x;}
double Abs(double x) {return abs(x);}

void main(int argc, char* argv[]){
    short len1, len2, len3;
    int *arr1, *arr2, *arr3;
    short low_gran, high_gran;
    FILE* f = fopen(argv[1], "r");

    fscanf(f, "%d %d", &low_gran, &high_gran);
    EnterArray(f, &arr1, &len1);
    EnterArray(f, &arr2, &len2);
    EnterArray(f, &arr3, &len3);

    func_ptr func;
    int idx;
    printf("Enter 1 - 6 for:\n1) abs\n2) exp\n3) sin\n4) cos\n5) ln\n6) personal funtion\n7) self\nEnter: ");
    scanf("%d", &idx);
    switch (idx)
    {
    case 1:
        func = Abs;
        break;
    case 2:
        func = exp;
        break;
    case 3:
        func = sin;
        break;
    case 4:
        func = cos;
        break;
    case 5:
        func = log;
        break;
    case 6:
        func = PersFunc;
        break;
    case 7:
        func = Self;
        break;
    default:
        break;
    }

    PrintArray(arr1, len1, func);
    PrintArray(arr2, len2, func);
    PrintArray(arr3, len3, func);

    bool was_1 = CheckArray(arr1, len1, low_gran, high_gran, func);
    
    //Check arr2
    bool was_2 = CheckArray(arr2, len2, low_gran, high_gran, func);
    
    //Check arr3
    bool was_3 = CheckArray(arr3, len3, low_gran, high_gran, func);
       
    if (was_1 && was_2 && was_3) {
        int p_1 = CalcArray(arr1, len1, low_gran, high_gran, func); 
        int p_2 = CalcArray(arr2, len2, low_gran, high_gran, func);
        int p_3 = CalcArray(arr3, len3, low_gran, high_gran, func);
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
        int p_1 = CalcArray  (arr1, len1, low_gran, high_gran, func); 
        int p_2 = CalcArray  (arr2, len2, low_gran, high_gran, func);

        if (p_1 == p_2)
            printf("arr 1 and 2 have same proizved\n");
        else if (p_1 < p_2)
            printf("arr 1 have most proizved\n");
        else
            printf("arr 2 have most proizved\n");
    } else if (was_1 && was_3) {
        int p_1 = CalcArray  (arr1, len1, low_gran, high_gran, func);
        int p_3 = CalcArray  (arr3, len3, low_gran, high_gran, func);

        if (p_1 == p_3)
            printf("arr 1 and 3 have same prozved\n");
        else if (p_1 < p_3)
            printf("arr 1 have most proizved\n");
        else
            printf("arr 3 have most proizved\n");
    } else if (was_2 && was_3) {
        int p_2 = CalcArray  (arr2, len2, low_gran, high_gran, func);
        int p_3 = CalcArray  (arr3, len3, low_gran, high_gran, func);

        if (p_2 == p_3)
            printf("arr 2 and 3 have same proizved\n");
        else if (p_2 < p_3)
            printf("arr 2 have most proizved\n");
        else
            printf("arr 3 have most proizved\n");
    } else if (was_1) {
        int p_1 = CalcArray  (arr1, len1, low_gran, high_gran, func); 
        printf("arr 1 have most proizved\n");
    } else if (was_2) {
        int p_2 = CalcArray  (arr2, len2, low_gran, high_gran, func);
        printf("arr 2 have most proizved\n");
    } else if (was_3) {
        int p_3 = CalcArray  (arr3, len3, low_gran, high_gran, func);
        printf("arr 3 have most proizved\n");
    } else {
        printf("no arrs have elements in range\n");
    }

    return;
}