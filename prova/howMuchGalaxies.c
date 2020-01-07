#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct Adj Adj;
typedef struct Graph Graph;
typedef struct Queue Queue;

struct Adj
{
    int item;
    Adj *next;
};

struct Graph
{
    Adj *vertices[max];
    short visited[max];
};

struct element_queue{
    int item;
    struct element_queue* next;
};

struct Queue{
    struct element_queue *begin, *end; 
};

struct element{
    struct Graph *gr;
    struct element *next;
};


typedef struct element_queue elq;

typedef struct element Element;

typedef struct element* List;

Queue* create_queue();
int is_empty(Queue *queue);
int enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
Graph* create_graph();
Adj* create_adj_list(int item);
void add_edge(Graph *graph, int vertex1, int vertex2);
void bfs(Graph *graph, int source, int *achou);

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));//aloca espaço de memória pra lista

    if(li != NULL)//se tiver algum dado na lista
        *li = NULL;//esvazia ela fazendo a atribuição

    return li;//retorna a lista vazia
}

int add_end(List *li, Graph *gr)
{
    if(li == NULL) return 0; // se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 0

    no->gr = gr;//passa os dados
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


void inicia_grafos(List* li, int i, int rotas)
{
    if(i < rotas){
        int plan1, plan2, achou = 0, j;

        scanf("%d %d", &plan1, &plan2);

        Element *no = *li;

        while(no != NULL){
            
        }

        i++;
        inicia_grafos(li, i, rotas);
    }
}

int main()
{
    List *li = init_list();

    Graph *graph = create_graph();

    add_end(li, graph);

    int rotas, planetas;

    scanf("%d %d", &rotas, &planetas);

    inicia_grafos(li, 0, rotas);

    return 0;
}

Queue* create_queue()
{
    Queue *fi = (Queue*) malloc(sizeof(Queue));

    if(fi != NULL){
        fi->begin = NULL;
        fi->end = NULL;
    }

    return fi;
}

int full_queue(Queue* fi)
{
    return 0;
}

int is_empty(Queue* fi)
{
    if(fi == NULL || fi->begin == NULL) return 1;

    return 0;
}

int enqueue(Queue* fi, int item)
{
    if(fi == NULL || full_queue(fi)) return 0;

    elq* no = (elq*) malloc(sizeof(elq));

    if(no == NULL) return 0;

    no->item = item;
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
    if(fi == NULL || is_empty(fi)) return 0;
    elq *no = fi->begin;
    fi->begin = fi->begin->next;

    if(fi->begin == NULL) fi->end = NULL; //fila ficou vazia

    free(no);
    return 1;
}

Graph* create_graph()
{
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    int i;
    for(i = 1; i <= max; i++)
    {
        graph -> vertices[i] = NULL;
        graph -> visited[i] = 0;
    }
    return graph;
}

Adj* create_adj_list(int item)
{
    Adj *new_adj = (Adj*) malloc(sizeof(Adj));
    new_adj->item = item;
    new_adj->next = NULL;
    return new_adj;
}

void add_edge(Graph *graph, int vertex1, int vertex2)
{
    Adj *vertex = create_adj_list(vertex2);
    vertex -> next = graph -> vertices[vertex1];
    graph -> vertices[vertex1] = vertex;
}

void bfs(Graph *graph, int source, int *achou)
{
    Queue *queue = create_queue();
    int dequeued;
    Adj *adj_list = graph->vertices[source];

    if(graph->visited[source] == 1) *achou == 1;

    graph->visited[source] = 1;
    //printf("%d\n", source);
    enqueue(queue, source);
    while(!is_empty(queue))
    {
        dequeued = dequeue(queue);
        adj_list = graph->vertices[dequeued];

        while(adj_list != NULL)
        {
            if(!graph->visited[adj_list -> item])
            {
                *achou = 1;
                //printf("%d\n", adj_list -> item);
                graph->visited[adj_list -> item] = 1;
                enqueue(queue, adj_list -> item);
            }
            adj_list = adj_list->next;
        }
    }
}