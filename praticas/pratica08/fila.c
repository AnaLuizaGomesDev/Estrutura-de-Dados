#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct fila_t {
    no_t* inicio;
    no_t* fim;
};

Fila* fila_criar() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

int fila_esta_vazia(Fila *f) {
    if (f == NULL || f->inicio == NULL) {
        return 1;
    }
    return 0;
}

int fila_enfileirar(Fila *f, int valor) {
    if (f == NULL) return 0;

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0; 

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo; 
    } else {
        f->fim->proximo = novo; 
    }

    f->fim = novo; 
    return 1;
}

int fila_desenfileirar(Fila *f) {
    if (f == NULL || fila_esta_vazia(f)) return -1;

    no_t* auxiliar = f->inicio;
    int valor_retorno = auxiliar->valor;

    f->inicio = f->inicio->proximo; 

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(auxiliar); 
    return valor_retorno;
}

int fila_inicio(Fila *f) {
    if (f == NULL || fila_esta_vazia(f)) return -1;
    return f->inicio->valor;
}

void lista_exibir(Fila *f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    no_t* atual = f->inicio;
    printf("Fila (Inicio -> Fim): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void fila_destruir(Fila *f) {
    if (f == NULL) return;

    no_t* atual = f->inicio;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(f);
}