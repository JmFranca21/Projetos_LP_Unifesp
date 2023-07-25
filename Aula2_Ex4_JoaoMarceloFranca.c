
#include <stdio.h>

int main()
{
    int AN, AA, IP, IF;
    printf("Por favor, informe seu ano de nascimento: ");
    scanf("%d", &AN);
    printf("Agora informe o ano atual: ");
    scanf("%d", &AA);
    IP = AA - AN;
    IF = 2050 - AN;
    printf("Atualmente, você tem %d anos. \n Em 2050 você terá %d anos.", IP, IF);
}
