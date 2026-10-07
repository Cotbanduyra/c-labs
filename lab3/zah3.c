#include "forlab3.h"

int main(int argc, char** argv){
    FILE* text = fopen(argv[1], "r");
    FILE* bin = fopen(argv[2], "wb+");

    if (text && bin){
        printf("p1\n");
        if (!text_to_binary(text, bin)) {
            printf("Fial of convertion\n");
        }else{

            int lg, hg;

            printf("lg and hg");
            scanf("%d", &lg);
            scanf("%d", &hg);

            printf("Before:\n");
            print_binary_file(bin);


            DelNotRange(bin, lg, hg);
            printf("After:\n");
            print_binary_file(bin);
            }
    }
    fclose(text);
    fclose(bin);

    return 0;
}