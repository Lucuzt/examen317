#include <stdio.h>

// Función para sumar dos números
void suma(int *a, int *b, int *resultado) {
*resultado = *a + *b;
}

// Función para restar dos números
void resta(int *a, int *b, int *resultado) {
*resultado = *a - *b;
}

// Función para multiplicar dos números usando sumas repetidas
void multiplicacion(int *a, int *b, int *resultado) {
*resultado = 0;
int multiplicando = *a;
int multiplicador = *b;
for (int i = 0; i < multiplicador; i++) {
*resultado += multiplicando;
}
}

// Función para dividir dos números usando restas repetidas
void division(int *a, int *b, int *resultado) {
*resultado = 0;
int dividendo = *a;
int divisor = *b;
while (dividendo >= divisor) {
dividendo -= divisor;
(*resultado)++;
}
}

int main() {
int a, b;
int resultado;

// Pedir al usuario que introduzca los números
printf("Introduce el primer número: ");
scanf("%d", &a);
printf("Introduce el segundo número: ");
scanf("%d", &b);

// Suma
suma(&a, &b, &resultado);
printf("Suma: %d + %d = %d\n", a, b, resultado);

// Resta
resta(&a, &b, &resultado);
printf("Resta: %d - %d = %d\n", a, b, resultado);

// Multiplicación
multiplicacion(&a, &b, &resultado);
printf("Multiplicación: %d * %d = %d\n", a, b, resultado);

// División
if (b != 0) {
division(&a, &b, &resultado);
printf("División: %d / %d = %d\n", a, b, resultado);
} else {
printf("División: No se puede dividir por cero.\n");
}

return 0;
}
