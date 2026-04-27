#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

ListaAlunos* criar_lista_alunos() {
    ListaAlunos *lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    if (!lista) return NULL;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void destruir_lista_alunos(ListaAlunos *lista) {
    NodoAluno *atual = lista->inicio;
    while (atual != NULL) {
        NodoAluno *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

static NodoAluno* criar_nodo_aluno(Aluno aluno) {
    NodoAluno *novo = (NodoAluno*) malloc(sizeof(NodoAluno));
    if (!novo) return NULL;
    novo->dado = aluno;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

int inserir_aluno_inicio(ListaAlunos *lista, Aluno aluno) {
    NodoAluno *novo = criar_nodo_aluno(aluno);
    if (!novo) return 0;

    if (lista->tamanho == 0) {
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

int inserir_aluno_fim(ListaAlunos *lista, Aluno aluno) {
    NodoAluno *novo = criar_nodo_aluno(aluno);
    if (!novo) return 0;

    if (lista->tamanho == 0) {
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

NodoAluno* buscar_por_matricula(ListaAlunos *lista, int matricula) {
    NodoAluno *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado.matricula == matricula) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int remover_por_matricula(ListaAlunos *lista, int matricula) {
    NodoAluno *nodo = buscar_por_matricula(lista, matricula);
    if (!nodo) return 0;

    if (nodo->anterior) nodo->anterior->proximo = nodo->proximo;
    else lista->inicio = nodo->proximo;

    if (nodo->proximo) nodo->proximo->anterior = nodo->anterior;
    else lista->fim = nodo->anterior;

    free(nodo);
    lista->tamanho--;
    return 1;
}

void imprimir_aprovados(ListaAlunos *lista) {
    printf("=== Aprovados ===\n");
    NodoAluno *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado.media >= 7.0f) {
            printf("Matricula: %d | Nome: %s | Media: %.1f\n",
                atual->dado.matricula, atual->dado.nome, atual->dado.media);
        }
        atual = atual->proximo;
    }
}

void imprimir_reprovados(ListaAlunos *lista) {
    printf("=== Reprovados ===\n");
    NodoAluno *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado.media < 7.0f) {
            printf("Matricula: %d | Nome: %s | Media: %.1f\n",
                atual->dado.matricula, atual->dado.nome, atual->dado.media);
        }
        atual = atual->proximo;
    }
}
