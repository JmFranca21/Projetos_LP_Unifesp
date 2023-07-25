#include <stdio.h>
int main ()
{
    float P1, P2, T1, T2, T3, M1, M2, M3, NF;
    printf("Insira suas notas:\n");
    printf("P1 = ");
    scanf("%f", &P1);
    printf("P2 = ");
    scanf("%f", &P2);
    printf("T1 = ");
    scanf("%f", &T1);
    printf("T2 = ");
    scanf("%f", &T2);
    printf("T3 = ");
    scanf("%f", &T3);
    printf("M3 = ");
    scanf("%f", &M3);
    M1 = (P1+P2)/2;
    M2 = (T1+T2+T3)/3;
    NF = ((M1*0.6)+(M2*0.3)+(M3*0.1));
    printf("Sua nota final é: %.2f.\n", NF);
    
    return 0;
}