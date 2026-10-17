#include "forlab4.h"

void ReadString(FILE* f, char** str, int* size) {
    char c;
    if((c = fgetc(f)) != EOF){
        *str = (char*) realloc(*str, ++*size * sizeof(char));
        (*str)[*size - 1] = c;
        ReadString(f, str, size);
    }else{
    *str = (char*) realloc(*str, ++*size * sizeof(char));
    (*str)[*size - 1] = '\0';}
    return;
}

bool CheckOfWord(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

void CopyStr(char* f_str, char** t_str, int start_idx, int end_idx, int* old_size){
    if (start_idx <= end_idx){
        *t_str = (char*) realloc(*t_str, (*old_size + 1) * sizeof(char));
        (*t_str)[(*old_size)++] = f_str[start_idx];
        CopyStr(f_str, t_str, start_idx + 1, end_idx, old_size);}
    return;
}

bool NoRepeatedLetters(char* f_str, int start_idx, int end_idx){
    bool no_was_repeated = true;
    if (start_idx <= end_idx){
        no_was_repeated = NoRepeatedLetters(f_str, start_idx + 1, end_idx);
        if (!no_was_repeated) for (int i = start_idx; i <= end_idx && no_was_repeated; i++) no_was_repeated = (f_str[i] != f_str[start_idx]);}
    return no_was_repeated;
}

void CreateNewStr(char* f_str, char** t_str, int curr_pos, int word_start, bool is_word){
    static int size_of_t = 0;
    if (f_str[curr_pos] != '\0'){
        if (is_word){
            if (!CheckOfWord(f_str[curr_pos])){
                is_word = false;
                if (NoRepeatedLetters(f_str, word_start, curr_pos)){
                    CopyStr(f_str, t_str, word_start, curr_pos-1, &size_of_t);}}
        }else{
            if (CheckOfWord(f_str[curr_pos])){
                is_word = true;
                word_start = curr_pos;}}
    CreateNewStr(f_str, t_str, ++curr_pos, word_start, is_word);}
    else if(is_word){CopyStr(f_str, t_str, word_start, curr_pos, &size_of_t);}
    return;
}


/*
bool NoRepeatedLetters(char* f_str, int start_idx, int end_idx){
    bool no_was_repeated = true;
    for (int i = start_idx; i < end_idx && no_was_repeated; i++){
         for(int j = i + 1; j <= end_idx && no_was_repeated; j++){
            if ( f_str[i] == f_str[j]) no_was_repeated = false;}}
    return no_was_repeated;
}
//*/