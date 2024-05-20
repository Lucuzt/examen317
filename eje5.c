#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printVector(int vector[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d\n", vector[i]);
    }
}

int main(int argc, char** argv) {
    int rank, size;
    int matrix[N][N] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
    int vector[N] = { 1, 2, 3, 4 };
    int result[N] = { 0 };
    int local_result[N] = { 0 };

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Each process calculates a part of the result
    for (int i = 0; i < N; i++) {
        local_result[i] = 0;
        for (int j = 0; j < N; j++) {
            local_result[i] += matrix[i][j] * vector[j];
        }
    }

    // Gathering results from all processes
    MPI_Reduce(local_result, result, N, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Printing the final result
    if (rank == 0) {
        printf("Matrix:\n");
        printMatrix(matrix);
        printf("Vector:\n");
        printVector(vector);
        printf("Result:\n");
        printVector(result);
    }

    MPI_Finalize();
    return 0;
}
