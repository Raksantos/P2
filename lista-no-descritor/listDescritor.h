struct student{
    int registration;
    char name[30];
    double n1, n2, n3, n4;
};

typedef struct description List;

List* init_list();

void free_list();

int size_list(List *li);