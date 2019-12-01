struct student{
    int registration;
    char name[30];
    double n1, n2, n3, n4;
};

typedef struct element* Stack;

Stack* init_stack();

void free_stack(Stack* pi);

int size_stack(Stack* pi);

int full_stack(Stack* pi);

int empty_stack(Stack* pi);

int push(Stack* pi, struct student st);

int pop(Stack* pi);

int top(Stack* pi, struct student *aux);