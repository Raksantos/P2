#include <stdio.h>
#include <stdlib.h>
#include "listCircular.h"
#define debug if(1)

int main()
{
    List *li = init_list();
    if(empty_list(li)){
        debug printf("A lista está vazia!\n");
    }else{
        debug printf("A lista não está vazia!\n");
    }

    printf("Tamanho atual da lista: %d\n", size_list(li));
    free(li);
    return 0;
}

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void free_list(List* li)
{
    if(li != NULL && (*li) != NULL){
        Element *aux, *no = *li;
        while((*li) != no->next){
            aux = no;
            no = no->next;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int size_list(List* li)
{
    if(li == NULL || (*li) == NULL) return 0;
    int count = 0;
    Element *no = *li;

    while(no != (*li)){
        count++;
        no = no->next;
    }
    return count;
}

int empty_list(List* li)
{
    if(li == NULL && (*li) == NULL){
        return 1;
    }else{
        return 0;
    }
}