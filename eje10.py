import multiprocessing

def generate_series(start, end, result, index):
    """Genera una serie de números pares desde el inicio hasta el final."""
    series = []
    for i in range(start, end + 1):
        series.append(i * 2)
    result[index] = series
    print(f"Proceso {index}: {series}")

if __name__ == "__main__":
    # Solicitar al usuario que ingrese el número de términos y el número de procesos
    N = int(input("Ingrese el número de términos: "))
    M = int(input("Ingrese el número de procesos: "))

    # Crear una lista para almacenar los resultados de cada proceso
    manager = multiprocessing.Manager()
    result = manager.dict()

    # Calcular cuántos términos calculará cada proceso
    terms_per_process = N // M
    processes = []

    for i in range(M):
        start_term = i * terms_per_process + 1
        end_term = start_term + terms_per_process - 1

        if i == M - 1:  # Ajustar el último proceso para que cubra el resto de términos
            end_term = N

        p = multiprocessing.Process(target=generate_series, args=(start_term, end_term, result, i))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

    # Combinar y mostrar los resultados
    series = []
    for i in range(M):
        series.extend(result[i])

    print("\nSerie generada:", series)
