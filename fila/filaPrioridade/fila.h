#define MAX 100

struct pacient{
    char name[30];
    int prio;
};

typedef struct queue_prio QueuePrio;

QueuePrio* init_queue();

void free_queue(QueuePrio* fi);

int size_queue(QueuePrio* fi);

int full_queue(QueuePrio* fi);

int empty_queue(QueuePrio* fi);

int enqueue(QueuePrio* fi, char *name, int prio);

int dequeue(QueuePrio* fi);

int select_queue(QueuePrio* fi, char *name);