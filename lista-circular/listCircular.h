struct student{
    int registration;
    char name[30];
    double n1, n2, n3, n4;
};

typedef struct element* List;

struct element{
    struct student data;
    struct element *next;
};

typedef struct element Element;

List* init_list();

void free_list(List* li);

int size_list(List* li);

int empty_list(List* li);