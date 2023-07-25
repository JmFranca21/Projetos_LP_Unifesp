#include <stdio.h>

int main()
{
    
    float c;
    float d;
    printf("Insira a cotação do dólar hoje: ");
    scanf("%f", &c);
    printf("Insira a quantia de dinheiro que você tem em dólar: ");
    scanf("%f", &d);
    float r = c*d;
    printf("A quantia informada em dólares equivale a %.2f reais, de acordo com a cotação de hoje.", r);
    
}