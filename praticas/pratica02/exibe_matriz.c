#include <stdio.h>
#include <time.h>

void processar_matriz() {
    int mat[10][10];
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) mat[i][j] = i + j;

    clock_t inicio, fim;

    inicio = clock();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int v = mat[i][j]; 
        }
    }
    fim = clock();
    printf("Tempo (2 lacos) O(n^2): %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    int *ptr = &mat[0][0];
    for (int i = 0; i < 100; i++) {
        int v = ptr[i];
    }
    fim = clock();
    printf("Tempo (1 laco) O(n^2): %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
}

int main() {
    processar_matriz(); 
    return 0;
}