#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    debug printf("Tamanho da lista ao iniciar: %d.\n", sizeof_list(li));

    if(empyt_list(li)){
        debug printf("A lista está vazia!\n");
    }
    else{
        debug printf("A lista não está vazia!\n");
    }

    struct student aluno1;
    aluno1.registration = 123456;
    strcpy(aluno1.name, "Rodrigo");
    aluno1.n1 = 10.0;
    aluno1.n2 = 10.0;
    aluno1.n3 = 10.0;
    aluno1.n4 = 10.0;
    if(add_beginning(li, aluno1)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao adicionar o aluno.\n");
    }

    struct student aluno2;
    aluno2.registration = 123789;
    strcpy(aluno2.name, "Pedro");
    aluno2.n1 = 10.0;
    aluno2.n2 = 10.0;
    aluno2.n3 = 10.0;
    aluno2.n4 = 10.0;

    if(add_end(li, aluno2)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao adicionar o aluno.\n");
    }

    struct student aluno3;
    aluno3.registration = 123780;
    strcpy(aluno3.name, "Joao");
    aluno3.n1 = 10.0;
    aluno3.n2 = 10.0;
    aluno3.n3 = 10.0;
    aluno3.n4 = 10.0;

    if(add_end(li, aluno3)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao adicionar o aluno.\n");
    }

    if(remove_middle(li, 123789)){
        debug printf("Aluno removido com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao remover o aluno.\n");
    }

    if(remove_beginning(li)){
        debug printf("Aluno removido com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao remover o aluno.\n");
    }
    if(remove_end(li)){
        debug printf("Aluno removido com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao remover o aluno.\n");
    }

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

int sizeof_list(List* li)
{
    if(li == NULL) return 0;//se a lista não existir, retorna 0.
    int count = 0;//contador para verificar o tamanho da lista
    Element *no = *li;//elemento auxiliar que recebe a lista

    while(no != NULL){//enquanto não chegar no final da lista
        count++;//adiciona mais um ao contador
        no = no->next;//elemento auxiliar passa para o próximo
    }

    return count;
}

int empyt_list(List *li)
{
    if (li == NULL) return 1;//se ela não existir, retorna vazia

    if (*li == NULL) return 1;//se ela existir, mas estiver vazia retorna verdadeiro

    return 0;//se não, retorna que não está vazia
}

int add_beginning(List *li, struct student st)
{
    if(li == NULL) return 0;//se a lista não existir, retorne 0

    Element *no = (Element*) malloc(sizeof(Element));//aloca memória para o novo elemento

    if(no == NULL) return 0;//se houver problema na alocação, retorna 0

    no->data = st;//passa os dados do aluno para a lista
    no->next = (*li);//novo nó aponta para a antiga cabeça da lista
    no->previous = NULL;//ponteiro anterior aponta para null, já que é a nova cabeça da lista

    if(*li != NULL){//se a lista não estiver vazia
        (*li)->previous = no;//ponteiro anterior da antiga cabeça aponta para a nova cabeça
    }

    *li = no;//aponta o ponteiro para ponteiro para a nova cabeça

    return 1;//retorna sucesso
}

int add_end(List* li, struct student st)
{
    if(li == NULL) return 0;//se a lista não existir, retorna 0

    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;//se houver algum problema na hora de iniciar o novo elemento, retorna 0

    no->data = st;//passa os dados do novo estudante para o nó
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

int add_middle(List* li, struct student st)
{
    if (li == NULL) return 0;//se a lista não existir, retorna 0

    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;//se houver problema em alocar memória para o nó, retorna 0 (erro)

    no->data = st;//passa os dados do novo aluno para o nó

    if(empyt_list(li)){//se a lista estiver vazia, adiciona no inícios
        no->next = NULL;//ponteiro próximo aponta para vazio
        no->previous = NULL;//anterior aponta para vazio
        *li = no;//ponteiro para ponteiro aponta para o novo nó que é a cabeça da lista
        return 1;//retorna sucesso
    }  
    else{
        Element *previous, *current = *li;//cria elementos auxiliares anterior e atual
        while(current != NULL && current->data.registration < st.registration){//enquanto não chegar no final da lista ou achar um elemento com número de matrícula menor
            previous = current;//anterior passa a ser o atual
            current = current->next;//atual vai para o próximo
        }
        if(current == *li){//insere no início
            no->previous = NULL;//ponteiro anterior aponta para null
            (*li)->previous = no;//antiga cabeça aponta para a nova cabeça
            no->next = (*li);//nova cabeça aponta para a antiga cabeça
            *li = no;//ponteiro para ponteiro aponta para a nova cabeça
        }
        else{
            no->next = previous->next;//ponteiro proximo do novo nó aponta para o que o anterior estava apontando
            no->previous = previous;//ponteiro anterior do novo nó aponta para o anterior
            previous->next = no;//ponterior próximo do anterior aponta para o novo nó
            if(current != NULL){//se o nó atual não estiver vazio
                current->next = no;//ponteiro próximo aponta para o novo nó
            }
        }
    }
    return 1;//retorna sucesso
}

int remove_beginning(List *li)
{
    if(li == NULL || empyt_list(li)) return 0;//se a lista não existir ou estiver vazia, retorna 0

    Element *no = *li;//elemento auxiliar
    *li = no->next;//cabeça da lista irá apontar para o próximo elemento
    if(no->next != NULL){//se houver um único elemento na lista
        no->next->previous = NULL;//lista fica vazia
    }
    free(no);//libera o nó
    return 1;
}

int remove_end(List* li)
{
    if(li == NULL || empyt_list(li)) return 0;//se a lista não existir ou estiver vazia, retorne 0
    Element *no = *li;//cria elemento auxiliar
    while(no != NULL){//enquanto não chegar no final da lista
        no = no->next;//passa para o próximo elemento
    }

    if(no->previous != NULL){
        *li = no->next;
    }
    else{
        no->previous->next = NULL;
    }

    free(no);
    return 1;
}

int remove_middle(List* li, int registration)
{
    if(li == NULL) return 0;//se a lista não existir
    
    Element *no = *li;//cria novo elemento auxiliar
    while(no != NULL && no->data.registration != registration){//enquanto não chegar no final da lista e a matrícula informada for diferente da na lista 
        no = no->next;//pecorre a lista
    }
    if(no == NULL) return 0;//nó não econtrado
    
    if(no->previous == NULL){
        *li = no->next;//se for o primeiro item o ponteiro para ponteiro apontará para null, esvaziando assim a lista
    }

    else{//se não for o primeiro item, faz a remoção no meio
        no->previous->next = no->next;
    }
    if(no->next != NULL){
        no->next->previous = no->previous;
    }
    free(no);
    return 1;
}