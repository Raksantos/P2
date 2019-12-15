#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binary_tree{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
};

typedef struct binary_tree BT;

BT* create_empty_binary_tree()
{
    return NULL;
}

BT* inite_bt(int item, BT* left, BT* right)
{
    BT* bt = (BT*) malloc(sizeof(BT));

    bt->item = item;
    bt->right = right;
    bt->left = left;

    return bt;
}

int is_empty(BT* bt)
{
    return bt == NULL ? 1 : 0;
}

void preOrder(BT* bt)
{
    if(!is_empty(bt)){
        printf(" ( %d ", bt->item);
        //printf("%d ", bt->item);
        if(bt->left == NULL){
            printf(" () ");
        }else{
            preOrder(bt->left);
        }

        if(bt->right == NULL){
            printf(" () ");
        }else{
            preOrder(bt->right); 
        }
    }
    printf(") ");
}

BT* add(BT *bt, int item)
{
    if(is_empty(bt)) bt = inite_bt(item, NULL, NULL);

    else if(bt->item > item) bt->left = add(bt->left, item);

    else bt->right = add(bt->right, item);

    return bt;
}

void printa_valor(BT *bt, int *cont)
{
    printf("( %d ", bt->item);
    
    if(bt->left == NULL){
        printf(" () ");
        if(bt->right == NULL){
            printf(" () ");
        }else{
            *cont++;
            printa_valor(bt->right, cont);
            int aux = 0;
            while(aux < *cont - 2){
                printf(") ");
                aux++;
            }
            return;
        }
    }

    else{
        printa_valor(bt->left, cont);
        if(bt->right == NULL){
            printf(" () )");
            return;
        }else{
            *cont++;
            printa_valor(bt->right, cont);
            int aux = 0;
            while(aux < *cont - 1){
                printf(") ");
                aux++;
            }
            return;
        }
    }

    printf(") ");

    return;
}

int main()
{
    BT *bt = create_empty_binary_tree();

    int x, aux = 0;

    while(scanf("%d", &x) != EOF){
        bt = add(bt, x);

        printf("----\n");
        printf("Adicionando %d\n  ", x);

        preOrder(bt);
        //printa_valor(bt, &aux);

        printf("\n");
    }

    printf("----");

    printf("\n");

    return 0;
}