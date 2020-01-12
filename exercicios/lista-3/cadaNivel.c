#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct binary_tree
{
	int item;
	int lvl;
    int value;
	struct binary_tree *right;
	struct binary_tree *left;
};

typedef struct binary_tree BT;

BT *create_tree(int item, BT *right, BT *left);

int verifica(BT *root, int array[], int menor[], int cont);

int main()
{
	int cont, n1, n2, n3, i;

	scanf("%d", &cont);
	
	BT* array_nodes[cont];

	for (i = 0; i < cont; i++)
	{
		scanf("%d %d %d\n", &n1, &n2, &n3);

		BT *root = create_tree(i, NULL, NULL);
		BT *no1;
		if(n2 != -1){
            no1 = create_tree(n2, NULL, NULL);
        }
			
		else{
            no1 = NULL;
        }

		BT *no2;
		if(n3 != -1){
            no2 = create_tree(n3, NULL, NULL);
        }
		else{
            no2 = NULL;
        }

		root->left = no1;
		root->right = no2;
		root->value = n1;

		array_nodes[i] = root;
	}

	for (i = 0; i < cont; i++)
	{
		BT *node = array_nodes[i];
		
        int position;

		if(node->left)
		{
			position = node->left->item;
			node->left = array_nodes[position];
		}

		if(node->right)
		{
			position = node->right->item;
			node->right = array_nodes[position];
		}

	}

	int tamanho = 200;
	int maior[tamanho];
	int menor[tamanho];

	for (i = 0; i <tamanho; i++)
	{
		maior[i] = 0;
	}

	for (i = 0; i <tamanho; i++)
	{
		menor[i] = __INT16_MAX__;
	}

	int aux = verifica(array_nodes[0], maior, menor, 0);
	
	for (i = 0; i < aux; i++)
	{
		int biggest = maior[i];
		int smallest = menor[i];
		printf("Nivel %d: Maior = %d, Menor = %d\n", i + 1, biggest, smallest);
	}
    return 0;
}

BT *create_tree(int item, BT *left, BT *right)
{
	BT *bt = malloc(sizeof(BT));
    
	bt->item = item;
	bt->right = right;
	bt->left = left;

	return bt;
}

int verifica(BT *root, int array[], int menor[], int cont)
{
	if(root == NULL)
	{
		return cont;
	}

	root->lvl = cont;

	if(root->value > array[cont])
	{
		array[cont] = root->value;
	}

	if(root->value < menor[cont])
	{
		menor[cont] = root->value;
	}

	int value1 = verifica(root->left, array, menor, cont + 1);
	int value2 = verifica(root->right, array, menor, cont + 1);

	return value1 > value2 ? value1 : value2;
}