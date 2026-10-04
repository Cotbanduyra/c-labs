#include "forlab4.h"

void main(int argc, char* argv[]){
    FILE* f = fopen(argv[1], "r");
    char* temp_str = (char*) malloc(0), *res_str= (char*) malloc(0);
    char** words;
    int words_count;

    ReadString(f, &temp_str);
    words_count = SplitIntoWords(temp_str, &words);
    if(CreateStr(words, &res_str, words_count))
        printf("%s\n", res_str);
    fclose(f);
    return;
}