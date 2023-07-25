
#include <stdio.h>
#include <math.h>

int main()
{
    int N, Q, C, R;
    printf("Insira um valor inteiro para descobrir seu, quadrado, cubo e raiz quadrada: ");
    scanf("%d", &N);
    Q = N*N;
    C = N*N*N;
    R = sqrt(N);
    printf("O quadrado vale: %d \n", Q);
    printf("O cubo vale: %d \n", C);
    printf("A raiz quadrada vale: %d", R);
    
}
