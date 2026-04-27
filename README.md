# Lista Duplamente Encadeada em C

Implementação de uma lista duplamente encadeada em linguagem C, organizada como Tipo Abstrato de Dados (TAD).

## Estrutura do projeto

```
lista_dupla/
├── nodo.h / nodo.c       # TAD Nodo duplo
├── lista.h / lista.c     # TAD Lista duplamente encadeada
├── aluno.h / aluno.c     # Desafio extra: lista de alunos
└── main.c                # Testes das operações
```

## Como compilar e executar

```bash
gcc -Wall -Wextra -o lista_dupla main.c nodo.c lista.c aluno.c
./lista_dupla
```

## Funcionalidades implementadas

### TAD Nodo
- Criação e destruição de nodo
- Getters e setters para valor, anterior e próximo

### TAD Lista
- Inserção no início, no fim e em posição específica
- Remoção do início, do fim e por valor
- Busca por valor
- Impressão do início para o fim e do fim para o início

### Desafio extra — Lista de Alunos
- Inserção no início e no fim
- Busca por matrícula
- Remoção por matrícula
- Impressão de aprovados (média ≥ 7.0) e reprovados (média < 7.0)

## Requisitos

- GCC

Em sistemas Debian/Ubuntu:

```bash
sudo apt install gcc
```
