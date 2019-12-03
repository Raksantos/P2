#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
    int num;
    struct element *next;
};

typedef struct element Element;

typedef struct element* List;

int linear_search(List* li, int size_list, int element)
{
    if(li == NULL) return 0;//se a lista não tiver conteudo, está vazia

    Element *no = *li;// elemento auxiliar
    while(no != NULL){
        if(no->num == element){
            return 1;
        }
        no = no->next;//pecorre a lista
    }

    return 0;//se não encontrar ninguém, retorna falso
}
List* init_list()
{
    List *li = (List*) malloc(sizeof(List));//aloca espaço de memória pra lista

    if(li != NULL)//se tiver algum dado na lista
        *li = NULL;//esvazia ela fazendo a atribuição

    return li;//retorna a lista vazia
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

int add_end(List *li, int i)
{
    if(li == NULL) return 0; // se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 0

    no->num = i;//passa os dados
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

int main()
{
    List *li1 = init_list();
    List *li2 = init_list();
    int size, i, aux;
    scanf("%d", &size);

    for(i = 0; i < size; i++){
        scanf("%d", &aux);
        add_end(li1, aux);
    }

    scanf("%d", &size);

    for(i = 0; i < size; i++){
        scanf("%d", &aux);
        add_end(li2, aux);
    }

    aux = 0;

    Element *no = *li2;
    while(no != NULL){
        if(linear_search(li1, sizeof_list(li1), no->num)){
            aux++;
        }
        no = no->next;
    }

    if(aux == sizeof_list(li2)){
        printf("1\n");
    }
    else{
        printf("0\n");
    }

    return 0;
}