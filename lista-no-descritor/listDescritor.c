#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listDescritor.h"
#define debug if(1)

typedef struct element{
    struct student data;
    struct element *next;
} Element;

struct description{
    Element *begin;
    Element *end;
    int size;
};

int main()
{
    List *li = init_list();
    debug printf("Tamanho da lista ao iniciar: %d\n", size_list(li));
    free_list(li);
    return 0;
}

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));
    if(li != NULL){
        li->begin = NULL;
        li->end = NULL;
        li->size = 0;
    }
    return li;
}

void free_list(List* li)
{
    if(li != NULL){
        Element *no;
        while(li->begin != NULL){
            no = li->begin;
            li->begin = li->begin->next;
            free(no);
        }
        free(li);
    }
}

int size_list(List* li)//Essa função é desnecessária nesse cenário
{
    if(li == NULL) return 0;

    return li->size;
}

int add_list_beginning(List* li, struct student st)
{
    if(li == NULL) return 0;
    Element *no = (Element*) malloc(sizeof(List));

    if(no == NULL) return 0;
    no->data = st;
    no->next = li->begin;
    if(li->begin == NULL){
        li->end = no;
    }
    li->begin = no;
    li->size++;
    return 1;
}

int add_list_end(List* li, struct student st)
{
    if(li == NULL) return 0;
    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;
    no->data = st;
    no->next = NULL;
    if(li->begin == NULL){
        li->begin = no;
    }else{
        li->end->next = no;
    }
    li->end = no;
    li->size++;
    return 1;
}