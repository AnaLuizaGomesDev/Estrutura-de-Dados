#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    printf("=== Testando Arvore Binaria ===\n\n");

    Arvore *minha_arvore = arvore_criar();
    printf("Arvore criada. Esta vazia? %s\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");

    printf("\n-> Inserindo elementos: 50, 30, 70, 20, 40, 60, 80\n");
    arvore_inserir(minha_arvore, 50); 
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    printf("Arvore esta vazia agora? %s\n\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");

    printf("-> Percurso Pre-Ordem (Raiz -> Esq -> Dir):\n");
    arvore_exibir_pre_ordem(minha_arvore); 

    printf("\n-> Percurso Em-Ordem (Esq -> Raiz -> Dir) - (Mostra ordenado):\n");
    arvore_exibir_em_ordem(minha_arvore);

    printf("\n-> Percurso Pos-Ordem (Esq -> Dir -> Raiz):\n");
    arvore_exibir_pos_ordem(minha_arvore);

    printf("\n-> Destruindo a arvore e limpando memoria...\n");
    arvore_destruir(minha_arvore);
    printf("Pronto!\n");

    return 0;
}