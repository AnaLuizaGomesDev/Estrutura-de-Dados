#include <stdio.h>
#include "lista_linear.h"

void lista_exibir(Lista *l);

int main() {
    Lista *minha_lista = criar_lista();

    lista_inserir_final(minha_lista, 10);
    lista_inserir_final(minha_lista, 20);
    lista_inserir_inicio(minha_lista, 5); 
    lista_inserir_final(minha_lista, 30);

    lista_exibir(minha_lista);

    int pos = lista_buscar_valor(minha_lista, 20);
    printf("O valor 20 esta na posicao: %d\n", pos);

    lista_remover_valor(minha_lista, 10);
    printf("Apos remover o 10: ");
    lista_exibir(minha_lista);

    destruir_lista(minha_lista);
    printf("Lista destruida.\n");

    return 0;
}