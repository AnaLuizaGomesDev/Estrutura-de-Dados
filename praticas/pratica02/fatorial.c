#include <stdio.h>

long fatorial_iterativo(int n) {
    if (n < 0) return 0;
    long resultado = 1;
    for (int i = 1; i <= n; i++) resultado *= i;
    return resultado;
}

long fatorial_recursivo(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    printf("Iterativo (5!) O(1): %ld\n", fatorial_iterativo(5));
    printf("Recursivo (5!) O(n): %ld\n", fatorial_recursivo(5));
    return 0;
}