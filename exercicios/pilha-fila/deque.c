#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
  	node_t *next;
  	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que são enfileirados no deque
node_t*  node_new     (int value);

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct    ();
//Libera a memória do conteúdo e do próprio deque
void     destruct     (deque_t *deque);

//Retorna o tamanho do deque
int      size         (deque_t *deque);
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool     empty        (deque_t *deque);

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque);
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque);

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value);
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value);
//Retira o valor do final caso não esteja vazia
void     dequeue_rear (deque_t *deque);
//Retira o valor da frente caso não esteja vazia
void     dequeue_front(deque_t *deque);
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque);

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque);

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();

  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
    
    //printf("Passou daqui\n");

 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    
  	erase(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  	
  	print(deque);
    destruct(deque);

	return 0;
}






deque_t* construct    ()
{
    deque_t* deque = (deque_t*) malloc(sizeof(deque_t));

    if(deque != NULL){
        deque->front = NULL;
        deque->rear = NULL;
        deque->size = 0;
    }

    return deque;
}

void     destruct     (deque_t *deque)
{
    if(!empty(deque)){
        node_t *no;
        while(deque->front != deque->rear){
            no = deque->front;
            deque->front = deque->front->next;
            deque->front->prev = NULL;
            no->next = NULL;

            free(no);
        }

        deque->front = NULL;
        deque->rear = NULL;
        
        free(deque);
    }
}

node_t*  node_new     (int value)
{
    node_t *node = (node_t*) malloc(sizeof(node_t));

    if(node != NULL)
    {
        node->next = NULL;
        node->prev = NULL;
    }

    node->value = value;

    return node;
}

int      size         (deque_t *deque)
{
    return deque->size;
}

bool     empty        (deque_t *deque)
{
    return deque->size == 0 ? true : false;
}

int      front        (deque_t *deque)
{
    if(empty(deque)) return INT_MIN;

    return deque->front->value;
}

int      rear         (deque_t *deque)
{
    if(empty(deque)) return INT_MIN;

    return deque->rear->value;
}

void     print        (deque_t *deque)
{
    if(!empty(deque)){
        node_t *node = deque->front;
        printf("%d", node->value);

        node = node->next;

        while(node != NULL){
            printf("% d", node->value);
            node = node->next;
        }
        printf("\n");
    }else{
        printf("The deque is empty\n");
    }
}

void     enqueue_rear (deque_t *deque, int value)
{

    node_t *node = node_new(value);

    if(empty(deque) == true){
        //printf("Entrou aqui\n");
        deque->front = node;
        deque->rear = node;
    }else{
        deque->rear->next = node;
        node->prev = deque->rear;
        deque->rear = node;
    }

    //printf("Passou daqui\n");

    deque->size++;
    return;
}

void     enqueue_front(deque_t *deque, int value)
{
    node_t *node = node_new(value);

    if(empty(deque)){
        deque->front = node;
        deque->rear = node;
    }else{
        deque->front->prev = node;
        node->next = deque->front;
        deque->front = node;
    }

    deque->size++;
    return;
}

void     dequeue_rear (deque_t *deque)
{
    node_t *no = deque->rear;

    deque->rear = no->prev;
    deque->rear->next = NULL;

    deque->size--;

    free(no);
}

void     dequeue_front (deque_t *deque)
{
    node_t *no = deque->front;

    deque->front = no->next;
    deque->front->prev = NULL;

    deque->size--;

    free(no);
}

void     erase        (deque_t *deque)
{
    if(!empty(deque)){
        node_t *no;
        while(deque->front != NULL){
            no = deque->front;
            deque->front = deque->front->next;
            free(no);
        }

        free(deque);
    }

    deque->size = 0;
}

