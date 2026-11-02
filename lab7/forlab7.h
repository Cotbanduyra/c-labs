#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef FORLAB7
#define FORLAB7

extern void ReadString(FILE* f, char** str);

extern void CreateNewStr(char* f_str, char** t_str, int curr_pos, int word_start, bool is_word);

extern void Reverse_words(char* f_str, char** t_str);

bool CheckOfWord(char c);
void CopyStr(char* f_str, char** t_str, int start_idx, int end_idx, int* old_size);
bool CompareWithRest(char* f_str, int base_idx, int curr_idx, int end_idx);
bool NoRepeatedLetters(char* f_str, int start_idx, int end_idx);
int WordEnd(char* f_str, int pos, int limit);
int FindLastWord(char* f_str, int pos, int limit, int* end);
int StrLen(char* f_str, int pos);
void ReverseWordsRec(char* f_str, char** t_str, int limit, int* size_of_t);

#endif