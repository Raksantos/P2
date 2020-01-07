#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct element{
    struct student data;
    struct element* next;
};

struct queue{
    struct element *begin, *end; 
};

typedef struct element Element;

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

    if(enqueue(fi, aluno1)){
        printf("Aluno adicionado com sucesso! Tamanho da fila: %d\n", size_queue(fi));
    }else{
        printf("Houve um problema ao adicionar o aluno na fila\n");
    }

    if(select_queue(fi, &aux)){
        printf("Aluno consultado com sucesso! Nome do aluno: %s\n", aux.name);
    }else{
        printf("Houve um problema ao consultar o aluno na fila\n");
    }

    if(dequeue(fi)){
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
        fi->begin = NULL;
        fi->end = NULL;
    }

    return fi;
}

void free_queue(Queue* fi)
{
    if(fi != NULL){
        Element *no;
        while(fi->begin != NULL){
            no = fi->begin;
            fi->begin = fi->begin->next;
            free(no);
        }
        free(fi);
    }
}

int size_queue(Queue* fi)
{
    if(fi == NULL) return 0;

    int cont = 0;
    Element *no = fi->begin;
    while(no != NULL){
        cont++;
        no = no->next;
    }

    return cont;
}

int full_queue(Queue* fi)
{
    return 0;
}

int empty_queue(Queue* fi)
{
    if(fi == NULL || fi->begin == NULL) return 1;

    return 0;
}

int enqueue(Queue* fi, struct student st)
{
    if(fi == NULL || full_queue(fi)) return 0;

    Element* no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    no->data = st;
    no->next = NULL;
    
    if(fi->end == NULL) {
        fi->begin = no;
    }else{
        fi->end->next = no;
        fi->end = no;
    }
    return 1;
}

int dequeue(Queue* fi)
{
    if(fi == NULL || empty_queue(fi)) return 0;
    Element *no = fi->begin;
    fi->begin = fi->begin->next;

    if(fi->begin == NULL) fi->end = NULL; //fila ficou vazia

    free(no);
    return 1;
}

int select_queue(Queue* fi, struct student *aux)
{
    if(fi == NULL || empty_queue(fi)) return 0;

    *aux = fi->begin->data;
    return 1;
}