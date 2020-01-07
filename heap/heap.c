#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define MAX_HEAP_SIZE 10

struct Heap{
    int size;
    int data[MAX_HEAP_SIZE];
};

int main()
{
    heap *hp = create_heap();
    int i;

    heapSort(hp);

    for(i = 0; i < 9; i++){
        printf("%d\n", hp->data[i]);
    }
    
    return 0;
}

heap* create_heap()
{
    heap *hp = (heap*) malloc(sizeof(heap));
    hp->size = MAX_HEAP_SIZE;

    return hp;   
}

int get_parent_index(heap *hp, int i)
{
    return i/2;
}

int get_left_index(heap *hp, int i)
{
    return 2*i;
}

int get_right_index(heap *hp, int i)
{
    return 2*i + 1;
}

int item_of(heap *hp, int i)
{
    return hp->data[i];
}

void swap(int *position1, int *position2)
{
    int aux = *position1;
    *position1 = *position2;
    *position2 = aux;
}

void enqueue(heap *hp, int item)
{
    if(hp->size >= MAX_HEAP_SIZE) printf("Heap overflow");

    else{
        hp->data[++hp->size] = item;

        int key_index = hp->size;
        int parent_index = get_parent_index(hp, hp->size);

        while(parent_index >= 1 && hp->data[key_index] > hp->data[parent_index]){
            swap(&hp->data[key_index], &hp->data[parent_index]);

            key_index = parent_index;

            parent_index = get_parent_index(hp, key_index);
        }
    }
}

int is_empty(heap *hp)
{
    return hp->size == 0 ? 1 : 0;
}

int dequeue(heap *hp)
{
    if(is_empty(hp)){
        printf("Heap underflow");
        return -1;
    }
    else{
        int item = hp->data[1];

        hp->data[1] = hp->data[hp->size];

        hp->size--;

        max_heapify(hp, 1);

        return item;
    }
}

void max_heapify(heap *hp, int i)
{
    int largest;
    int left_index = get_left_index(hp, i);
    int right_index = get_right_index(hp, i);

    if(left_index <= hp->size && hp->data[left_index] > hp->data[i]){
        largest = left_index;
    }else{
        largest = i;
    }

    if(right_index <= hp->size && hp->data[right_index] > hp->data[largest]){
        largest = right_index;
    }

    if(hp->data[i] != hp->data[largest]){
        swap(&hp->data[i], &hp->data[largest]);
        max_heapify(hp, largest);
    }
}

void heapSort(heap *hp)
{
    int i;
    for(i = hp->size; i >= 2; i--)
    {
        swap(&hp->data[1], &hp->data[i]);

        hp->size--;

        max_heapify(hp, 1);
    }
}