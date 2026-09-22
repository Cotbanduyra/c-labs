#include "forlab3.h"

bool is_valid_float(const char *s){
    char *end;
    strtof(s, &end);
    return *end == '\0';
}

bool check_text_file(const char *text_filename){
    FILE *f = fopen(text_filename, "r");
    char token[64];
    long count = 0;
    bool ok = (f != NULL);

    if (ok) {
        while (fscanf(f, "%63s", token) == 1) {
            if (!is_valid_float(token))
                ok = false;
            count++;
        }
        fclose(f);
    }

    return ok && count > 0 && count % RECORD_SIZE == 0;
}

bool text_to_binary(const char *text_filename, const char *binary_filename){
    FILE *ft;
    FILE *fb;
    record rec;
    int i;
    bool ok = check_text_file(text_filename);

    if (ok) {
        ft = fopen(text_filename, "r");
        fb = fopen(binary_filename, "wb");
        ok = (ft != NULL && fb != NULL);

        if (ok) {
            while (ok && fscanf(ft, "%f %f %f", &rec[0], &rec[1], &rec[2]) == RECORD_SIZE)
                ok = fwrite(rec, sizeof(record), 1, fb) == 1;
            fclose(ft);
            fclose(fb);
        } else {
            if (ft) fclose(ft);
            if (fb) fclose(fb);
        }
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