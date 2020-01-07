#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "fila.h"

struct hash{
    int qtd, table_size;
    struct student **itens;
};

typedef struct hash Hash;

int main()
{
    Hash *ha = init_hash(1427);
    return 0;
}

Hash* init_hash(int table_size)
{
    Hash* ha = (Hash*) malloc(sizeof(Hash));

    if(ha != NULL){
        int i;
        ha->table_size = table_size;
        ha->itens = (struct student**) malloc(table_size * sizeof(struct student*));

        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for(i = 0; i < ha->table_size; i++){
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void free_hash(Hash* ha)
{
    if(ha != NULL){
        int i;
        for (i = 0; i < ha->table_size; i++){
            if(ha->itens[i] != NULL){
                free(ha->itens[i]);
            }
            free(ha->itens);
            free(ha);
        }
    }
}

