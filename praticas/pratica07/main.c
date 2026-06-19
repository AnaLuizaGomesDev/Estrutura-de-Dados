#include <stdio.h>
#include "pilha.h"

int main() {
    printf("=== Testando Pilha ===\n\n");

    Pilha *minha_pilha = pilha_criar();
    printf("Pilha criada. Está vazia? %s\n", pilha_esta_vazia(minha_pilha) ? "Sim" : "Não");

    printf("\n-> Empilhando: 10, 20, 30\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    
    pilha_exibir(minha_pilha);

    printf("\n-> Elemento no topo atualmente: %d\n", pilha_topo(minha_pilha));

    printf("\n-> Desempilhando um elemento: %d\n", pilha_desempilhar(minha_pilha));
    pilha_exibir(minha_pilha);

    printf("-> Desempilhando outro elemento: %d\n", pilha_desempilhar(minha_pilha));
    pilha_exibir(minha_pilha);

    printf("\n-> Destruindo a pilha e limpando memoria...\n");
    pilha_destruir(minha_pilha);
    printf("Pronto!\n");

    return 0;
}