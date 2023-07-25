#include <stdio.h>

int main() 
{
   int num, i;
   printf("Insira um número e descubra sua tabuada: \n");
   scanf("%d", &num);
   i = 1;
   while (i <= 10)
   {
       printf("%d x %d = %d\n", num, i, (num*i));
       i++;
   }
   
   return (0);
}

