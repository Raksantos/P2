#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct queue_prio{
    int qtd;
    struct pacient data[MAX];
};

QueuePrio* init_queue()
{
    QueuePrio *fi = (QueuePrio*) malloc(sizeof(QueuePrio));
    if(fi != NULL){
        fi->qtd = 0;
    }
    
    return fi;
}

void free_queue(QueuePrio* fi)
{
    free(fi);
}

int size_queue(QueuePrio* fi)
{
    return fi->qtd;
}

int full_queue(QueuePrio* fi)
{
    if(fi == NULL) return -1;//retorna -1 porque se ela for nula, significa que houve problema na criação da lista e, por isso, é uma lista inválida

    return fi->qtd == MAX ? 1 : 0;
}

int empty_queue(QueuePrio* fi)
{
    if(fi == NULL) return -1;

    return fi->qtd == 0 ? 1 : 0;
}

int enqueue(QueuePrio* fi, char *name, int prio)
{
    if(fi == NULL) return 0;
    if(full_queue(fi)) return 0;

    int i = fi->qtd - 1;
    while(i >= 0 && fi->data[i].prio >= prio){
        fi->data[i+1] = fi->data[i];
        i--;
    }

    strcpy(fi->data[i + 1].name, name);
    fi->data[i+1].prio = prio;
    fi->qtd++;
    return 1;
}

int dequeue(QueuePrio* fi)
{
    if(fi == NULL || fi->qtd == 0) return 0;

    fi->qtd--;
    return 1;
}

int select_queue(QueuePrio* fi, char *name)
{
    if(fi == NULL || fi->qtd == 0) return 0;

    strcpy(name, fi->data[fi->qtd-1].name);

    return 1;
}