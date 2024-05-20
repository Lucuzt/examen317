#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int N = 10; // Número de términos en la serie

    // Calculamos cuántos términos calculará cada proceso
    int terms_per_process = N / size;

    // Calculamos el rango de términos para este proceso
    int start_term = rank * terms_per_process + 1;
    int end_term = (rank + 1) * terms_per_process;
    if (rank == size - 1) {
        // Ajustamos el final del rango si este proceso es el último
        end_term = N;
    }

    // Generamos la serie para este proceso
    for (int i = start_term; i <= end_term; ++i) {
        int term = i * 2;
        std::cout << "Proceso " << rank << ": " << term << std::endl;
    }

    MPI_Finalize();
    return 0;
}

