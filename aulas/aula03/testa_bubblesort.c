#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ordenacao.h"

#define TAMANHO 100000

int main() {
    int vetor[TAMANHO];
    for(int i=0; i < TAMANHO; i++){
        vetor[i] = rand();
    }

    printf("vetor antes de ordenar:\n");
    //imprimir_vetor(vetor, TAMANHO);

    clock_t inicio = clock();
    //ordenacao
    bubble_sort(vetor, TAMANHO);
    clock_t termino = clock();
    float duracao = (float)(termino - inicio) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao: %f segundos\n", duracao);

    printf("\nvetor depois de ordenar:\n");
    //imprimir_vetor(vetor, TAMANHO);

    return 0;
}