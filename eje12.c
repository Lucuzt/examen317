#include <stdio.h>
#include <mpi.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 7; // El término de Fibonacci que deseas calcular
    int result;

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
        result = fibonacci(n);
        printf("El término %d de Fibonacci es %d\n", n, result);
    }
    else {
        MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        result = fibonacci(n);
        printf("Proceso %d calculó el término %d de Fibonacci como %d\n", rank, n, result);
    }

    MPI_Finalize();
    return 0;
}
