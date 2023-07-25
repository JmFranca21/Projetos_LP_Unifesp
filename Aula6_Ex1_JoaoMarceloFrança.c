#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 0, cara = 0, coroa = 0;
    srand(time(NULL));
    while (i < 10) {
        int x = rand() % 2;
        printf ("%d\n", x);
        if (x == 0) {
            cara++;
        } else {
            coroa++;
        }
            i++;
    }
    if (cara > coroa) {
       printf("Jogador 1 venceu com %d pontos.\n", cara);
       printf("Enquanto o Jogador 2 fez %d pontos.\n", coroa);
    } else if (coroa > cara) {
        printf("Jogador 2 venceu com %d pontos.\n", coroa);
        printf("Enquanto o Jogador 1 fez %d pontos.\n", cara);
    } else {
        printf("Empate!\n");
   }
    return 0;
}
