#include "selecao.h"

// Complexidade: O(n) 
int linear_search(int v[], int n, int k) {
    if (k >= 0 && k < n) {
        return v[k];
    }
    return -1;
}

// Complexidade: O(n) 
int quick_select(int v[], int inicio, int fim, int k) {
    if (inicio <= fim) {
        int pivo = v[fim];
        int i = inicio;
        for (int j = inicio; j < fim; j++) {
            if (v[j] <= pivo) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
            }
        }
        int temp = v[i];
        v[i] = v[fim];
        v[fim] = temp;
        int p = i;

        if (p == k) return v[p];
        
        if (p > k) return quick_select(v, inicio, p - 1, k);
        return quick_select(v, p + 1, fim, k);
    }
    return -1;
}