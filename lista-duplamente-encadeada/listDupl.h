struct student {
    int registration;
    char name[30];
    int n1, n2, n3, n4;
};

typedef struct element* List;

List* init_list();

void free_list(List* li);

int sizeof_list(List* li);

int empyt_list(List* li);

int add_beginning(List* li, struct student st);

int add_end(List* li, struct student st);

int add_middle(List* li, struct student st);

int remove_beginning(List* li);