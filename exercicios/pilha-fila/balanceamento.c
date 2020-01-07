#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    char caractere;
    struct element *next;
};

typedef struct element Element;

typedef struct element *Stack;

Stack *init_stack();

void free_stack(Stack *pi);

int size_stack(Stack *pi);

int full_stack(Stack *pi);

int empty_stack(Stack *pi);

int push(Stack *pi, char caractere);

char pop(Stack *pi);

int top(Stack *pi, char *aux);

void verifica();

int contador(Stack *p);

int main()
{
    int strings;

    scanf("%d", &strings);
    getchar();
    while (strings > 0)
    {

        verifica();

        strings--;
    }
    return 0;
}

void verifica()
{
    fflush(stdin);
    char entrada[255];
    fgets(entrada, 255, stdin);

    int i;

    Stack *p = init_stack();

    for (i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] != ' ' && entrada[i] != '\n')
        {
            push(p, entrada[i]);
        }
    }

    if (contador(p))
        printf("Yes\n");

    else
        printf("No\n");
}

int contador(Stack *p)
{
    int contParenteses = 0, contColchetes = 0;
    char parenteses[255];
    char colchetes[255];

    while (size_stack(p) > 0)
    {
        char aux = pop(p);

        if (aux == '(')
        {
            parenteses[contParenteses] = '(';
            contParenteses++;
        }

        else if (aux == ')')
        {
            parenteses[contParenteses] = ')';
            contParenteses++;
        }

        else if (aux == '[')
        {
            colchetes[contColchetes] = '[';
            contColchetes++;
        }

        else if (aux == ']')
        {
            colchetes[contColchetes] = ']';
            contColchetes++;
        }
    }

    parenteses[contParenteses] = '\0';
    colchetes[contColchetes] = '\0';

    int i;

    int auxParen = 0, auxCo = 0;

    for(i = 0; i < contParenteses; i++){
        if(parenteses[i] == ')') auxParen++;

        else if(parenteses[i] == '(') auxParen--;

        if(auxParen < 0) return 0;
    }

    for(i = 0; i < contColchetes; i++){
        if(colchetes[i] == ']') auxCo++;

        else if(colchetes[i] == '[') auxCo--;

        if(auxCo < 0) return 0;
    }

    if(auxCo == 0 && auxParen == 0) return 1;

    else return 0;
}

Stack *init_stack()
{
    Stack *pi = (Stack *)malloc(sizeof(Stack));

    if (pi != NULL)
    {
        *pi = NULL;
    }

    return pi;
}

void free_stack(Stack *pi)
{
    if (pi != NULL)
    {
        Element *no;
        while (*pi != NULL)
        {
            no = *pi;
            *pi = (*pi)->next;
            free(no);
        }

        free(pi);
    }
}

int size_stack(Stack *pi)
{
    if (pi == NULL)
        return 0;
    int cont = 0;
    Element *no = *pi;
    while (no != NULL)
    {
        no = no->next;
        cont++;
    }

    return cont;
}

int full_stack(Stack *pi)
{
    return 0;
}

int empty_stack(Stack *pi)
{
    if (pi == NULL)
        return 1;

    return (*pi)->next == NULL ? 1 : 0;
}

int push(Stack *pi, char caractere)
{
    if (pi == NULL)
        return 0;
    Element *no = (Element *)malloc(sizeof(Element));

    if (no == NULL)
        return 0;

    no->caractere = caractere;
    no->next = (*pi);

    *pi = no;
    return 1;
}

char pop(Stack *pi)
{
    if (pi == NULL || (*pi) == NULL)
        return 0;

    Element *no = *pi;

    *pi = no->next;

    char aux = no->caractere;

    free(no);

    return aux;
}

int top(Stack *pi, char *aux)
{
    if (pi == NULL || (*pi) == NULL)
        return 0;

    *aux = (*pi)->caractere;

    return 1;
}