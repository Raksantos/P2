#include <stdio.h>
#include <stdlib.h>

struct element{
    int num;
    struct element *previous;
    struct element *next;
};

typedef struct element Element;

typedef struct element* List;

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));
    if(li != NULL) *li = NULL;//se a lista for iniciada com algo, esvazia ela
    return li;
}

int add_end(List* li, int num)
{
    if(li == NULL) return 0;//se a lista não existir, retorna 0

    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;//se houver algum problema na hora de iniciar o novo elemento, retorna 0

    no->num = num;//passa os dados do novo estudante para o nó
    no->next = NULL;//novo nó apontara para null, já que está no final
    if((*li) == NULL){//se a lista estiver vazia, insere no início
        no->previous = NULL;//o no apontará para null, pois é o final
        *li = no;//ponteiro para ponteiro aponta para o novo nó
    }
    else{
        Element *aux = *li;//cria elemento auxiliar para pecorrer a lista
        while(aux->next != NULL){//enquanto não estiver no final da lista
            aux = aux->next;//elemento atual passa para o próximo
        }
        aux->next = no;//ao chegar no final, o antigo último elemento aponta para o novo
        no->previous = aux;//ponteiro anterior aponta para o antigo último elemento
    }

    return 1;//retorna sucesso
}

int main()
{
    List *li = init_list();

    int aux;

    while(scanf("%d", &aux) != EOF){
        add_end(li, aux);
    }

    Element *no = *li;

    Element *aux1 = no->previous;
    Element *aux2 = no;

    while(aux2 != NULL){
        aux2->previous = aux2->next;
        aux2->next = aux1;
        aux1 = aux2;
        aux2 = aux2->previous;
    }

    *li = aux1;

    no = *li;
    while(no != NULL){
        printf("%d ", no->num);
        no = no->next;
    }

    return 0;
}