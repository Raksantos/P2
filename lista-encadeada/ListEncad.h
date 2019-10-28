struct student {
    int registration;
    char name[30];
    float n1, n2, n3, n4;
};

typedef struct element* List;

List* init_list();

void free_list(List* li);

int sizeof_list(List* li);

int empty_list(List* li);

int add_beginning(List* li, struct student st);

int add_middle(List* li, struct student st);

int add_end(List* li, struct student st);

int remove_beginning(List* li);

int remove_end(List* li);

int remove_middle(List* li, int student_registration);

int select_list_position(List* li, int position, struct student *data);

int select_list_registration(List* li, int registration, struct student *data);