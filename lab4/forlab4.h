#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ReadString(FILE* f, char** str, int* size);

void CreateNewStr(char* f_str, char** t_str, int curr_pos, int word_start, bool is_word);

bool NoRepeatedLetters(char* f_str, int start_idx, int end_idx);