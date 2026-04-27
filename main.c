#include <stdio.h>
#include "lista.h"
#include "aluno.h"

int main() {
    printf("=== Testando Lista Duplamente Encadeada ===\n\n");

    Lista *lista = criar_lista();

    printf("-- Inserir no inicio: 30, 20, 10 --\n");
    inserir_inicio(lista, 30);
    inserir_inicio(lista, 20);
    inserir_inicio(lista, 10);
    imprimir_inicio_fim(lista);

    printf("-- Inserir no fim: 40, 50 --\n");
    inserir_fim(lista, 40);
    inserir_fim(lista, 50);
    imprimir_inicio_fim(lista);

    printf("-- Impressao fim para inicio --\n");
    imprimir_fim_inicio(lista);

    printf("-- Inserir valor 35 na posicao 3 --\n");
    inserir_posicao(lista, 35, 3);
    imprimir_inicio_fim(lista);

    printf("-- Buscar valor 35 --\n");
    Nodo *encontrado = buscar(lista, 35);
    if (encontrado) printf("Encontrado: %d\n", obter_valor(encontrado));
    else printf("Nao encontrado\n");

    printf("-- Buscar valor 99 --\n");
    encontrado = buscar(lista, 99);
    if (encontrado) printf("Encontrado: %d\n", obter_valor(encontrado));
    else printf("Nao encontrado\n");

    int removido;
    printf("-- Remover do inicio --\n");
    remover_inicio(lista, &removido);
    printf("Removido: %d\n", removido);
    imprimir_inicio_fim(lista);

    printf("-- Remover do fim --\n");
    remover_fim(lista, &removido);
    printf("Removido: %d\n", removido);
    imprimir_inicio_fim(lista);

    printf("-- Remover valor 35 --\n");
    remover_valor(lista, 35);
    imprimir_inicio_fim(lista);

    printf("Tamanho atual: %d\n", obter_tamanho(lista));

    destruir_lista(lista);

    printf("\n=== Testando Lista de Alunos ===\n\n");

    ListaAlunos *alunos = criar_lista_alunos();

    Aluno a1 = {1001, "Ana Silva", 8.5f};
    Aluno a2 = {1002, "Bruno Costa", 5.0f};
    Aluno a3 = {1003, "Carla Matos", 7.0f};
    Aluno a4 = {1004, "Diego Lima", 4.5f};
    Aluno a5 = {1005, "Eduarda Reis", 9.2f};

    inserir_aluno_fim(alunos, a1);
    inserir_aluno_fim(alunos, a2);
    inserir_aluno_fim(alunos, a3);
    inserir_aluno_inicio(alunos, a4);
    inserir_aluno_fim(alunos, a5);

    imprimir_aprovados(alunos);
    printf("\n");
    imprimir_reprovados(alunos);

    printf("\n-- Buscar matricula 1003 --\n");
    NodoAluno *na = buscar_por_matricula(alunos, 1003);
    if (na) printf("Encontrado: %s\n", na->dado.nome);

    printf("-- Remover matricula 1002 --\n");
    remover_por_matricula(alunos, 1002);
    imprimir_reprovados(alunos);

    destruir_lista_alunos(alunos);

    return 0;
}
