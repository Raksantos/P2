struct student{
    int registration;
    char name[30];
    float n1, n2, n3, n4;
};

typedef struct queue Queue;

Queue* init_queue();

void free_queue(Queue* fi);