#include "forlab3.h"


int main(int argc, char** argv)
{
    if (!text_to_binary(argv[1], argv[2])) {
        printf("Ошибка преобразования\n");
        return 1;
    }

    int i1, i2;

    printf("what need to swap:");
    scanf("%d", &i1);
    scanf("%d", &i2);

    printf("До обработки:\n");
    print_binary_file(argv[2]);

    
    if (!swap_records(argv[2], i1, i2)) {
        printf("Ошибка обмена\n");
        return 1;
    }

    printf("После обработки:\n");
    print_binary_file(argv[2]);

    return 0;
}