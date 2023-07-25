#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	char genero[30];
	int integrantes;
	int ranking;
} BANDA;

void Preenche(BANDA banda[]) {
	int i;
	for (i = 0; i < 5; i++) {
		system("clear");
		
		printf("Nome da banda: ");
		scanf("%s", banda[i].nome);

		printf("\nGênero musical: ");
		scanf("%s", banda[i].genero);

		printf("\nN° de integrantes: ");
		scanf("%d", &banda[i].integrantes);

		printf("\nRanking pessoal: ");
		scanf("%d", &banda[i].ranking);
	}
}

void Imprime(BANDA banda[]) {
	int i;
	for (i = 0; i < 5; i++) {
		printf("\nNome da banda: %s.\n", banda[i].nome);
		printf("Gênero musical: %s.\n", banda[i].genero);
		printf("N° de integrantes: %d.\n", banda[i].integrantes);
		printf("Posição no ranking pessoal: %d. \n\n", banda[i].ranking);

	}
}

int main(void) {
	BANDA banda[5];
	Preenche(banda);
	Imprime(banda);
  return 0;
}