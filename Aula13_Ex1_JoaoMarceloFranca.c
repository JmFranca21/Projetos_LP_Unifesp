#include <stdio.h>
#include <stdlib.h>

int recebe_vetor () {
	int i, n, N[n], X, aux = 0;

	printf("Escolha o tamanho do vetor: ");
	scanf("%d", &n);

	printf("Digite os valores do vetor: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &N[i]);
	}

	printf("Digite um valor para saber quantas vezes ele aparece no vetor: ");
	scanf("%d", &X);

	for (i = 0; i < n; i++) {
		if (N[i] == X) {
			aux++;
		}
	}
	
	return aux;
}

int main () {
	int i, n, N[n], X, aux, rv;
	
	printf("%d", recebe_vetor());

	return 0;
}