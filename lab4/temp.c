void CreateNewStr(char* f_str, char** t_str, int curr_pos, int word_start, bool is_word, int* size_of_t){
    if (f_str[curr_pos] != '\0'){
        if (is_word){
            if (!CheckOfWord(f_str[curr_pos])){
                is_word = false;
                if (NoRepeatedLetters(f_str, word_start, curr_pos)){
                    CopyStr(f_str, t_str, word_start, curr_pos, size_of_t);}}
    }else{
            if (CheckIfWord(f_str[curr_pos])){
                is_word = true;
                word_start = curr_pos;}}
        CreateNewStr(f_str, t_str, ++curr_pos, word_start, is_word, size_of_t);}
    if(is_word){
        CopyStr(f_str, t_str, word_start, curr_pos, size_of_t);}
    return;
}

void CopyStr(char* f_str, char** t_str, int start_idx, int end_idx, int* old_size){
    *t_str = (char*) realloc(*t_str, (*old_size + (end_idx - start_idx + 1)) * sizeof(char));
    for (int i = start_idx; i <= end_idx; i++){
        (*t_str)[*old_size - 1 + (i - start_idx)] = f_str[i];}
    *old_size += end_idx - start_idx + 1;
    return;
}

bool NoRepeatedLetters(char* f_str, int start_idx, int end_idx){
    bool no_was_repeated = true;
    for (int i = start_idx; i < end_idx && no_was_repeated; i++){
         for(int j = i + 1; j <= end_idx && no_was_repeated; j++){
            if ( f_str[i] == f_str[j]) no_was_repeated = false;}}
    return no_was_repeated;
}