#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>

void main(int argc, char* argv[]){

    void* handle = dlopen("./libforlab7.so", RTLD_LAZY);


    FILE* f = fopen(argv[1], "r");
    char* temp_str = (char*) malloc(0), *res_str= (char*) malloc(0);
    
    void (*ReadStrings) (FILE*, char**) = dlsym(handle, "ReadString");
    ReadStrings(f, &temp_str);

    void (*CreateStr) (char*, char**, int, int, int) = dlsym(handle, "CreateNewStr"); 
    CreateStr(temp_str, &res_str, 0, 0, 0);
    
    printf("%s\n", res_str);
    
    void (*ReverseWords) (char*, char**) = dlsym(handle, "Reverse_words");
    ReverseWords(temp_str, &res_str);
    
    printf("%s\n", res_str);
    fclose(f);
    return;
} // switch position of words
