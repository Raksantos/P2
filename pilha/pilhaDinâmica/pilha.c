#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct stack{
    struct student data[10];
    struct element *next;
};

typedef struct stack Element;

int main()
{
    Stack *pi = init_stack();

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
    Element *no;
    while(no->next != NULL){
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

    Element* no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    *no->data = st;
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

    aux = (*pi)->data;

    return 1;
}