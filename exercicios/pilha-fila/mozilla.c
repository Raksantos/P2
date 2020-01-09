#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    int size;
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

void verifica(STACK *front, STACK *back, char *entrada)
{

    int i, contador;

    for(i = 0; i < strlen(entrada); i++)
    {
        if(entrada[i] == '\n'){
            for(contador = i; contador < strlen(entrada); contador++){
                entrada[contador] = entrada[contador + 1];
            }
        }
    }

    if((strcmp(entrada, "ENTER") == 0)){
        PUSH(back, 1);
        back->size++;
        if(front->size > 0){
            POP(front);
            front->size--;
        }
    }
    else if(strcmp(entrada, "BACK") == 0){
        PUSH(front, 1);
        front->size++;
        if(back->size >= -1){
            POP(back);
            back->size--;
        }
    }else if(strcmp(entrada, "FORWARD") == 0){
        PUSH(back, 1);
        back->size++;
        if(front->size > 0){
            POP(front);
            front->size--;
        }
    }
}

int main()
{
    STACK *front = Create_stack();
    STACK *back = Create_stack();

    front->size = 0;
    back->size = -1;

    fflush(stdin);
    char entrada[255];

    while(fgets(entrada, 255, stdin) != NULL){

        verifica(front, back, entrada);

        fflush(stdin);
    }

    if(back->size < 0){
        printf("BACK: 0\n");    
    }else{
        printf("BACK: %d\n", back->size);   
    }
    
    printf("FOWARD: %d\n", front->size);

    return 0;
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