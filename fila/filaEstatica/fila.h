struct student{
    int registration;
    char name[30];
    float n1, n2, n3, n4;
};

typedef struct queue Queue;

Queue* init_queue();

void free_queue(Queue* fi);

int size_queue(Queue* fi);

int full_queue(Queue* fi);

int empty_queue(Queue* fi);

int add (Queue* fi, struct student al);

int remove_queue(Queue* fi);

int select_queue(Queue* fi, struct student *st);