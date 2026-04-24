#include <stdio.h>

void calcular_media(int n, float numeros[]) {
    if (n <= 0 || n > 100) return;

    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += numeros[i];
    }
    printf("%.2f\n", soma / n);
}

int main() {
    float valores[] = {7.5, 8.0, 9.2};
    calcular_media(3, valores);
    return 0;
}