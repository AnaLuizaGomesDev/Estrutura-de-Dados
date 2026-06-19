#include <stdio.h>
#include "conta.h"

int main() {
    Conta minha_conta = conta_criar(1234, 500.0);

    printf("Saldo inicial: R$ %.2f\n", conta_ver_saldo(minha_conta));

    conta_depositar(minha_conta, 200.0);
    printf("Apos deposito de 200: R$ %.2f\n", conta_ver_saldo(minha_conta));

    if (conta_sacar(minha_conta, 100.0)) {
        printf("Saque de 100 realizado com sucesso!\n");
    }

    if (!conta_sacar(minha_conta, 1000.0)) {
        printf("Falha ao sacar 1000: Saldo insuficiente.\n");
    }

    printf("Saldo final: R$ %.2f\n", conta_ver_saldo(minha_conta));

    conta_destruir(minha_conta);

    return 0;
}