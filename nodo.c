#include <stdlib.h>
#include "nodo.h"

Nodo* criar_nodo(int valor) {
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    if (!novo) return NULL;
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

int obter_valor(Nodo *nodo) {
    return nodo->valor;
}

void definir_valor(Nodo *nodo, int valor) {
    nodo->valor = valor;
}

Nodo* obter_anterior(Nodo *nodo) {
    return nodo->anterior;
}

Nodo* obter_proximo(Nodo *nodo) {
    return nodo->proximo;
}

void definir_anterior(Nodo *nodo, Nodo *anterior) {
    nodo->anterior = anterior;
}

void definir_proximo(Nodo *nodo, Nodo *proximo) {
    nodo->proximo = proximo;
}

void destruir_nodo(Nodo *nodo) {
    free(nodo);
}
