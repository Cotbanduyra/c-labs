#include "forlab4.h"

void ReadString(FILE* f, char** str) {
    char c;
    fseek(f, 0, SEEK_SET);
    int size = 0;
    while ((c = fgetc(f)) != EOF){
        *str = (char*) realloc(*str, ++size * sizeof(char));
        (*str)[size - 1] = c;
    }
    *str = (char*) realloc(*str, ++size * sizeof(char));
    (*str)[size - 1] = '\0';
    return;
}

bool CheckOfWord(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void CopyStr(char* fstr, char** tstr, int size){
    *tstr = (char*) malloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
        (*tstr)[i] = fstr[i];
    return;
}

unsigned short SplitIntoWords(char *str, char*** words) {
    unsigned short word_numb = 0;
    bool is_word = false;
    char* buf = (char*) malloc(0); int buf_size = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (is_word){
            buf = (char*) realloc(buf, ++buf_size * sizeof(char));
            if (CheckOfWord(str[i])){
                buf[buf_size - 1] = str[i];
            } else {
                buf[buf_size - 1] = '\0';
                *words = (char**) realloc(*words, ++word_numb * sizeof(char**));
                CopyStr(buf, &(*words)[word_numb-1], buf_size);
                free(buf);
                buf = (char*) malloc(0);
                buf_size = 0;

                is_word = false;
            }
        } else{
            if (CheckOfWord(str[i])){
                is_word = true;
                buf = (char*) realloc(buf, ++buf_size * sizeof(char));
                buf[buf_size-1] = str[i];
            }
        }
    }

    if (is_word){
        buf = realloc(buf, ++buf_size * sizeof(char));
        buf[buf_size - 1] = '\0';
        *words = (char**) realloc(*words, ++word_numb * sizeof(char**));
        CopyStr(buf, &(*words)[word_numb-1], buf_size);
    }

    return word_numb;
}

bool NoRepeatedLetters(char *word) {
    bool was_repeated = true;

    for(int i = 0; word[i] != '\0' && was_repeated; i++){
        for(int j = i + 1; word[j] != '\0' && was_repeated; j++){
            if (word[i] == word[j]) was_repeated = false;
        }
    }
    return was_repeated;
}

bool CreateStr(char** words, char** str, int nwords){
    int pos = 0;
    for (int i = 0; i < nwords; i++) {
        if (NoRepeatedLetters(words[i])){
            for (int j = 0; words[i][j] != '\0'; j++) {
                *str = realloc(*str, ++pos * sizeof(char));
                (*str)[pos - 1] = words[i][j];
            }
        }
    }
    if (pos > 0){
        *str = realloc(*str, ++pos * sizeof(char));
        (*str)[pos - 1] = '\0';
    }
    return pos;
}