#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H
typedef struct lista Lista;

Lista *criar_lista();
int lista_vazia(Lista *l);
int lista_inserir_inicio(Lista *l, int valor);
int lista_inserir_final(Lista *l, int valor);
int lista_remover_valor(Lista *l, int valor);
int lista_buscar_valor(Lista *l, int valor);
void destruir_lista(Lista *l);
#endif
