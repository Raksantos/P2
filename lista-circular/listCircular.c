#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    debug printf("Tamanho atual da lista: %d\n", size_list(li));

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

    if(add_beginning(li, aluno1)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", size_list(li));
    }else{
        debug printf("Houve um problema em inserir o aluno no inicio\n");
    }

    if(add_end(li, aluno2)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", size_list(li));
    }else{
        debug printf("Houve um problema em inserir o aluno no final\n");
    }

    if(add_ordered(li, aluno3)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", size_list(li));
    }else{
        debug printf("Houve um problema em inserir o aluno no meio\n");
    }

    struct student st_i_want;
    if(select_list_position(li, 2, &st_i_want)){
        debug printf("Aluno encontrado!\nNome: %s\nMatricula: %d\n", st_i_want.name, st_i_want.registration);
    }
    else{
        debug printf("Aluno não encontrado.\n");
    }

    if(select_list_registration(li, 123780, &st_i_want)){
        debug printf("Aluno encontrado!\nNome: %s\nMatricula: %d\n", st_i_want.name, st_i_want.registration);
    }
    else{
        debug printf("Aluno não foi encontrado.\n");
    }
    
    // if(remove_middle(li, 123789)){
    //     debug printf("Aluno removido com sucesso!\n");
    //     debug printf("Tamanho atual da lista: %d\n", size_list(li));
    // }
    // else{
    //     printf("Ocorreu um erro ao remover o aluno.\n");
    // }

    // if(remove_end(li)){
    //     debug printf("Aluno removido com sucesso!\n");
    //     debug printf("Tamanho atual da lista: %d\n", size_list(li));
    // }
    // else{
    //     printf("Ocorreu um erro ao remover o aluno.\n");
    // }

    // if(remove_beginning(li)){
    //     debug printf("Aluno removido com sucesso!\n");
    //     debug printf("Tamanho atual da lista: %d\n", size_list(li));
    // }
    // else{
    //     printf("Ocorreu um erro ao remover o aluno.\n");
    // }

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

    do{
        count++;
        no = no->next;
    }while(no != (*li));
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

int add_beginning(List* li, struct student st)
{
    if(li == NULL) return 0;
    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    no->data = st;

    if((*li) == NULL){
        *li = no;
        no->next = no;
    }else{
        Element *aux = *li;
        while(aux->next != (*li)){
            aux = aux->next;
        }
        aux->next = no;
        no->next = *li;
        *li = no;
    }
    return 1;
}

int add_end(List* li, struct student st)
{
    if(li == NULL) return 0;

    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    no->data = st;

    if((*li) == NULL){
        *li = no;
        no->next = no;
    }else{
        Element *aux = *li;
        while(aux->next != (*li)){
            aux = aux->next;
        }
        aux->next = no;
        no->next = *li;
        *li = no;
    }
    return 1;
}

int add_ordered(List* li, struct student st)
{
    if(li == NULL) return 0;

    Element *no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    no->data = st;

    if((*li) == NULL){
        *li = no;
        no->next = no;
    }else{
        if((*li)->data.registration > st.registration){
            Element *aux = *li;
            while (aux->next != (*li))
            {
                aux = aux->next;
                no->next = *li;
                aux->next = no;
                *li = no;
                return 1;
            }
            Element *previous = *li, *current = (*li)->next;
            while(current != (*li) && current->data.registration < st.registration){
                previous = current;
                current = current->next;
            }

            previous->next = no;
            no->next = current;
        }
    }
    return 1;
}


int remove_beginning(List* li)
{
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    if((*li) == (*li)->next){
        free(*li);
        *li = NULL;
        return 1;
    }

    Element *current = *li;

    while(current->next != (*li)){
        current = current->next;
    }
    Element *no = *li;
    current->next = no->next;
    *li = no->next;
    free(no);
    return 1;
}

int remove_end(List* li)
{
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    if((*li) == (*li)->next){
        free(*li);
        *li = NULL;
        return 1;
    }
    
    Element *previous, *no = *li;
    while(no->next != (*li)){
        previous = no;
        no = no->next;
    }
    previous->next = no->next;
    free(no);
    return 1;
}

int remove_middle(List* li, int registration)
{
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    Element *no = *li;

    if(no->data.registration == registration){
        if(no == no->next){
            free(no);
            *li = NULL;
            return 1;
        }else{
            Element *last = *li;
            while(last->next != (*li)){
                last = last->next;
            }
            last->next = (*li)->next;
            *li = (*li)->next;
            free(no);
            return 1;
        }
    }

    Element *previous = no;
    no = no->next;

    while(no != (*li) && no->data.registration != registration){
        previous = no;
        no = no->next;
    }

    if(no == *li) return 0;
    previous->next = no->next;
    free(no);
    return 1;
}

int select_list_position(List* li, int position, struct student *st)
{
    if(li == NULL || (*li) == NULL || position <= 0) return 0;

    Element *no = *li;
    int i = 1;
    while(no->next != (*li) && i < position){
        no = no->next;
        i++;
    }
    if(i != position) return 0;
    else{
        *st = no->data;
        return 1;
    }
}

int select_list_registration(List* li, int registration, struct student *st)
{
    if(li == NULL || (*li) == NULL) return 0;

    Element *no = *li;
    while(no->next != (*li) && no->data.registration != registration){
        no = no->next;
    }

    if(no->data.registration != registration) return 0;
    else{
        *st = no->data;
        return 1;
    }
}