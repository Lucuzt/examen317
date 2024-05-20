#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 4// Tamaño de la matriz y vector

int main() {
    // Declaración de la matriz y el vector
    double matriz[N][N];
    double vector[N];
    double resultado[N];

    // Inicialización de la matriz y el vector con datos aleatorios
    srand(123); // Seed para reproducibilidad, puedes cambiarla o eliminarla
    for (int i = 0; i < N; i++) {
        vector[i] = (double)rand() / RAND_MAX; // Genera un número aleatorio entre 0 y 1
        for (int j = 0; j < N; j++) {
            matriz[i][j] = (double)rand() / RAND_MAX; // Genera un número aleatorio entre 0 y 1
        }
    }

    // Inicialización del vector resultado
    for (int i = 0; i < N; i++) {
        resultado[i] = 0.0;
    }

    // Multiplicación de la matriz por el vector usando OpenMP
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }

    // Mostrar el resultado
    printf("Resultado:\n");
    for (int i = 0; i < N; i++) {
        printf("%f ", resultado[i]);
    }
    printf("\n");

    return 0;
}
