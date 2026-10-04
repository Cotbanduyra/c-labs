#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void EnterArray(FILE* f, int** arr, short* length);

bool CheckArray(int* arr, short length, int lg, int hg);

int CalcArray(int* arr, short length, int lg, int hg, int (*op) (int));
/*
int GetIndFN(int* arr, short length);

int SumAfterNull(int* arr, short length, int idx);
//*/