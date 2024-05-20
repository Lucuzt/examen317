#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    int M, N;

    std::cout << "Ingrese el número de procesadores (vectores): ";
    std::cin >> M;
    std::cout << "Ingrese el número de términos: ";
    std::cin >> N;

    // Calculamos cuántos términos calculará cada proceso
    int terms_per_process = N / M;

    // Inicializamos un vector para almacenar los resultados de cada proceso
    std::vector<std::vector<int>> results(M, std::vector<int>(terms_per_process));

#pragma omp parallel num_threads(M)
    {
        int id = omp_get_thread_num();

        // Calculamos el rango de términos para este proceso
        int start_term = id * terms_per_process + 1;
        int end_term = start_term + terms_per_process - 1;

        // Generamos la serie para este proceso
        for (int i = start_term; i <= end_term; ++i) {
            results[id][i - start_term] = i * 2;
        }

        // Imprimimos los resultados de este proceso
#pragma omp critical
        {
            std::cout << "Proceso " << id << ": ";
            for (int j = 0; j < terms_per_process; ++j) {
                std::cout << results[id][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
