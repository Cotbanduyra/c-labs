#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define RECORD_SIZE 3

typedef float record[3];

bool swap_records(const char *binary_filename, int index1, int index2);

bool text_to_binary(const char *text_filename, const char *binary_filename);

bool check_text_file(const char *text_filename);

void print_binary_file(const char *binary_filename);