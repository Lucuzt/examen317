#include <omp.h>

int main() {
int a, b;
printf("Ingrese el primer número (a): ");
scanf("%d", &a);
printf("Ingrese el segundo número (b): ");
scanf("%d", &b);

int result_multiply = 0;
int result_divide = 0;

#pragma omp parallel sections
{
#pragma omp section
{
// Multiplicación utilizando sumas
#pragma omp parallel for reduction(+:result_multiply)
for (int i = 0; i < b; i++) {
result_multiply += a;
}
}

#pragma omp section
{
// División utilizando restas
int temp = a;
while (temp >= b) {
temp -= b;
result_divide++;
}
}
}

printf("Multiplicación: %d\n", result_multiply);
printf("División: %d\n", result_divide);

return 0;
}
