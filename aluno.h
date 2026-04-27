#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int matricula;
    char nome[50];
    float media;
} Aluno;

typedef struct NodoAluno {
    Aluno dado;
    struct NodoAluno *anterior;
    struct NodoAluno *proximo;
} NodoAluno;

typedef struct {
    NodoAluno *inicio;
    NodoAluno *fim;
    int tamanho;
} ListaAlunos;

ListaAlunos* criar_lista_alunos();
void destruir_lista_alunos(ListaAlunos *lista);

int inserir_aluno_inicio(ListaAlunos *lista, Aluno aluno);
int inserir_aluno_fim(ListaAlunos *lista, Aluno aluno);

NodoAluno* buscar_por_matricula(ListaAlunos *lista, int matricula);
int remover_por_matricula(ListaAlunos *lista, int matricula);

void imprimir_aprovados(ListaAlunos *lista);
void imprimir_reprovados(ListaAlunos *lista);

#endif
