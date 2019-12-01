#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define MAX 100

struct queue{
    int begin, end, size;
    struct student data[MAX];
};

int main()
{
    Queue *fi = init_queue();

    free_queue(fi);
    return 0;
}

Queue* init_queue()
{
    Queue *fi = (Queue*) malloc(sizeof(Queue));
    if(fi != NULL){
        fi->begin = 0;
        fi->end = 0;
        fi->size = 0;
    }
    
    return fi;
}

void free_queue(Queue* fi)
{
    free(fi);
}

int size_queue(Queue* fi)
{
    if(fi == NULL) return -1;//retorna -1 porque se ela for nula, significa que houve problema na criação da lista e, por isso, é uma lista inválida
     
    return fi->size;
}

int full_queue(Queue* fi)
{
    if(fi == NULL) return -1;//retorna -1 porque se ela for nula, significa que houve problema na criação da lista e, por isso, é uma lista inválida

    return fi->size == MAX ? 1 : 0;
}

int empty_queue(Queue* fi)
{
    if(fi == NULL) return -1;

    return fi->size == 0 ? 1 : 0;
}