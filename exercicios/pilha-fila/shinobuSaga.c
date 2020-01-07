#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE *head;
};
struct _node
{
    int element;
    NODE *next;
};

//Cria uma stack com o a head NULL
STACK *Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE *create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK *stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK *stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK *stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK *stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK *calculadora, int size);

int main()
{
    STACK *calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));
}

STACK *Create_stack()
{
    STACK *pi = (STACK *)malloc(sizeof(STACK));

    if (pi != NULL)
    {
        pi->head = NULL;
    }

    return pi;
}

NODE *create_node(int element)
{
    NODE *no = (NODE *)malloc(sizeof(NODE));

    no->element = element;

    return no;
}

void PUSH(STACK *stack, int element)
{
    if (stack == NULL) return;
    NODE *no = create_node(element);

    if (no == NULL)
        return;

    no->next = stack->head;
    stack->head = no;
}

int POP(STACK *pi)
{
    if (pi == NULL || IS_EMPTY(pi)) return 0;

    NODE *aux = pi->head;

    pi->head = aux->next;

    int aux2 = aux->element;

    free(aux);

    return aux2;
}

int IS_EMPTY(STACK *stack)
{
    return stack->head == NULL ? 1 : 0;
}

void Calculadora(STACK* calculadora, int size)
{
    int i;
    char entrada[5];

    for(i = 0; i < size; i++)
    {
        fflush(stdin);
        scanf("%s", entrada);

        if ((entrada[0] == '+') || (entrada[0] == '-') || (entrada[0] == '*') || (entrada[0] == '/'))
        {
            result(calculadora, entrada[0]);
        }
        else{
            PUSH(calculadora, atoi(entrada));
        }
    }
}

void result(STACK *stack, char operation)
{
    if(IS_EMPTY(stack)) return;
    int n1, n2;
    n1 = POP(stack);
    n2 = POP(stack);

    if(operation == '+'){
        PUSH(stack, n1 + n2);
    }
    else if(operation == '*'){
        PUSH(stack, n1 * n2);
    }
    else if(operation == '-'){
        PUSH(stack, n2 - n1);
    }
    else if(operation == '/'){
        PUSH(stack, n2 / n1);
    }
}
