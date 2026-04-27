#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
} Lista;

Lista* criar_lista();
int esta_vazia(Lista *lista);
int obter_tamanho(Lista *lista);
void destruir_lista(Lista *lista);

int inserir_inicio(Lista *lista, int valor);
int inserir_fim(Lista *lista, int valor);
int inserir_posicao(Lista *lista, int valor, int posicao);

void imprimir_inicio_fim(Lista *lista);
void imprimir_fim_inicio(Lista *lista);

int remover_inicio(Lista *lista, int *valor_removido);
int remover_fim(Lista *lista, int *valor_removido);
int remover_valor(Lista *lista, int valor);

Nodo* buscar(Lista *lista, int valor);

#endif
