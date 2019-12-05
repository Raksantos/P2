#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct element{
    int num;
    int posi;
    struct element *next;
};

typedef struct element Element;

typedef struct element* List;

void swap(int *position1, int *position2)
{
    int aux = *position1;
    *position1 = *position2;
    *position2 = aux;
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
        no->posi = 1;
    }
    //se não for uma lista vazia
    else{
        int i = 1;
        Element *aux = *li;//cria um elemento auxiliar que irá pecorrer a lista, iniciando da cabeça
        while(aux->next != NULL){//enquanto o ponteiro do elemento auxiliar não apontar para null, vai para o próximo
            aux = aux->next; // pecorrendo a lista
            i++;
        }
        aux->next = no; // aponta o último nó da lisa para o novo último nó
        aux->posi = i;
    }
}

int partitionate(int *array, int begin, int end)
{
    int left, right, pivot, aux;
    left = begin;
    right = end;
    pivot = array[begin];
    while(left < right){
        while(array[left] <= pivot){
            left++;
        }
        while(array[right] > pivot){
            right--;
        }
        if(left < right){
            swap(&array[left], &array[right]);
        }
    }
    array[begin] = array[right];
    array[right] = pivot;
    return right;
}

void quickSort(int *array, int begin, int end)
{
    int pivot;
    if (begin < end){
        pivot = partitionate(array, begin, end);
        quickSort(array, begin, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int linear_search(List* li, int element)
{
    Element *no = *li;
    while(no != NULL){//enquanto o i não tiver o tamanho do list, isto é, o tamanho do elemento, adiciona 1
        if(element == no->num){
            return 1;//encontrou o elemento
        }//se e encontrar alguém em alguma posição
        no = no->next;
    }
    return 0;//se não encontrar ninguém, retorna falso
}

int linear_search_array(int *array, int size_array, int element)
{
    int i;//contador de posições
    for(i = 0; i < size_array; i++){//enquanto o i não tiver o tamanho do array, isto é, o tamanho do elemento, adiciona 1
        if(element == array[i]){
            return i;//retorna a posição encontrada
        }//se e encontrar alguém em alguma posição
    }
    return -1;//se não encontrar ninguém, retorna uma posição inválida
}

int main()
{
    List *li1 = init_list();
    List *li2 = init_list();
    int list_aux[20] = {0}, i, aux = 0;

    for(i = 0; i < 20; i++){
        scanf("%d", &aux);
        add_end(li1, aux);
    }

    for(i = 0; i < 20; i++){
        scanf("%d", &aux);
        add_end(li2, aux);
    }

    Element *no = *li2;

    aux = 0;

    while(no != NULL){
        if(linear_search(li1, no->num)){
            if(linear_search_array(list_aux, aux, no->num) == -1){
                list_aux[aux] = no->num;
                aux++;    
            }
        }
        no = no->next;
    }
    
    if(aux == 0){
        printf("VAZIO\n");
    }else{
        quickSort(list_aux, 0, aux - 1);
        for(i = 0; i < aux; i++){
            printf("%d\n", list_aux[i]);
        }
    }

    return 0;
}