#include <stdio.h>

int main() {
  int A[10], B[10], Soma[10], Subtracao[10], i;
  
  i = 0;
    while ( i < 10) {
      printf("Digite o valor %d do vetor A: ", i + 1);
      scanf("%d", &A[i]);
      i++;
    }
  
    i = 0;
    while (i < 10) {
      printf("Digite o valor %d do vetor B: ", i + 1);
      scanf("%d", &B[i]);
      i++;
    }
  
    i = 0;
    while (i < 10) {
      Soma[i] = A[i] + B[i];
      Subtracao[i] = A[i] - B[i];
      i++;
    }
  
    i = 0;
    printf("\nSoma dos elementos dos vetores A e B:\n");
    while (i < 10) {
      printf("%d ", Soma[i]);
      i++;
    }
  
    i = 0;
    printf("\n\nSubtracao dos elementos dos vetores A e B:\n");
    while (i < 10) {
      printf("%d ", Subtracao[i]);
      i++;
    }

    return 0;
}
