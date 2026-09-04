#include <stdio.h>
#include <stdlib.h>

#define RECORD_SIZE 3

struct one_record{
    float f1, f2, f3;
};

void display_binary_file(const char *filename, const char *label) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("%s: File %s not found\n", label, filename);
        return;
    }
    
    float records[RECORD_SIZE];
    int record_num = 1;
    
    printf("\n--- %s ---\n", label);
    while (fread(records, sizeof(float), RECORD_SIZE, file) == RECORD_SIZE) {
        printf("Record %d: %.2f %.2f %.2f\n", 
               record_num++, records[0], records[1], records[2]);
    }
    
    fclose(file);
}

void main(int argc, char** argv) {
    FILE *text_file, *binary_file;
    char* i_file_name = argv[1]; 
    char* o_file_name = argv[2];
    float numbers[RECORD_SIZE];
    char line[200];
    int records_count = 0;
    
    text_file = fopen(i_file_name, "r");
    if (text_file == NULL) {
        printf("Error: Cannot open input.txt\n");
    }
    
    binary_file = fopen(o_file_name, "rwb");
    if (binary_file == NULL) {
        printf("Error: Cannot create output.bin\n");
        fclose(text_file);
    }
    
    
    fclose(text_file);
    fclose(binary_file);
    
    printf("Total records processed: %d\n\n", records_count);
    
    // === AFTER PROCESSING ===
    printf("AFTER PROCESSING:\n");
    display_binary_file(o_file_name, "Binary file after processing");
    
    return;
}