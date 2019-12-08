#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element{
    char carctere;
    int frequency;
    struct element *next;
};

typedef struct element Element;

typedef struct element* List;

void swap(char *position1, char *position2)
{
    char aux = *position1;
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

int partitionate(char *array, int begin, int end)
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

void quickSort(char *array, int begin, int end)
{
    int pivot;
    if (begin < end){
        pivot = partitionate(array, begin, end);
        quickSort(array, begin, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

int add_end(List *li, char carctere, int fre)
{
    if(li == NULL) return 0; // se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 0

    no->carctere = carctere;//passa os dados
    no->frequency = fre;
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

void insertionSort(char *array, int size_array)
{
    int i, j, aux;
    for(i = 0; i < size_array; i++){
        aux = array[i];
        for(j = i; (j > 0) && (aux > array[j - 1]); j--){
            array[j] = array[j - 1];
        }
        array[j] = aux;
    }
}

int main()
{
    char text[256];
    int text_size = 0, i, j, aux, already_in = 0, fre = 0;
    
    scanf("%[^\n]s", text);

    for(i = 0; text[i] != '\0'; i++){
        text_size++;
    }

    quickSort(text, 0, text_size - 1);
    insertionSort(text, text_size);

    aux = text_size;

    List *li = init_list();

    for(i = 0; i < text_size; i++){
        for(j = (text_size - aux) - 1; j >= 0; j--){
            if(text[i] == text[j]){
                already_in = 1;
            }
        }
        if(!already_in){
            for(j = i; j < text_size; j++){
                if(text[i] == text[j]){
                    fre++;
                }
            }
            add_end(li, text[i], fre);
            printf("%c %d\n", text[i], fre);
        }
        aux--;
        already_in = 0;
        fre = 0;
    }

    return 0;
}