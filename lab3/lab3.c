#include "forlab3.h"


int main(int argc, char** argv){
    FILE* text = fopen(argv[1], "r");
    FILE* bin = fopen(argv[2], "rb+");

    if (text && bin){
        if (!text_to_binary(text, bin)) {
            printf("Fial of convertion\n");
        }else{

            int i1, i2;

            printf("what need to swap:");
            scanf("%d", &i1);
            scanf("%d", &i2);

            printf("Before:\n");
            print_binary_file(bin);


            if (!swap_records(bin, i1, i2)) {
                printf("Faild to sawap\n");
            }else{

                printf("After:\n");
                print_binary_file(bin);
            }
        }
    }
    fclose(text);
    fclose(bin);

    return 0;
}



