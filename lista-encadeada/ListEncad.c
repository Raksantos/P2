#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListEncad.h"
#define debug if(0)
struct element{
    struct student data;
    struct element *next;
};

typedef struct element Element;

int main()
{
    List *li = init_list();
    int x = sizeof_list(li);
    debug printf("Tamanho da lista ao iniciar: %d\n", x);

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
    strcpy(aluno1.name, "Pedro");
    aluno1.n1 = 10.0;
    aluno1.n2 = 10.0;
    aluno1.n3 = 10.0;
    aluno1.n4 = 10.0;

    if(add_end(li, aluno2)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao adicionar o aluno.\n");
    }

    struct student aluno3;
    aluno3.registration = 123789;
    strcpy(aluno3.name, "Joao");
    aluno3.n1 = 10.0;
    aluno3.n2 = 10.0;
    aluno3.n3 = 10.0;
    aluno3.n4 = 10.0;

    if(add_middle(li, aluno3)){
        debug printf("Aluno adicionado com sucesso!\n");
        debug printf("Tamanho atual da lista: %d\n", sizeof_list(li));
    }
    else{
        printf("Ocorreu um erro ao adicionar o aluno.\n");
    }

    free_list(li);

    debug printf("Tamanho da lista depois do free: %d\n", sizeof_list(li));
    return 0;
}

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));//aloca espaço de memória pra lista

    if(li != NULL)//se tiver algum dado na lista
        *li = NULL;//esvazia ela fazendo a atribuição

    return li;//retorna a lista vazia
}

void free_list(List* li)
{
    if(li != NULL){//se a lista não estiver vazia
        Element *no;//cria elemento auxiliar
        while((*li) != NULL){//enquanto a lista não estiver vazia
            no = *li;//auxilar recebe o valor do nó
            *li = (*li)->next;//cabeça da lista apontara para o próximo elemento
            free(no);//libera os dados do nó
        }
        free(li);//ao acabar de pecorrer a lista, libera a memória da lista
    }
}

int sizeof_list(List* li)
{
    if(li == NULL) return 0;//se a lista não tiver conteudo, está vazia

    int count = 0;
    Element *no = *li;// elemento auxiliar
    while(no != NULL){
        count++;//enquanto o elemento não estiver no final da lista, adiciona mais um ao contador
        no = no->next;//pecorre a lista
    }
    return count;
}

int empty_list(List* li)
{
    return (li == NULL || *li == NULL) ? 1 : 0; //se a lista estiver sem conteúdo ou apontando para nenhum canto, está vazia.
}

int add_beginning(List* li, struct student st)
{
    if(li == NULL) return 0;// se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 

    no->data = st; //passa os dados
    no->next = (*li);
    *li = no; //ponteiro que aponta para a cabeça da lista aponta para o novo nó
    return 1;
}

int add_end(List *li, struct student st)
{
    if(li == NULL) return 0; // se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 0

    no->data = st;//passa os dados
    no->next = NULL;//faz com que o ponteiro aponte para null, já que é o último elemento
    if((*li) == NULL){
        *li = no;//se a lista for vazia ele vai inserir no início
    }
    //se não for uma lista vazia
    else{
        Element *aux = *li;//cria um elemento auxiliar que irá pecorrer a lista, iniciando da cabeça
        while(aux->next != NULL){//enquanto o ponteiro do elemento auxiliar não apontar para null, vai para o próximo
            aux = aux->next; // pecorrendo a lista
        }
        aux->next = no; // aponta o último nó da lisa para o novo último nó
    }
}

int add_middle(List* li, struct student st)
{
    if(li == NULL) return 0; //se a lista não existir, retorna erro

    Element *no = (Element*) malloc(sizeof(Element)); // aloca espaço para o novo elemento
    if(no == NULL) return 0;//se ocorrer problema na alocação da memória do nó, retorna erro

    no->data = st;
    if(empty_list(li)){//se a lista estiver vazia
        no->next = (*li);//no irá apontar para null, pois está no início da lista e ela está vazia
        *li = no;//ponteiro da cabeça aponta para o novo nó
        return 1;
    }

    else{//procura onde inserir
        Element *previous, *current = *li;//cria os auxiliares anterior e atual
        while(current != NULL && current->data.registration < st.registration){//se eu não chegar no final da lista e a matrícula do atual for menor que a do que estou inserindo
            previous = current;//anterior agora passa a ser o antigo atual
            current = current->next;//atual irá apontar para o próximo nó
        }
        if(current == *li){//se o elemento atual for o início da lista, ele irá inserir no início da lista
            no->next = (*li);
            *li = no;
        }
        else{//se não, ele está ou no final ou no meio
            no->next = previous->next;//no inserido irá apontar para o nó atual, que agora será o próximo
            previous->next = no;//no anterior irá apontar para o nó inserido, que agora será o atual
        }
    }
    return 1;
}