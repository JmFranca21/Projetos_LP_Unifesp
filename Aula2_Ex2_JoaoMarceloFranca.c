
#include <stdio.h>

int main()
{
    int A;
    int B;
    printf("Insira um valor para a variável A: ");
    scanf("%d", &A);
    printf("Agora insira um valor para a variável B: ");
    scanf("%d", &B);
    int C;
    C = B;
    B = A;
    A = C;
    printf("Após a troca dos valores, a variável A passa a valer %d e a variável B passa a valer %d.", A, B);
}