#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"

void resetar_vetor(int origem[], int destino[], int n) {
    memcpy(destino, origem, n * sizeof(int));
}

int main() {
    int n = 100;
    int original[100], teste[100];
    clock_t inicio, fim;

    srand(time(NULL));
    for (int i = 0; i < n; i++) original[i] = rand() % 1000;

    resetar_vetor(original, teste, n);
    inicio = clock();
    bubble_sort(teste, n);
    fim = clock();
    printf("Bubble Sort O(n^2): %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    resetar_vetor(original, teste, n);
    inicio = clock();
    selection_sort(teste, n);
    fim = clock();
    printf("Selection Sort O(n^2): %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    resetar_vetor(original, teste, n);
    inicio = clock();
    quick_sort(teste, 0, n - 1);
    fim = clock();
    printf("Quick Sort O(n log n): %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}