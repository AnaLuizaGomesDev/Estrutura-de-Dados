#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct hash_t {
    no_t** tabela; 
    int tamanho;   
};

int funcao_hash(int chave, int tamanho) {
    if (chave < 0) chave = -chave; 
    return chave % tamanho;
}

TabelaHash* hash_criar(int tamanho) {
    TabelaHash* h = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (h != NULL) {
        h->tamanho = tamanho;
        h->tabela = (no_t**) malloc(tamanho * sizeof(no_t*));
        for (int i = 0; i < tamanho; i++) {
            h->tabela[i] = NULL;
        }
    }
    return h;
}

int hash_esta_vazia(TabelaHash *h) {
    if (h == NULL) return 1;
    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return 0; 
        }
    }
    return 1;
}

int hash_inserir(TabelaHash *h, int valor) {
    if (h == NULL) return 0;

    int indice = funcao_hash(valor, h->tamanho);

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return 0;
    
    novo->valor = valor;
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;

    return 1;
}

int hash_buscar(TabelaHash *h, int valor) {
    if (h == NULL) return 0;

    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

int hash_remover(TabelaHash *h, int valor) {
    if (h == NULL) return 0;

    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];
    no_t* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return 0; 

    if (anterior == NULL) {
        h->tabela[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1; 
}

void hash_exibir(TabelaHash *h) {
    if (h == NULL) return;

    printf("--- Estado da Tabela Hash ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("Indice [%d]: ", i);
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
    printf("-----------------------------\n");
}

void hash_destruir(TabelaHash *h) {
    if (h == NULL) return;

    for (int i = 0; i < h->tamanho; i++) {
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            no_t* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(h->tabela);
    free(h);
}