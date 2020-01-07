#include <stdio.h>
#include <stdlib.h>

struct node{
    int item;
    int priority;
    struct node *next;
};

typedef struct node NODE;

struct priority_queue{
    NODE *head;
};

typedef struct priority_queue PQ;

PQ* init_queue();
int is_empty(PQ *pq);
void enqueue(PQ* pq, int i, int p);
NODE* dequeue(PQ* pq);
int maximum(PQ *pq);

void print(PQ *pq);

int main()
{
    PQ *pq = init_queue();

    enqueue(pq, 1, 1);
    enqueue(pq, 2, 1);
    enqueue(pq, 3, 1);
    enqueue(pq, 4, 2);
    enqueue(pq, 5, 3);

    print(pq);

    NODE *no = dequeue(pq);
    printf("Valor removido: %d\n", no->item);

    no = dequeue(pq);

    printf("Valor removido: %d\n", no->item);

    if(!is_empty(pq)) printf("Nao esta vazia");

    return 0;
}

PQ* init_queue()
{
    PQ* pq = (PQ*) malloc(sizeof(PQ));

    if(pq != NULL) pq == NULL;

    return pq;

}

int is_empty(PQ *pq)
{
    return pq->head == NULL ? 1 : 0;
}

void enqueue(PQ* pq, int i, int p)
{
    NODE *no= (NODE*) malloc(sizeof(NODE));

    no->item = i;
    no->priority = p;

    if(is_empty(pq) || (p > pq->head->priority)){
        no->next = pq->head;
        pq->head = no;
    }else{
        NODE *current = pq->head;
        while((current->next != NULL) && (current->next->priority > p)){
            current = current->next;
        }

        no->next = current->next;
        current->next = no;
    }
}

NODE* dequeue(PQ* pq)
{
    if(is_empty(pq)){
        return NULL;
    }else{
        NODE *no = pq->head;
        pq->head = pq->head->next;
        no->next = NULL;
        return no;
    }
}

int maximum(PQ *pq)
{
    return is_empty(pq) ? -1 : pq->head->item;
}

void print(PQ *pq)
{
    NODE *no = pq->head;

    while(no != NULL)
    {
        printf("%d\n", no->item);
        no = no->next;
    }
}