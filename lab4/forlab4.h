#include <stdio.h>
#include <stdlib.h>

void ReadString(FILE* f, char** str);

unsigned short SplitIntoWords(char *str, char*** words);

bool NoRepeatedLetters(char *word);

bool CreateStr(char** words, char** str, int nwords);