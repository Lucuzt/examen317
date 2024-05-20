#include <iostream>

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
std::cout << "Introduce el primer número: ";
std::cin >> a;
std::cout << "Introduce el segundo número: ";
std::cin >> b;

// Suma
suma(&a, &b, &resultado);
std::cout << "Suma: " << a << " + " << b << " = " << resultado << std::endl;

// Resta
resta(&a, &b, &resultado);
std::cout << "Resta: " << a << " - " << b << " = " << resultado << std::endl;

// Multiplicación
multiplicacion(&a, &b, &resultado);
std::cout << "Multiplicación: " << a << " * " << b << " = " << resultado << std::endl;

// División
if (b != 0) {
division(&a, &b, &resultado);
std::cout << "División: " << a << " / " << b << " = " << resultado << std::endl;
} else {
std::cout << "División: No se puede dividir por cero." << std::endl;
}

return 0;
}
