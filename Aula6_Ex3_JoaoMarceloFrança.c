#include <stdio.h> 
int main() { 
    int massa, tempo = 0, hora, min, seg; 
    printf("Indique a massa, em gramas, do material: \n"); 
    scanf("%d", &massa); 
    while (massa >= 1) { 
        massa = massa / 2; 
        tempo = tempo + 30; 
    } 
    hora = tempo / 3600; 
    min = (tempo % 3600) / 60; 
    seg = (tempo % 3600) % 60; 
    printf ("Massa final: %d.\n", massa); 
    printf ("Tempo necessário: %d horas, %d minutos, %d segundos.\n", hora, min, seg); 
    return 0; 
}
