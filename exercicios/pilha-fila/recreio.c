#include <stdio.h>
#include <stdlib.h>

struct node{
    int nota;
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
void normal_enqueue(PQ *pq, int nota);
void print(PQ *pq);
int trocas(PQ* pq, PQ* pq2);

int main()
{
    int n, m;
    scanf("%d", &n);

    while(n > 0){

        PQ *pq = init_queue();
        PQ *pq2 = init_queue();
        scanf("%d",&m);

        while(m > 0){
            
            int nota;

            scanf("%d", &nota);
            
            normal_enqueue(pq2, nota);
            enqueue(pq, nota, nota);
            m--;    
        }

        printf("%d\n", trocas(pq, pq2));

        n--;
    }
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

void enqueue(PQ* pq, int nota, int p)
{
    NODE *no= (NODE*) malloc(sizeof(NODE));

    no->nota = nota;
    no->priority = p;

    if(is_empty(pq) || (p > pq->head->priority)){
        no->next = pq->head;
        pq->head = no;
    }
    else{
        NODE *current = pq->head;
        while((current->next != NULL) && (current->next->priority > p)){
            current = current->next;
        }

        no->next = current->next;
        current->next = no;
    }
}

void normal_enqueue(PQ *pq, int nota)
{
    NODE *no= (NODE*) malloc(sizeof(NODE));

    no->nota = nota;
    no->priority = 0;

    if(is_empty(pq)){
        no->next = pq->head;
        pq->head = no;
    }else{
        NODE *current = pq->head;

        while(current->next != NULL){
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
    return is_empty(pq) ? -1 : pq->head->nota;
}

void print(PQ *pq)
{
    NODE *no = pq->head;

    while(no != NULL)
    {
        printf("%d\n", no->nota);
        no = no->next;
    }
}

int trocas(PQ* pq, PQ* pq2)
{
    int i;

    int trocas = 0;
    
    NODE *no = pq->head;
    NODE *no2 = pq2->head;

    while(no != NULL && no2 != NULL){
        if(no->nota == no2->nota) trocas++;

        no = no->next;
        no2 = no2->next;

    }

    return trocas;
}