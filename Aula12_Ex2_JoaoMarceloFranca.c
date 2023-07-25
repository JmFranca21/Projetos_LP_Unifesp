#include <stdio.h>
#include <string.h>

void cripto(char texto[]) {
    int tamanho = strlen(texto);
    for (int i = 0; i < tamanho; i++) {
        texto[i] = texto[i] + 3;
    }
}

int main() {
    char texto[100];
    printf("Digite o texto a ser criptografado: ");
    fgets(texto, 100, stdin);
    cripto(texto);
    printf("Texto criptografado: %s", texto);
    return 0;
}
