#include "forlab3.h"

bool is_valid_self(char* s){
    int i = 0;
    bool digits = false;

    if (s[i] == '+' || s[i] == '-') i++;

    if (s[i] >= '0' && s[i] <= '9') {
        digits = true;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') i++;

    if (s[i] == '.') {
        i++;
        if (s[i] >= '0' && s[i] <= '9') digits = true;
        while (s[i] >= '0' && s[i] <= '9') i++;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '+' || s[i] == '-')
            i++;
        if (s[i] < '0' || s[i] > '9')
            return false;
        while (s[i] >= '0' && s[i] <= '9')
            i++;
    }

    return s[i] == '\0' && digits;
}


bool check_text_file(FILE* f){
    fseek(f, 0, SEEK_SET);
    char* token;
    long count = 0;
    while (fscanf(f, "%s", token) == 1) {
         if (is_valid_self(token))
             count++;
     }

    return count > 0 && count % RECORD_SIZE == 0;
}

bool text_to_binary(FILE* ft, FILE* fb){
    fseek(ft, 0, SEEK_SET);
    fseek(fb, 0, SEEK_SET);
    char* token;
    record rec;
    int i = 0;
    bool ok = true;
    while (ok && fscanf(ft, "%s", token) == 1) {
        if (is_valid_self(token)){
            rec[i++] = strtof(token, NULL);
            if (i == RECORD_SIZE) {
                if (fwrite(rec, sizeof(record), 1, fb) != 1) {
                    ok = false;
                }
                i = 0;
            }
        }
    }
    printf("writed\n");
    return ok;
}

bool swap_records(FILE* f, int index1, int index2){
    record r1, r2;
    bool ok = (index1 != index2);

    if (ok) {
        fseek(f, index1 * sizeof(record), SEEK_SET);
        ok = fread(r1, sizeof(record), 1, f) == 1;
        
        if (ok) {
            fseek(f, index2 * sizeof(record), SEEK_SET);
            ok = fread(r2, sizeof(record), 1, f) == 1;
        }
        
        if (ok) {
            fseek(f, index2 * sizeof(record), SEEK_SET);
            ok = fwrite(r1, sizeof(record), 1, f) == 1;
        }
        
        if (ok) {
            fseek(f, index1 * sizeof(record), SEEK_SET);
            ok = fwrite(r2, sizeof(record), 1, f) == 1;
        }
    }

    return ok;
}


void print_binary_file(FILE* f){
    fseek(f, 0, SEEK_SET);
    record rec;

    while (fread(rec, sizeof(record), 1, f) == 1) {
        for (int i = 0; i < RECORD_SIZE; i++)
            printf("%g ", rec[i]);
        printf("\n");
    }

    return;
}
