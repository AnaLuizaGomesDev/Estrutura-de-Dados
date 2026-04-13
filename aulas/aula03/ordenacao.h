#ifndef ORDENACAO_H
#define ORDENACAO_H

void troca(int *a, int *b);
void bubble_sort(int v[], int n);
void imprimir_vetor(int v[], int n);
void quick_sort(int v[], int inicio, int fim);
int particionar_vetor(int v[], int inicio, int fim);

#endif