#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#define MAX 100

struct queue{
    int begin, end, size;
    struct student data[MAX];
};

int main()
{
    Queue *fi = init_queue();

    struct student aluno1;
    aluno1.registration = 123456;
    strcpy(aluno1.name, "Rodrigo");
    aluno1.n1 = 10.0;
    aluno1.n2 = 10.0;
    aluno1.n3 = 10.0;
    aluno1.n4 = 10.0;

    struct student aluno2;
    aluno2.registration = 123789;
    strcpy(aluno2.name, "Pedro");
    aluno2.n1 = 10.0;
    aluno2.n2 = 10.0;
    aluno2.n3 = 10.0;
    aluno2.n4 = 10.0;

    struct student aluno3;
    aluno3.registration = 123780;
    strcpy(aluno3.name, "Joao");
    aluno3.n1 = 10.0;
    aluno3.n2 = 10.0;
    aluno3.n3 = 10.0;
    aluno3.n4 = 10.0;

    struct student aux;

    printf("Tamanho da fila ao iniciar: %d\n", size_queue(fi));

    if(add_queue(fi, aluno1)){
        printf("Aluno adicionado com sucesso! Tamanho da fila: %d\n", size_queue(fi));
    }else{
        printf("Houve um problema ao adicionar o aluno na fila\n");
    }

    if(select_queue(fi, &aux)){
        printf("Aluno consultado com sucesso! Nome do aluno: %s\n", aux.name);
    }else{
        printf("Houve um problema ao consultar o aluno na fila\n");
    }

    if(remove_queue(fi)){
        printf("Aluno removido com sucesso! Tamanho da fila: %d\n", size_queue(fi));
    }else{
        printf("Houve um problema ao remover o aluno na fila\n");
    }
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

int add_queue(Queue* fi, struct student st)
{
    if(fi == NULL) return 0;

    if(full_queue(fi)) return 0;

    fi->data[fi->end] = st;
    fi->end = (fi->end+1)%MAX;
    fi->size++;

    return 1;
}

int remove_queue(Queue* fi)
{
    if(fi == NULL || empty_queue(fi)) return 0;

    fi->begin = (fi->begin+1)%MAX;
    fi->size--;

    return 1;
}

int select_queue(Queue* fi, struct student *st)
{
    if(fi == NULL || empty_queue(fi)) return 0;

    *st = fi->data[fi->begin];

    return 1;
}