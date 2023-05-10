#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, i, j;
    clock_t start, end;
    double cpu_time_used;

    if (argc != 2) {
    printf("Uso: %s <tamanho_sistema>\n", argv[0]);
    exit(EXIT_FAILURE);
    }

    // Tamanho do sistema
    n = atoi(argv[1]);

    // Alocar memória para as matrizes A e b e o vetor x
    double **A = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }
    double *x = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    memset(b, 0, n * sizeof(double));

    // Inicialização das matrizes A o vetor x com valores aleatórios
    for (i = 0; i < n; i++) {
        x[i] = (double)rand() / RAND_MAX;

        for (j = 0; j < n; j++) {
            A[i][j] = (double)rand() / RAND_MAX; 
        }
    }

    start = clock();

    // Cálculo do produto matriz-vetor A · x = b
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b[i] += A[i][j] * x[j];
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de CPU utilizado: %f segundos\n", cpu_time_used);

    // Liberar memória alocada
    for (i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    free(b);

    return 0;
}
