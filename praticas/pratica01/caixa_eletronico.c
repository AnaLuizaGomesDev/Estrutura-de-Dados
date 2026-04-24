#include <stdio.h>

void calcular_saque(int valor) {
    if (valor <= 0 || valor > 1000) return;

    int notas[] = {200, 100, 50, 20, 10, 5, 2};

    for (int i = 0; i < 7; i++) {
        int qtd = valor / notas[i];
        if (qtd > 0) {
            printf("%d nota(s) de %d\n", qtd, notas[i]);
        }
        valor %= notas[i];
    }
}

int main() {
    calcular_saque(864);
    return 0;
}