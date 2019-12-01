#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define MAX 5

struct stack{
    struct student data[MAX];
    int size;
};

int main()
{
    Stack *pi = init_stack();
    struct student aluno1;
    aluno1.registration = 123456;
    strcpy(aluno1.name, "Rodrigo");
    aluno1.n1 = 10.0;
    aluno1.n2 = 10.0;
    aluno1.n3 = 10.0;
    aluno1.n4 = 10.0;

    struct student aluno2;
    aluno2.registration = 123789;
    strcpy(aluno2.name, "Pedro");
    aluno2.n1 = 10.0;
    aluno2.n2 = 10.0;
    aluno2.n3 = 10.0;
    aluno2.n4 = 10.0;

    struct student aluno3;
    aluno3.registration = 123780;
    strcpy(aluno3.name, "Joao");
    aluno3.n1 = 10.0;
    aluno3.n2 = 10.0;
    aluno3.n3 = 10.0;
    aluno3.n4 = 10.0;

    struct student aux;
    printf("Tamanho da fila ao inicia: %d\n", size_stack(pi));

    if(push(pi, aluno1)){
        printf("Estudante adicionado com sucesso!\n");
    }else{
        printf("Houve um problema ao adicionar o estudante!\n");
    }

    if(top(pi, &aux)){
        printf("A consulta ocorreu bem. Nome do estudante: %s\n", aux.name);
    }else{
        printf("Houve um problema em consultar o elemento no topo da pilha\n");
    }

    printf("Tamanho atual da fila: %d\n", size_stack(pi));

    if(pop(pi)){
        printf("Elemento removido com sucesso!\n");
    }else{ 
        printf("Houve um problema ao remover o elemento da lista\n");
    }

    free(pi);
    return 0;
}

Stack* init_stack()
{
    Stack *pi = (Stack*) malloc(sizeof(Stack));

    if(pi != NULL){
        pi->size = 0;
    }

    return pi;
}

void free_stack(Stack* pi)
{
    free(pi);
}

int size_stack(Stack* pi)
{
    return pi == NULL ? -1 : pi->size;
}

int full_stack(Stack* pi)
{
    if(pi == NULL) return -1;

    return pi->size == MAX ? 1 : 0;
}

int empty_stack(Stack* pi)
{
    if(pi == NULL) return -1;

    return pi->size == 0 ? 1 : 0;
}

int push(Stack* pi, struct student st)
{
    if(pi == NULL || full_stack(pi)) return 0;

    pi->data[pi->size] = st;
    pi->size++;

    return 1;
}

int pop(Stack* pi)
{
    if(pi == NULL || empty_stack(pi)) return 0;

    pi->size--;
    return 1;
}

int top(Stack* pi, struct student *st)
{
    if(pi == NULL || empty_stack(pi)) return 0;

    *st = pi->data[pi->size - 1];

    return 1;
}

