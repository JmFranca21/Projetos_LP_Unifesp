#include <stdio.h>

int main()
{
    int n, i, num;
    int maior, menor;

    printf("Digite o número de elementos da sequência: ");
    scanf("%d", &n);

    printf("Digite os %d elementos da sequência: ", n);
    scanf("%d", &num);

    maior = num;
    menor = num;

    for (i = 1; i < n; i++)
    {
        scanf("%d", &num);
        if (num > maior)
            maior = num;
        if (num < menor)
            menor = num;
    }

    printf("Maior número da sequência: %d\n", maior);
    printf("Menor número da sequência: %d\n", menor);

    return 0;
}


