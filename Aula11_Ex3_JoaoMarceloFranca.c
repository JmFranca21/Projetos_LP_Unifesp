#include <stdio.h>

int main(void) {
    int largura = 60;
    int altura = 10;

    for (int i = 0; i < altura; i++) {
        if (i == 0 || i == altura - 1) {
            for (int j = 0; j < largura; j++) {
                printf("+");
            }
            printf("\n");
        } else {
            printf("+");
            for (int j = 0; j < largura - 2; j++) {
                printf(" ");
            }
            printf("+\n");
        }
    }

    return 0;
}
