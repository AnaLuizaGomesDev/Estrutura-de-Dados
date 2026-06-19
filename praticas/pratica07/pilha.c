#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct  pilha_t {
    no_t* topo;
};

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int pilha_esta_vazia(Pilha *p) {
    return (p->topo == NULL);
}

int pilha_empilhar(Pilha *p, int valor) {
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0; 

    novo->valor = valor;
    novo->proximo = p->topo; 
    p->topo = novo;          
    return 1;
}

int pilha_desempilhar(Pilha *p) {
    if (pilha_esta_vazia(p)) return -1;

    no_t* auxiliar = p->topo;
    int valor_retorno = auxiliar->valor;

    p->topo = p->topo->proximo; 
    free(auxiliar);             

    return valor_retorno;
}

int pilha_topo(Pilha *p) {
    if (pilha_esta_vazia(p)) return -1;
    return p->topo->valor;
}

void pilha_exibir(Pilha *p) {
    if (pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    no_t* atual = p->topo;
    printf("Pilha (Topo -> Base): ");
    while (atual != NULL) {
        printf("[%d] -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void pilha_destruir(Pilha *p) {
    no_t* atual = p->topo;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(p);
}