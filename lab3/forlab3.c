#include "forlab3.h"

bool is_valid_float(const char *s){
    char *end;
    strtof(s, &end);
    return *end == '\0';
}

bool is_valid_self(const char* s){
    int i = 0;
    bool digits = false;

    if (s[i] == '+' || s[i] == '-') i++;

    if (s[i] >= '0' && s[i] <= '9') digits = true;

    while (s[i] >= '0' && s[i] <= '9') i++;

    if (s[i] == '.') {
        i++;
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

    return s[i] == '\0';
}


bool check_text_file(const char *text_filename){
    FILE *f = fopen(text_filename, "r");
    char token[64];
    long count = 0;

    if (f) {
        while (fscanf(f, "%63s", token) == 1) {
            if (is_valid_float(token))
                count++;
        }
        fclose(f);
    }

    return count > 0 && count % RECORD_SIZE == 0;
}

bool text_to_binary(const char *text_filename, const char *binary_filename){
    FILE *ft = fopen(text_filename, "r");
    FILE *fb = fopen(binary_filename, "wb");
    char token[64];
    record rec;
    int i = 0;
    bool ok = (ft != NULL && fb != NULL);

    if (ok) {
        while (ok && fscanf(ft, "%63s", token) == 1) {
            if (is_valid_float(token)){
                rec[i++] = strtof(token, NULL);
                if (i == RECORD_SIZE) {
                    if (fwrite(rec, sizeof(record), 1, fb) != 1) {
                        ok = false;
                    }
                    i = 0;
                }
            }
        }
        fclose(ft);
        fclose(fb);
        printf("writed\n");
    } else {
        if (ft) fclose(ft);
        if (fb) fclose(fb);
    }

    return ok;
}

bool swap_records(const char *binary_filename, int index1, int index2){
    FILE *f;
    record r1, r2;
    bool ok = (index1 != index2);

    if (ok) {
        f = fopen(binary_filename, "rb+");
        ok = (f != NULL);

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

            fclose(f);
        }
    }

    return ok;
}


void print_binary_file(const char *binary_filename){
    FILE *f = fopen(binary_filename, "rb");
    record rec;
    int i;

    if (f) {
        while (fread(rec, sizeof(record), 1, f) == 1) {
            for (i = 0; i < RECORD_SIZE; i++)
                printf("%g ", rec[i]);
            printf("\n");
        }
        fclose(f);
    }
    return;
}