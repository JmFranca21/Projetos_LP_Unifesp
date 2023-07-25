#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, len;
    int flag = 0;

    printf("Digite uma string: ");
    scanf("%s", str);

    len = strlen(str);

    for(i=0;i < len ;i++)
    {
        if(str[i] != str[len-i-1])
        {
            flag = 1;
            break;
        }
    }

    if (flag) {
        printf("Não é um palíndromo.\n");
    }    
    else {
        printf("Sim, é um palíndromo.\n");
    }
    
    return 0;
}
