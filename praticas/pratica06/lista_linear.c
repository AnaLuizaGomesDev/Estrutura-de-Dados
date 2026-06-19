#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} no_t;

struct lista {
    no_t* primeiro;
    no_t* ultimo;
};

Lista *criar_lista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    return l;
}

int lista_vazia(Lista *l) {
    return (l->primeiro == NULL);
}

int lista_inserir_inicio(Lista *l, int valor) {
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = l->primeiro;

    if (lista_vazia(l)) {
        l->ultimo = novo;
    } else {
        l->primeiro->anterior = novo;
    }
    
    l->primeiro = novo;
    return 1; 
}

int lista_inserir_final(Lista *l, int valor) {
    no_t* novo = (no_t*) malloc(sizeof(no_t));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (lista_vazia(l)) {
        l->primeiro = novo;
    } else {
        l->ultimo->proximo = novo;
    }

    l->ultimo = novo;
    return 1; 
}

int lista_buscar_valor(Lista *l, int valor) {
    no_t* atual = l->primeiro;
    int indice = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1;
}

int lista_remover_valor(Lista *l, int valor) {
    no_t* atual = l->primeiro;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return 0; 

    if (atual == l->primeiro) {
        l->primeiro = atual->proximo;
    } else {
        atual->anterior->proximo = atual->proximo;
    }

    if (atual == l->ultimo) {
        l->ultimo = atual->anterior;
    } else {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
    return 1; 
}

void lista_exibir(Lista *l) {
    no_t* atual = l->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void destruir_lista(Lista *l) {
    no_t* atual = l->primeiro;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(l);
}