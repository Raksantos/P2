#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#define MAX_SIZE 5

struct adj_list{
    int item;
    struct adj_list *next;
};

struct grafo{
    struct adj_list *vertices[MAX_SIZE];
    short visited[MAX_SIZE];
};

struct element{
    int data;
    struct element* next;
};

struct queue{
    struct element *begin, *end; 
};

typedef struct element Element;

typedef struct queue Queue;

Queue* init_queue()
{
    Queue *fi = (Queue*) malloc(sizeof(Queue));

    if(fi != NULL){
        fi->begin = NULL;
        fi->end = NULL;
    }

    return fi;
}

int size_queue(Queue* fi)
{
    if(fi == NULL) return 0;

    int cont = 0;
    Element *no = fi->begin;
    while(no != NULL){
        cont++;
        no = no->next;
    }

    return cont;
}

int full_queue(Queue* fi)
{
    return 0;
}

int empty_queue(Queue* fi)
{
    if(fi == NULL || fi->begin == NULL) return 1;

    return 0;
}

int enqueue(Queue* fi, int item)
{
    if(fi == NULL || full_queue(fi)) return 0;

    Element* no = (Element*) malloc(sizeof(Element));

    if(no == NULL) return 0;

    no->data = item;
    no->next = NULL;
    
    if(fi->end == NULL) {
        fi->begin = no;
    }else{
        fi->end->next = no;
        fi->end = no;
    }
    return 1;
}

int dequeue(Queue* fi)
{
    if(fi == NULL || empty_queue(fi)) return 0;
    Element *no = fi->begin;
    fi->begin = fi->begin->next;

    if(fi->begin == NULL) fi->end = NULL; //fila ficou vazia

    free(no);
    return 1;
}

int select_queue(Queue* fi, int *aux)
{
    if(fi == NULL || empty_queue(fi)) return 0;

    *aux = fi->begin->data;
    return 1;
}

int main()
{
    Graph *gr = init_graph();
    return 0;
}

Graph* init_graph()
{
    Graph *gr = (Graph*) malloc(sizeof(Graph));

    int i;
    for(i = 1; i <= MAX_SIZE; i++){
        gr->vertices[i] = 0;
        gr->visited[i] = 0;
    }

    return gr;
}

int add_edge(Graph* gr, int vertex1, int vertex2)
{
    struct adj_list *vertex = create_adj_list(vertex2);
    vertex->next = gr->vertices[vertex1];
    gr->vertices[vertex1] = vertex;

    vertex = create_adj_list(vertex1);
    vertex->next = gr->vertices[vertex2];
    gr->vertices[vertex2] = vertex;
}

struct adj_list* create_adj_list(int item)
{
    struct adj_list *new_adj_list = (struct adj_list*) malloc(sizeof(struct adj_list));

    new_adj_list->item = item;
    new_adj_list = NULL;

    return new_adj_list;
}

void dfs(Graph* gr, int source)
{
    gr->visited[source] = 1;
    printf("%d\n", source);

    struct adj_list *list = gr->vertices[source];

    while(list != NULL){
        if(!gr->visited[list->item]){
            dfs(gr, list->item);
        }
        list = list->next;
    }
}

void bfs(Graph* gr, int source)
{
    Queue *queue = init_queue();
    int *dequeued;
    struct adj_list *list = gr->vertices[source];

    gr->visited[source] = 1;
    enqueue(queue, source);

    while(!empty_queue(queue)){
        select_queue(queue, dequeued);
        dequeue(queue);

        list = gr->vertices[*dequeued];

        while(list != NULL){
            if(!gr->visited[list->item]){
                printf("%d\n", list->item);
                gr->visited[list->item] = 1;
                enqueue(queue, list->item);
            }
            list = list->next;
        }
    }
}

