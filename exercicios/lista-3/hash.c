#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

typedef struct element element;
typedef struct hash_table hash_table;

struct element
{
    int value;
    element *next;
};

struct hash_table
{
    element *table[SIZE];
};

hash_table* create_hash_table();
void put(hash_table *ht, int key, int value);
int dispersao(int x, int n);
void print_ht(hash_table *ht, int size);
void remove_hash(hash_table *hash, int key);

int main()
{

    int n, i;
    scanf("%d", &n);

    for(i = 0; i < n; i++){

        hash_table *ht = create_hash_table();

        int m, c, j;
        scanf("%d %d", &m, &c);

        for(j = 0; j < c; j++)
        {
            int valor;
            scanf("%d", &valor);

            int posicao = dispersao(valor, m);

            put(ht, posicao, valor);
        }


        print_ht(ht, m);
        printf("\n");

        free(ht);
    }

}

int dispersao(int x, int n)
{
    return x % n;
}

void print_ht(hash_table *ht, int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        element *aux = ht->table[i];
        printf("%d ->",i);
        while(aux!=NULL){
            printf(" %d ->", aux->value);
            aux = aux->next ;
        }
       printf(" \\\n");
    }    
}

hash_table* create_hash_table()
{
    hash_table *new_hash_table = (hash_table*) malloc(sizeof(hash_table));

    int i;
    for (i = 0; i < SIZE; i++)
    {
        new_hash_table->table[i] = NULL;
    }

    return new_hash_table;
}

void put(hash_table *ht, int position, int value)
{
    element *node = (element*) malloc(sizeof(node));

    node->value = value;
    node->next = NULL;

    if(ht->table[position] == NULL)
    {
        ht->table[position] = node;
    }else{
        element *aux = ht->table[position];
        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = node;
    }
}