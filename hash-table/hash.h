struct student{
    int registration;
    char name[30];
    double n1, n2, n3;
};

Hash* init_hash(int table_size);

void free_hash(Hash* ha);

int valueString(char *str);

int put_withoutColision(Hash* ha, struct student st);

int get_withoutColision(Hash* ha, struct student* st);

int put_enderOpened(Hash* ha, struct student* st);

int get_enderOpened(Hash* ha, int registration, struct student* st);