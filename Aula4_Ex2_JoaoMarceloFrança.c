
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2, d;
    printf("Digite o valor de a: \n");
    scanf("%f", &a);
    printf("Digite o valor de b: \n");
    scanf("%f", &b);
    printf("Digite o valor de c: \n");
    scanf("%f", &c);
    d = (pow(b,2))-4*a*c;
    x1 = ((-b+sqrt(d))/(2*a));
    x2 = ((-b-sqrt(d))/(2*a));
    if (d > 0)
        printf("x1 = %f\nx2 = %f\n", x1, x2);
    else if (d == 0)
        printf("x1 = x2 = %f\n", x1);
    else
        printf("Não existe raiz! (delta negativo)\n");
        
    return 0;
}

