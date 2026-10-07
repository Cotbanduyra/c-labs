#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define RECORD_SIZE 3

typedef float record[3];

bool swap_records(FILE* f, int index1, int index2);

bool text_to_binary(FILE* ft, FILE* fb);

bool check_text_file(FILE* f);

void print_binary_file(FILE* f);

void DelNotRange(FILE* f, float lg, float hg);