#include <stdio.h>
#include "tabela_hash.h"

int main() {
    printf("=== Testando Tabela Hash ===\n\n");

    TabelaHash *minha_hash = hash_criar(5);
    printf("Tabela criada. Esta vazia? %s\n\n", hash_esta_vazia(minha_hash) ? "Sim" : "Nao");

    printf("-> Inserindo valores: 10, 22, 31, 15, 44\n");
    hash_inserir(minha_hash, 10);
    hash_inserir(minha_hash, 22);
    hash_inserir(minha_hash, 31);
    hash_inserir(minha_hash, 15);
    hash_inserir(minha_hash, 44);

    hash_exibir(minha_hash);
    printf("\n");

    printf("-> Buscando o valor 15: %s\n", hash_buscar(minha_hash, 15) ? "Encontrado!" : "Nao encontrado.");
    printf("-> Buscando o valor 99: %s\n\n", hash_buscar(minha_hash, 99) ? "Encontrado!" : "Nao encontrado.");

    printf("-> Removendo o valor 15 (colisao do indice 0)...\n");
    hash_remover(minha_hash, 15);
    hash_exibir(minha_hash);
    printf("\n");

    printf("-> Removendo o valor 22...\n");
    hash_remover(minha_hash, 22);
    hash_exibir(minha_hash);
    printf("\n");

    printf("-> Destruindo a tabela hash e limpando memoria...\n");
    hash_destruir(minha_hash);
    printf("Pronto!\n");

    return 0;
}