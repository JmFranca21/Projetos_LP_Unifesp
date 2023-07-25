#include <stdio.h>
#include <stdlib.h>

int main() {
  char frase[100];
  int i = 0, cont_vog = 0, cont_tot = 0;
  printf("Digite uma frase:\n");
  scanf("%[^\n]", frase);
  for (i = 0; frase[i] != '\0'; i++)
    {
      if (frase[i] != '\0')
        cont_tot++;
    }
  for (i = 0; frase[i] != '\0'; i++)
    {
      if ((frase[i] == 'A') || (frase[i] == 'a') || (frase[i] == 'E') || (frase[i] == 'e') || (frase[i] == 'I') || (frase[i] == 'i') || (frase[i] == 'O') || (frase[i] == 'o') || (frase[i] == 'U') || (frase[i] == 'u'))
        cont_vog++;
    }
  printf("O númro total de caracteres é: %d\n", cont_tot);
  printf("O número de vogais na frase digitada é: %d\n", cont_vog);
  printf("portanto a frequência relativa de vogais é de %d vogais/%d caracteres.\n", cont_vog, cont_tot);
  
  return 0;
}
