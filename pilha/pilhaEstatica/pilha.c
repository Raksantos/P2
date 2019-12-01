#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define MAX 5

struct stack{
    struct student data[MAX];
    int size;
};

int main()
{
    Stack *pi = init_stack();

    free(pi);
    return 0;
}

Stack* init_stack()
{
    Stack *pi = (Stack*) maloc(sizeof(Stack));

    if(pi != NULL){
        pi = NULL;
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