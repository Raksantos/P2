struct student{
    int registration;
    char name[30];
    double n1, n2, n3, n4;
};

typedef struct description List;

List* init_list();

void free_list(List* li);

int size_list(List* li);

int add_list_end(List* li, struct student st);

int add_list_beginning(List* li, struct student st);