#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binary_tree
{
    int item;
    struct binary_tree *left;
    struct binary_tree *right;
};

typedef struct element *Stack;

typedef struct binary_tree BT;

BT *create_empty_binary_tree();

BT *inite_bt(int item, BT *left, BT *right);

int is_empty(BT *bt);

void inOrder(BT *bt);

void preOrder(BT *bt);

void posOrder(BT *bt);

BT *add(BT *bt, int item);

BT *remove_node(BT *bt, int item);

BT *remove_current(BT *current);

BT *criando_arvore_aux(int *aux, char *entrada)
{
    BT *bt = create_empty_binary_tree();

    int num;
    char string[500];

    while (entrada[*aux] == '(')
    {
        *aux += 1;
    }

    if (entrada[*aux] != ')')
    {
        int x = 0;

        while (entrada[*aux] != '(')
        {
            string[x++] = entrada[*aux];
            *aux += 1;
        }

        string[x] = '\0';
        num = atoi(string);

        bt = inite_bt(num, NULL, NULL);
        bt->left = criando_arvore_aux(aux, entrada);
        bt->right = criando_arvore_aux(aux, entrada);
    }

    *aux += 1;

    return bt;
}

void search(BT *bt, int *aux, int item, int *depth)
{

    if(bt == NULL) return;

    else if (bt->item == item)
    {
        *aux = 1;
        return;
    }else{
        if(!(*aux)){
            *depth += 1;
            search(bt->left, aux, item, depth);
            search(bt->right, aux, item, depth);
            if(!(*aux)) *depth -= 1;
        }else{
            search(bt->left, aux, item, depth);
            search(bt->right, aux, item, depth);
        }
    }
}

int main()
{
    char entrada[500];

    scanf("%[^\n]s", entrada);

    int item;

    scanf("%d", &item);

    int i, j;

    for (i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] == ' ')
        {
            int contador;
            for (contador = i; contador < strlen(entrada); contador++)
            {
                entrada[contador] = entrada[contador + 1];
            }
        }
    }

    int cont = 0, aux = 0, profundidade = 0;

    BT *bt = criando_arvore_aux(&cont, entrada);

    search(bt, &aux, item, &profundidade);

    if (aux == 1)
    {
        printf("ESTA NA ARVORE\n%d\n", profundidade);
    }
    else
    {
        printf("NAO ESTA NA ARVORE\n-1\n");
    }

    return 0;
}

BT *create_empty_binary_tree()
{
    return NULL;
}

BT *inite_bt(int item, BT *left, BT *right)
{
    BT *bt = (BT *)malloc(sizeof(BT));

    bt->item = item;
    bt->right = right;
    bt->left = left;

    return bt;
}

int is_empty(BT *bt)
{
    return bt == NULL ? 1 : 0;
}

void inOrder(BT *bt)
{
    if (!is_empty(bt))
    {
        inOrder(bt->left);
        printf("%d ", bt->item);
        inOrder(bt->right);
    }
}

void preOrder(BT *bt)
{
    if (!is_empty(bt))
    {
        printf("%d ", bt->item);
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

void posOrder(BT *bt)
{
    if (!is_empty(bt))
    {
        posOrder(bt->left);
        posOrder(bt->right);
        printf("%d ", bt->item);
    }
}

BT *add(BT *bt, int item)
{
    if (is_empty(bt))
        bt = inite_bt(item, NULL, NULL);

    else if (bt->item > item)
        bt->left = add(bt->left, item);

    else
        bt->right = add(bt->right, item);

    return bt;
}

BT *remove_node(BT *bt, int item)
{
    if (is_empty(bt))
    {
        printf("A arvore ja esta vazia\n");
        return NULL;
    }

    struct binary_tree *previous = NULL;
    struct binary_tree *current = bt;

    while (current != NULL)
    {
        if (item == current->item)
        {
            if (current == bt)
                bt = remove_current(current);

            else
            {
                if (previous->right == current)
                    previous->right = remove_current(current);
                else
                    previous->left = remove_current(current);
            }
        }
        previous = current;
        if (item > current->item)
            current = current->right;
        else
            current = current->left;
    }
}

BT *remove_current(BT *current)
{
    BT *no1, *no2;
    if (current->left == NULL)
    {
        no2 = current->right;
        free(current);
        return no2;
    }
    no1 = current;
    no2 = current->left;

    while (no2->right != NULL)
    {
        no1 = no2;
        no2 = no2->right;
    }

    if (no1 != current)
    {
        no1->right = no2->left;
        no2->left = current->left;
    }

    no2->right = current->right;
    free(current);

    return no2;
}