#include <stdio.h>
#include <stdlib.h>
#include "listDupl.h"
#define debug if(1)

struct element {
    struct student data;
    struct element *previous;
    struct element *next;
};

typedef struct element Element;

int main(){
    List *li = init_list();
    free_list(li);
    return 0;
}

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));
    if(li != NULL) *li = NULL;//se a lista for iniciada com algo, esvazia ela
    debug printf("Lista iniciada com sucesso!\n");
    return li;
}

void free_list(List* li)
{
    if(li != NULL){//se a lista não existir, não tem o que fazer
        Element *no;//no auxiliar
        while((*li) != NULL){//enquanto o conteudo da lista não estiver vazio, temos elementos na lista
            no = *li;//no recebe o conteudo
            *li = (*li)->next;//cabeça da lista vai para o próximo elemento
            free(no);//libera o nó atual
        }
        free(li);//libera a lista alocada
    }
}