#include <stdio.h>


int main() {
  int n, s[100], i, j, k;
  i = 0;
  j = 0;
  k = 0;

  printf("n = "), scanf(" %d", &n);
  printf("Digite uma sequência de %d números\n\n", n);
  
  do scanf(" %d", &s[i]); while (++i < n);
  i = 0;

  printf("\n%d",s[0]);
  while (++i < n) {
    k = 0;
    do {
      if (s[i] == s[j])
        k = 1; 
    } while (++j < i);
    j = 0;
    if (k != 1)
      printf(", %d",s[i]);
  }

  return 0;
}