struct student{
    int registration;
    char name[30];
    double n1, n2, n3, n4;
};

typedef struct element* List;

List* init_list();

void free_list(List* li);

int size_list(List* li);

int empty_list(List* li);

int add_beginning(List* li, struct student st);

int add_end(List* li, struct student st);

int add_ordered(List* li, struct student st);

int remove_beginning(List* li);

int remove_end(List* li);

int remove_middle(List* li, int registration);

int select_list_position(List* li, int position, struct student *st);

int select_list_registration(List* li, int registration, struct student *st);