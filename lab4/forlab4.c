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
    return;}

bool CheckOfWord(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');}

void CopyStr(char* f_str, char** t_str, int start_idx, int end_idx, int* old_size){
    if (start_idx <= end_idx){
        *t_str = (char*) realloc(*t_str, (*old_size + 1) * sizeof(char));
        (*t_str)[(*old_size)++] = f_str[start_idx];
        CopyStr(f_str, t_str, start_idx + 1, end_idx, old_size);}
    return;}

bool CompareWithRest(char* f_str, int base_idx, int curr_idx, int end_idx){
    bool result = true;
    if (curr_idx <= end_idx) result = (f_str[curr_idx] != f_str[base_idx]) && CompareWithRest(f_str, base_idx, curr_idx + 1, end_idx);
    return result;}

bool NoRepeatedLetters(char* f_str, int start_idx, int end_idx){
    bool result = true;
    if (start_idx < end_idx){
        result = NoRepeatedLetters(f_str, start_idx + 1, end_idx) && CompareWithRest(f_str, start_idx, start_idx + 1, end_idx);}
    return result;}

void CreateNewStr(char* f_str, char** t_str, int curr_pos, int word_start, bool is_word){
    static int size_of_t = 0;
    if (f_str[curr_pos] != '\0'){
        if (is_word){
            is_word = CheckOfWord(f_str[curr_pos]) ? true : false;
            if (!is_word) NoRepeatedLetters(f_str, word_start, curr_pos - 1) ? CopyStr(f_str, t_str, word_start, curr_pos - 1, &size_of_t) : (void)0;
        }else{
            if (CheckOfWord(f_str[curr_pos])){
                is_word = true;
                word_start = curr_pos;}}
        CreateNewStr(f_str, t_str, curr_pos + 1, word_start, is_word);
    }else{
        is_word ? (NoRepeatedLetters(f_str, word_start, curr_pos - 1) ? CopyStr(f_str, t_str, word_start, curr_pos - 1, &size_of_t): (void)0) : (void)0;
        *t_str = (char*) realloc(*t_str, (size_of_t + 1) * sizeof(char));
        (*t_str)[size_of_t] = '\0';}
    return;}

//// ZAHITA //////
int WordEnd(char* f_str, int pos, int limit){
    return (pos <= limit && CheckOfWord(f_str[pos])) ? WordEnd(f_str, pos + 1, limit) : pos;
}

int FindLastWord(char* f_str, int pos, int limit, int* end){
    int result;
    if (pos > limit){
        result = -1;
    }else if (!CheckOfWord(f_str[pos])){
        result = FindLastWord(f_str, pos + 1, limit, end);
    }else{
        int e = WordEnd(f_str, pos, limit);
        int tail = FindLastWord(f_str, e, limit, end);
        if (tail != -1){
            result = tail;
        }else{
            *end = e - 1;
            result = pos;
        }
    }
    return result;
}

int StrLen(char* f_str, int pos){
    return (f_str[pos] == '\0') ? pos : StrLen(f_str, pos + 1);
}

void ReverseWordsRec(char* f_str, char** t_str, int limit, int* size_of_t){
    int le;
    int ls = FindLastWord(f_str, 0, limit, &le);
    if (ls != -1){
        CopyStr(f_str, t_str, ls, le, size_of_t);
        ReverseWordsRec(f_str, t_str, ls - 1, size_of_t);
    }
    return;
}

void Reverse_words(char* f_str, char** t_str){
    int size_of_t = 0;
    int limit = StrLen(f_str, 0) - 1;
    ReverseWordsRec(f_str, t_str, limit, &size_of_t);
    *t_str = (char*) realloc(*t_str, (size_of_t + 1) * sizeof(char));
    (*t_str)[size_of_t] = '\0';
    return;
}