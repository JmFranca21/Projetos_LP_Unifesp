#include <stdio.h>
#include <stdlib.h>

int avista (int gasto) {
    int total;
    total = gasto * 0.9;
    return total;
}

int duasvezes (int gasto) {
    int total;
    total = gasto;
    return total;
}

int tresdez (int gasto) {
    int total;
    total = gasto * 1.09;

    return total;
}

int main () {
    int gasto, choice, i, j, aux;

    printf("1) A vista com 10 por cento de desconto\n");
    printf("2) Em duas vezes (preço da etiqueta)\n");
    printf("3) De 3 até 10 vezes com 3 por cento de juros ao mês (somente para compras acima de R$ 100,00)\n");
    
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Digite o valor da compra: ");
        scanf("%d", &gasto);
        printf("O valor total da compra foi: %d\n", avista(gasto));
    }
    else if (choice == 2) {
        printf("Digite o valor da compra: ");
        scanf("%d", &gasto);
        printf("O valor total da compra foi: %d\n", duasvezes(gasto));
    }
    else if (choice == 3) {
        printf("Digite o valor da compra: ");
        scanf("%d", &gasto);
        if (gasto > 100) {
            printf("O valor total da compra foi: %d\n", tresdez(gasto));
        }
        else {
            printf("O valor total da compra foi: %d\n", gasto);
        }
        
    }
}