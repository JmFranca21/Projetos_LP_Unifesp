#include <stdio.h>

int main() {
    float temperaturas[7], menor, maior, media = 0;

    for (int i = 0; i < 7; i++) {
        printf("Digite a temperatura do dia %d em graus Celsius: ", i + 1);
        scanf("%f", &temperaturas[i]);

        if (i == 0) {
            menor = temperaturas[i];
            maior = temperaturas[i];
        } else {
            if (temperaturas[i] < menor) {
                menor = temperaturas[i];
            }

            if (temperaturas[i] > maior) {
                maior = temperaturas[i];
            }
        }

        media += temperaturas[i];
    }

    media /= 7;

    printf("\nMenor temperatura da semana: %.2f °C\n", menor);
    printf("Maior temperatura da semana: %.2f °C\n", maior);
    printf("Temperatura média semanal: %.2f °C\n", media);

    return 0;
}
