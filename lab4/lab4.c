#include "forlab4.h"

void main(int argc, char* argv[]){
    FILE* f = fopen(argv[1], "r");
    char* temp_str = (char*) malloc(0), *res_str= (char*) malloc(0);
    int size_b = 0;
    ReadString(f, &temp_str, &size_b);
    CreateNewStr(temp_str, &res_str, 0, 0, 0);
    printf("%s\n", res_str);
    fclose(f);
    return;
}