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

int is_empty(BT* bt)
{
    return bt == NULL ? 1 : 0;
}

BT* init_bt(int item, BT* left, BT* right)
{
    BT* bt = (BT*) malloc(sizeof(BT));

    bt->item = item;
    bt->right = right;
    bt->left = left;

    return bt;
}

void dfs(BT* bt, BT* aux)
{
    if(!is_empty(bt)){
        if(bt->item == aux->item){
            bt->left = aux->left;
            bt->right = aux->right;
            return;
        }
        else{
            dfs(bt->left, aux);
            dfs(bt->right, aux);
        }
    }
}

BT* add(BT *bt, int item)
{
    if(is_empty(bt)) bt = init_bt(item, NULL, NULL);

    else if(bt->item > item) bt->left = add(bt->left, item);

    else bt->right = add(bt->right, item);

    return bt;
}

BT* criando_arvore_aux(int *aux, char *entrada)
{
    BT *bt = create_empty_binary_tree();

    int num;
    char string[500];

    while(entrada[*aux]=='(')
    {
        *aux += 1;
    }

    if(entrada[*aux]!=')')
    {
        int x = 0;
        while(entrada[*aux]!='(')
        {
            string[x++] = entrada[*aux];
            *aux += 1;
        }

        string[x] = '\0';
        num = atoi(string);

        bt = init_bt(num, NULL, NULL);
        bt->left = criando_arvore_aux(aux, entrada);
        bt->right = criando_arvore_aux(aux, entrada);

    }

    *aux += 1;
    
    return bt;
}

void printar_arvore(BT* bt)
{
    if(!is_empty(bt)){
        printf("(%d", bt->item);
        if(bt->left == NULL){
            printf("()");
        }else{
            printar_arvore(bt->left);
        }

        if(bt->right == NULL){
            printf("()");
        }else{
            printar_arvore(bt->right); 
        }
    }
    printf(")");
}

void principal_recursiva(BT *matriz, int contador)
{
    char entrada[500];

    scanf("%[^\n]s", entrada);

    getchar();

    int taman = strlen(entrada);

    if(entrada[0] == '(' && entrada[1] == ')' && taman == 2)
    {
        printar_arvore(matriz);
        printf("\n");
        return;
    }else{

        int cont = 0;

        if(contador == 0){
            matriz = criando_arvore_aux(&cont, entrada);

            contador++; 

            principal_recursiva(matriz, contador);
        }else{

            BT *aux = criando_arvore_aux(&cont, entrada);

            printf("\n");


            dfs(matriz, aux);

            principal_recursiva(matriz, contador);

        }
    }
}

int main()
{
    BT *bt;
    principal_recursiva(bt, 0);

    return 0;
}