#include <stdio.h>

int main() {
    int m, n, p;
    printf("Digite os valores de m, n e p: ");
    scanf("%d %d %d", &m, &n, &p);

    int A[m][n], B[n][p], D[m][p];

    printf("Digite os valores da matriz A: ");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os valores da matriz B: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            D[i][j] = 0;
            for (int k = 0; k < n; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("A matriz resultante é: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
