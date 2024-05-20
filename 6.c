#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define NUM_RECT 1000000
#define MASTER 0

double f(double x) {
    return 4.0 / (1.0 + x * x);
}

int main(int argc, char* argv[]) {
    int num_procs, my_rank;
    double total_sum, local_sum;
    double width = 1.0 / (double)NUM_RECT;
    double sum = 0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int chunk_size = NUM_RECT / num_procs;
    int start = my_rank * chunk_size;
    int end = start + chunk_size;

    for (int i = start; i < end; i++) {
        double x = (i + 0.5) * width;
        sum += f(x);
    }

    local_sum = sum * width;

    MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);

    if (my_rank == MASTER) {
        printf("Estimación de π: %.16f\n", total_sum);
    }

    MPI_Finalize();

    return 0;
}
