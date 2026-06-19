#include <stdio.h>

void buscar(int alvo) {
    int vetor[100];
    for (int i = 0; i < 100; i++) vetor[i] = i; 

    int encontrado = -1;
    for (int i = 0; i < 100; i++) {
        if (vetor[i] == alvo) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) printf("Indice: %d\n\n", encontrado);
}

int main() {
    printf("[Valor qualquer]\n");
    buscar(42);
    printf("[Melhor caso O(1)]\n");
    buscar(0);  // melhor caso
    printf("[Pior Caso O(n)]\n");
    buscar(99); // pior caso
    return 0;
}