#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef double (*func_ptr) (double x);

void EnterArray(FILE* f, int** arr, short* length);

bool CheckArray(int* arr, short length, int lg, int hg, func_ptr op);

int CalcArray(int* arr, short length, int lg, int hg, func_ptr op);

void PrintArray(int* arr, short len, func_ptr func);
/*
int GetIndFN(int* arr, short length);

int SumAfterNull(int* arr, short length, int idx);
//*/