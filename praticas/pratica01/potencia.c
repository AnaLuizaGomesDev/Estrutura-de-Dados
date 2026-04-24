#include <stdio.h>

void calcular_potencia(int base, int expoente) {
    if (expoente < 0) return;

    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    printf("%d\n", resultado);
}

int main (){
    calcular_potencia(2, 5);
    return 0;
}