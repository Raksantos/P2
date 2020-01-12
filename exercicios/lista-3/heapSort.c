 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 999

typedef struct heap heap;

struct heap
{
    int size;
    int items[MAX];
};

heap* create_heap();
int is_empty(heap *new_heap);
void swap(int *item_1, int *item_2);
void max_heapify(heap *new_heap, int i);
void heap_sort(heap *new_heap, int tamanhoHeap);
void build_max_heap(heap *new_heap);
void print_heap(heap *new_heap, int i, int aux);

int main()
{

    heap *hp = create_heap();

    int x, tamanhoHeap = 0, i = 1;
    while(scanf("%d", &x) != EOF)
    {
        hp->items[i] = x;
        tamanhoHeap++;
        i++;
    }

    hp->size = tamanhoHeap;

    printf("Estado inicial: ");
    print_heap(hp, 1, 0);

    build_max_heap(hp);
    printf("Estado Atual da Heap: ");

    print_heap(hp, 1, 0);
    if(tamanhoHeap > 1){

        printf("Maior elemento neste passo: %d", hp->items[1]);
    }

    heap_sort(hp, tamanhoHeap);
    return 0;
}

heap *create_heap()
{
    heap *new_heap = (heap*) malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}

int is_empty(heap *new_heap)
{
    return (new_heap->size == 0);
}

void swap(int *item_1, int *item_2)
{
    int aux = 0;
    aux = *item_1;
    *item_1 = *item_2;
    *item_2 = aux;
}

void max_heapify(heap *new_heap, int i)
{
    int bigger;
    int left = 2 * i;
    int right = 2 * i + 1; 

    if((new_heap->size >= left) && (new_heap->items[left] > new_heap->items[i]))
    {
        bigger = left;
    }
    else{
        bigger = i;
    }

    if((new_heap->size >= right) && (new_heap->items[right] > new_heap->items[bigger]))
    {
        bigger = right;
    }
    if(bigger != i)
    {
        swap(&new_heap->items[i], &new_heap->items[bigger]);
        max_heapify(new_heap, bigger);
    }
}

void heap_sort(heap *new_heap, int tamanhoHeap)
{
    build_max_heap(new_heap);
    int n = new_heap->size;
    int i = 0;
    for(i = n; i >= 2; i--)
    {
        printf("\n");
        swap(&new_heap->items[1], &new_heap->items[i]);
        new_heap->size--;
        max_heapify(new_heap, 1);
        printf("Estado Atual da Heap: ");
        print_heap(new_heap, 1, 0);

        if(i > 2){
            printf("Maior elemento neste passo: %d", new_heap->items[1]);
        }
    }
    new_heap->size = tamanhoHeap;

    printf("Resultado Final: ");

    print_heap(new_heap, 1, 0);
}

void build_max_heap(heap *new_heap)
{
    int n = new_heap->size;
    int i = 0;
    for (i = n/2; i >= 1; i--)
    {
        max_heapify(new_heap, i);
    }
}

void print_heap(heap *new_heap, int i, int aux)
{
    if (i == new_heap->size + 1)
    {
        printf("\n");
        return;
    }
    if (aux == 0)
    {
        printf("%d", new_heap->items[i]);
    }
    else{
        printf(" | %d", new_heap->items[i]);
    }
    aux = 1;
    print_heap(new_heap, i+1, aux);
}