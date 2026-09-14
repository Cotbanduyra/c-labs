#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void EnterArray(int* arr, short* length);

bool CheckArray(int* arr, short length, int lg, int hg);

int CalcArray(const int const* arr, short length, int lg, int hg);