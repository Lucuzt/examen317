import multiprocessing
import time

def calcular_pi_parte(inicio, fin, paso):
    suma = 0.0
    for i in range(inicio, fin):
        x = (i + 0.5) * paso
        suma += 4.0 / (1.0 + x**2)
    return suma

def main():
    num_pasos = 10000000
    num_procesos = 4
    paso = 1.0 / num_pasos
    inicio = time.time()

    pool = multiprocessing.Pool(processes=num_procesos)
    resultados = []

    for i in range(num_procesos):
        inicio_rango = i * (num_pasos // num_procesos)
        fin_rango = (i + 1) * (num_pasos // num_procesos)
        resultados.append(pool.apply_async(calcular_pi_parte, (inicio_rango, fin_rango, paso)))

    pool.close()
    pool.join()

    suma_total = sum(resultado.get() for resultado in resultados)
    pi = suma_total * paso
    fin = time.time()

    print("El valor aproximado de π es:", pi)
    print("Tiempo de cálculo:", fin - inicio, "segundos")

if __name__ == "__main__":
    main()
