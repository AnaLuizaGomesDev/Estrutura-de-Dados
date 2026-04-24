#include <stdio.h>

void calcular_imc(float peso, float altura) {
    if (peso <= 0 || altura <= 0) return;

    float imc = peso / (altura * altura);

    if (imc < 18.5) printf("Abaixo do Peso, IMC: %.2f\n", imc);
    else if(imc <= 24.9) printf("Peso normal, IMC: %.2f\n", imc);
    else if(imc <= 29.9) printf("Sobrepeso, IMC: %.2f\n", imc);
    else printf("Obesidade, IMC: %.2f\n", imc);
}

int main () {

    calcular_imc(50.0, 1.80); // abaixo do peso
    calcular_imc(70.0, 1.75); // peso normal
    calcular_imc(85.0, 1.70); // sobrepeso
    calcular_imc(100.0, 1.65); // exemplo de erro

    return 0;
}