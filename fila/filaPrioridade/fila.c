#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct queue_prio{
    int qtd;
    struct pacient data[MAX];
};

int main()
{
    QueuePrio *fp = init_queue();
    printf("Tamanho da fila de prioridade: %d\n", size_queue(fp));
    if(enqueue(fp, "Rodrigo", 10)){
        printf("Paciente adicionado com sucesso! Novo tamanho da fila: %d\n", size_queue(fp));
    }else{
        printf("Ocorreu um erro ao adicionar o paciente!\n");
    }

    if(enqueue(fp, "Pedro", 9)){
        printf("Paciente adicionado com sucesso! Novo tamanho da fila: %d\n", size_queue(fp));
    }else{
        printf("Ocorreu um erro ao adicionar o paciente!\n");
    }
    char nome[30];
    select_queue(fp, nome);

    printf("Paciente na cabeça da fila: %s\n", nome);

    dequeue(fp);

    select_queue(fp, nome);

    printf("Novo paciente na cabeça da fila: %s\n", nome);

    return 0;
}

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