#include <stdio.h>
#include <stdlib.h>

float RecebeCotacao () {
    float cotacao;
    printf("Digite a cotacao do dolar: ");
    scanf("%f", &cotacao);
    return cotacao;
}

float RecebeValor () {
    float valor;
    printf("Digite o valor em dolar: ");
    scanf("%f", &valor);
    return valor;
}

float ConverteEmReal () {
    float cotacao = RecebeCotacao();
    float valor = RecebeValor();
    float real = cotacao * valor;
    return real;
}
int main()
{
    float real = ConverteEmReal();
    system("cls");
    printf("O valor em reais eh: RS %.2f", real);
    return 0;
}