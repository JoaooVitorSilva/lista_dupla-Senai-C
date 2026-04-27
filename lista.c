#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Lista* criar_lista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (!lista) return NULL;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

int esta_vazia(Lista *lista) {
    return lista->tamanho == 0;
}

int obter_tamanho(Lista *lista) {
    return lista->tamanho;
}

void destruir_lista(Lista *lista) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        Nodo *proximo = atual->proximo;
        destruir_nodo(atual);
        atual = proximo;
    }
    free(lista);
}

int inserir_inicio(Lista *lista, int valor) {
    Nodo *novo = criar_nodo(valor);
    if (!novo) return 0;

    if (esta_vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->proximo = lista->inicio;
        lista->inicio->anterior = novo;
        lista->inicio = novo;
    }

    lista->tamanho++;
    return 1;
}

int inserir_fim(Lista *lista, int valor) {
    Nodo *novo = criar_nodo(valor);
    if (!novo) return 0;

    if (esta_vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->anterior = lista->fim;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }

    lista->tamanho++;
    return 1;
}

int inserir_posicao(Lista *lista, int valor, int posicao) {
    if (posicao < 0 || posicao > lista->tamanho) return 0;

    if (posicao == 0) return inserir_inicio(lista, valor);
    if (posicao == lista->tamanho) return inserir_fim(lista, valor);

    Nodo *novo = criar_nodo(valor);
    if (!novo) return 0;

    Nodo *atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    Nodo *anterior = atual->anterior;
    novo->proximo = atual;
    novo->anterior = anterior;
    anterior->proximo = novo;
    atual->anterior = novo;

    lista->tamanho++;
    return 1;
}

void imprimir_inicio_fim(Lista *lista) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void imprimir_fim_inicio(Lista *lista) {
    Nodo *atual = lista->fim;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

int remover_inicio(Lista *lista, int *valor_removido) {
    if (esta_vazia(lista)) return 0;

    Nodo *remover = lista->inicio;
    *valor_removido = remover->valor;

    if (lista->tamanho == 1) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->inicio = remover->proximo;
        lista->inicio->anterior = NULL;
    }

    destruir_nodo(remover);
    lista->tamanho--;
    return 1;
}

int remover_fim(Lista *lista, int *valor_removido) {
    if (esta_vazia(lista)) return 0;

    Nodo *remover = lista->fim;
    *valor_removido = remover->valor;

    if (lista->tamanho == 1) {
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        lista->fim = remover->anterior;
        lista->fim->proximo = NULL;
    }

    destruir_nodo(remover);
    lista->tamanho--;
    return 1;
}

Nodo* buscar(Lista *lista, int valor) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int remover_valor(Lista *lista, int valor) {
    Nodo *nodo = buscar(lista, valor);
    if (!nodo) return 0;

    if (nodo == lista->inicio) {
        int v;
        return remover_inicio(lista, &v);
    }

    if (nodo == lista->fim) {
        int v;
        return remover_fim(lista, &v);
    }

    nodo->anterior->proximo = nodo->proximo;
    nodo->proximo->anterior = nodo->anterior;
    destruir_nodo(nodo);
    lista->tamanho--;
    return 1;
}
