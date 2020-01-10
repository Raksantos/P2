#include <stdio.h>
#include <stdlib.h>

struct binary_tree{
    int item;
    int value;
    struct binary_tree *left;
    struct binary_tree *right;
};

typedef struct binary_tree BT;

BT* create_empty_binary_tree();

BT* inite_bt(int item, BT* left, BT* right);

BT* search(BT *bt, int item);

int is_empty(BT* bt);

void inOrder(BT* bt);

void preOrder(BT* bt);

void posOrder(BT* bt);

BT* add(BT *bt, int item);

BT* remove_node(BT *bt, int item);

BT* remove_current(BT* current);

void depth(BT *bt, int item, int *profundidade, int profDesejada, int min, int max);

void cria_arvore(int n, BT* bt)
{
    if(n > 0){

        int value, childleft, childright;

        scanf("%d %d %d", &value, &childleft, &childright);

        if(childleft == -1){
            bt->left = NULL;
        }

        else if(childright == -1){
            bt->right = NULL;
        }

        else if(childright == -1 && childleft == -1){
            bt->right = NULL;
            bt->left = NULL;
        }

        else{
            bt->right->item = childright;
            bt->left->item = childleft;
        }

        bt->value = value;

        n--;
        cria_arvore(n, bt);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int value, childleft, childright;

    scanf("%d %d %d", &value, &childleft, &childright);

    BT *bt = inite_bt(0, NULL, NULL);

    if(childleft == -1){
        bt->left = NULL;
    }

    else if(childright == -1){
        bt->right = NULL;
    }

    else if(childright == -1 && childleft == -1){
        bt->right = NULL;
        bt->left = NULL;
    }

    else{
        bt->right->item = childright;
        bt->left->item = childleft;
    }

    bt->value = value;

    n--;

    cria_arvore(n, bt);

    return 0;
}

void depth(BT *bt, int item, int *profundidade, int profDesejada, int min, int max)
{
    if(bt == NULL) return;

    else{
        if(*profundidade != profDesejada){
            *profundidade += 1;
            depth(bt->left, item, profundidade, profDesejada, min, max);
            depth(bt->right, item, profundidade, profDesejada, min, max);
            if(*profundidade != profDesejada) *profundidade -= 1;
        }else{
            depth(bt->left, item, profundidade, profDesejada, min, max);
            depth(bt->right, item, profundidade, profDesejada, min, max);
        }
    }
}

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

BT* search(BT *bt, int item)
{
    if((bt == NULL) || (bt->item == item)) return bt;

    else if(bt->item > item){
        return search(bt->left, item);
    }
    else{
        return search(bt->right, item);
    }
}

int is_empty(BT* bt)
{
    return bt == NULL ? 1 : 0;
}

void inOrder(BT* bt)
{
    if(!is_empty(bt)){
        inOrder(bt->left);
        printf("%d ", bt->item);
        inOrder(bt->right); 
    }
}

void preOrder(BT* bt)
{
    if(!is_empty(bt)){
        printf("%d ", bt->item);
        preOrder(bt->left);
        preOrder(bt->right); 
    }
}

void posOrder(BT* bt)
{
    if(!is_empty(bt)){
        posOrder(bt->left);
        posOrder(bt->right); 
        printf("%d ", bt->item);
    }
}

BT* add(BT *bt, int item)
{
    if(is_empty(bt)) bt = inite_bt(item, NULL, NULL);

    else if(bt->item > item) bt->left = add(bt->left, item);

    else bt->right = add(bt->right, item);

    return bt;
}

BT* remove_node(BT *bt, int item)
{
    if(is_empty(bt)){
        printf("A arvore ja esta vazia\n");
        return NULL;
    }

    struct binary_tree *previous = NULL;
    struct binary_tree *current = bt;

   while(current != NULL){
       if(item == current->item){
           if(current == bt) bt = remove_current(current);

           else{
                if(previous->right == current)
                    previous->right = remove_current(current);
                else
                    previous->left = remove_current(current);
           }
       }
       previous = current;
       if(item > current->item)
          current = current->right;
        else
            current = current->left;
   } 
}

BT* remove_current(BT* current)
{
    BT *no1, *no2;
    if(current->left == NULL){
        no2 = current->right;
        free(current);
        return no2;
    }
    no1 = current;
    no2 = current->left;

    while(no2->right != NULL){
        no1 = no2;
        no2 = no2->right;
    }

    if(no1 != current){
        no1->right = no2->left;
        no2->left = current->left;
    }

    no2->right = current->right;
    free(current);

    return no2;
}