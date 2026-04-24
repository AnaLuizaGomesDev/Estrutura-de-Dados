#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "selecao.h"

int main() {
    int n = 100;
    int k = 50; 
    int original[100], teste[100];
    clock_t inicio, fim;

    srand(time(NULL));
    for (int i = 0; i < n; i++) original[i] = rand() % 1000;

    memcpy(teste, original, n * sizeof(int));
    inicio = clock();
    int res_linear = linear_search(teste, n, k);
    fim = clock();
    printf("Linear Search (Pos %d): Valor %d | Tempo: %f s\n", k, res_linear, (double)(fim - inicio) / CLOCKS_PER_SEC);

    memcpy(teste, original, n * sizeof(int));
    inicio = clock();
    int res_quick = quick_select(teste, 0, n - 1, k);
    fim = clock();
    printf("Quick Select  (Pos %d): Valor %d | Tempo: %f s\n", k, res_quick, (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}