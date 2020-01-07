struct student{
    int registration;
    char name[30];
    double n1, n2, n3, n4;
};

typedef struct queue Queue;

Queue* init_queue();

void free_queue(Queue* fi);

int size_queue(Queue* fi);

int full_queue(Queue* fi);

int empty_queue(Queue* fi);

int enqueue(Queue* fi, struct student st);

int dequeue(Queue* fi);

int select_queue(Queue* fi, struct student *aux);