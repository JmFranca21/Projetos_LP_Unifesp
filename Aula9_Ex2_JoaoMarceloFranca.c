#include <stdio.h>

int main()
{
    int n, i;
    int fatorial = 1;

    printf("Digite um número inteiro: ");
    scanf("%d",&n);
    if (n < 0)
        printf("Erro! Fatorial de um número negativo não existe.");
    else
    {
        for(i=1; i<=n; ++i)
        {
            fatorial *= i;              // fatorial = fatorial*i;
        }
        printf("Fatorial de %d = %d", n, fatorial);
    }

    return 0;
}

