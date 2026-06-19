#include <stdio.h>
#include "fila.h"

int main() {
    printf("=== Testando Fila ===\n\n");

    Fila *minha_fila = fila_criar();
    printf("Fila criada. Está vazia? %s\n", fila_esta_vazia(minha_fila) ? "Sim" : "Não");

    printf("\n-> Enfileirando: 10, 20, 30\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    
    lista_exibir(minha_fila);

    printf("\n-> Elemento no início atualmente: %d\n", fila_inicio(minha_fila));

    printf("\n-> Desenfileirando um elemento (quem sai primeiro?): %d\n", fila_desenfileirar(minha_fila));
    lista_exibir(minha_fila);

    printf("-> Desenfileirando outro elemento: %d\n", fila_desenfileirar(minha_fila));
    lista_exibir(minha_fila);

    printf("\n-> Destruindo a fila e limpando memoria...\n");
    fila_destruir(minha_fila);
    printf("Pronto!\n");

    return 0;
}