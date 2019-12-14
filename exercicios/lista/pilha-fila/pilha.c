#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct element{
    struct student data;
    struct element *next;
};

typedef struct element Element;

int main()
{
    Stack *pi = init_stack();
    printf("Tamanho atual da pilha: %d\n", size_stack(pi));

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

    if(push(pi, aluno1)){
        printf("Aluno adicionado com sucesso, tamanho atual da pilha: %d\n", size_stack(pi));
    }else{
        printf("Ocorreu um erro ao adicionar o aluno na pilha.\n");
    }

    if(top(pi, &aux)){
        printf("Aluno encontrado com sucesso. Nome do aluno: %s\n", aux.name);
    }else{
        printf("Houve um problema ao realizar a consulta do aluno na pilha.\n");
    }

    if(pop(pi)){
        printf("Aluno removido com sucesso da pilha. Tamanho da pilha: %d\n", size_stack(pi));
    }else{
        printf("Houve um problema ao remover o aluno da pilha.\n");
    }

    free_stack(pi);
    return 0;
}

Stack* init_stack()
{
    Stack *pi = (Stack*) malloc(sizeof(Stack));

    if(pi != NULL){
        *pi = NULL;
    }

    return pi;
}

void free_stack(Stack* pi)
{
    if(pi != NULL){
        Element *no;
        while(*pi != NULL){
            no = *pi;
            *pi = (*pi)->next;
            free(no);
        }

        free(pi);
    }
}

int size_stack(Stack* pi)
{
    if(pi == NULL) return 0;
    int cont = 0;
    Element *no = *pi;
    while(no != NULL){
        no = no->next;
        cont++;
    }

    return cont;
}

int full_stack(Stack* pi)
{
    return 0;
}

int empty_stack(Stack* pi)
{
    if(pi == NULL) return 1;

    return (*pi)->next == NULL ? 1 : 0;
}

int push(Stack* pi, struct student st)
{
    if(pi == NULL) return 0;
    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    no->data = st;
    no->next = (*pi);

    *pi = no;
    return 1;
}

int pop(Stack* pi)
{
    if(pi == NULL || (*pi) == NULL) return 0;

    Element *no = *pi;

    *pi = no->next;

    free(no);

    return 1;
}

int top(Stack* pi, struct student *aux)
{
    if(pi == NULL || (*pi) == NULL) return 0;

    *aux = (*pi)->data;

    return 1;
}