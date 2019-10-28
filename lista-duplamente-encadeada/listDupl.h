struct student {
    int registration;
    char name[30];
    int n1, n2, n3, n4;
};

typedef struct element* List;

List* init_list();

void free_list(List* li);