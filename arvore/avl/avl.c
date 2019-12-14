#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

struct binary_tree
{
    int item;
    int h;
    struct binary_tree *left;
    struct binary_tree *right;
};

int main()
{
    BT *bt = create_empty_binary_tree();

    bt = add(bt, 4);
    bt = add(bt, 5);
    bt = add(bt, 7);
    bt = add(bt, 2);
    bt = add(bt, 9);
    //bt = remove_node(bt, 2);
    bt = add(bt, 12);

    preOrder(bt);
    printf("\n");
    inOrder(bt);
    printf("\n");
    posOrder(bt);
    printf("\n");
    return 0;
}

BT *create_empty_binary_tree()
{
    return NULL;
}

BT *init_bt(int item, BT *left, BT *right)
{
    BT *bt = (BT *)malloc(sizeof(BT));

    bt->item = item;
    bt->right = right;
    bt->left = left;
    bt->h = 1;

    return bt;
}

BT *search(BT *bt, int item)
{
    if ((bt == NULL) || (bt->item == item))
        return bt;

    else if (bt->item > item)
    {
        return search(bt->left, item);
    }
    else
    {
        return search(bt->right, item);
    }
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
        inOrder(bt->left);
        inOrder(bt->right);
    }
}

void posOrder(BT *bt)
{
    if (!is_empty(bt))
    {
        inOrder(bt->left);
        inOrder(bt->right);
        printf("%d ", bt->item);
    }
}

BT *add(BT *bt, int item)
{
    if (is_empty(bt)){
        bt = init_bt(item, NULL, NULL);
        return bt;
    }
    else if (bt->item > item)
        bt->left = add(bt->left, item);

    else if(bt->item < item)
        bt->right = add(bt->right, item);

    else{
        return bt;
    }

    bt->h = h(bt);
    int balance = balance_factor(bt);

    if (balance > 1 && item < bt->left->item)
    {
         return rotate_right(bt);
    }

    if (balance < -1 && item > bt->right->item)
    {
        return rotate_left(bt);
    }

    if (balance > 1 && item > bt->left->item)
    {
        bt->left = rotate_left(bt->left);
        return rotate_right(bt);
    }

    if (balance < -1 && item < bt->right->item)
    {
        bt->right = rotate_right(bt->right);
        return rotate_left(bt);
    }

    return bt;
}

BT* min(BT *root)
{
	BT *current = root;

	while(current->left != NULL)
    {
		current = current->left;
	}

	return current;
}

BT* remove_node(BT *root, int item)
{
    if(is_empty(root))
    {
		return root;
	}
	if(root->item > item)
    {
		root->left = remove_node(root->left, item);
	}
	else if(root->item < item)
    {
		root->right = remove_node(root->right, item);
	}
	else{
		if(root->left == NULL)
        {
			BT *aux = root->right;
			free(root);
			return aux;
		}
		else if(root->right == NULL)
        {
			BT *aux = root->left;
			free(root);
			return aux;
		}

		BT *aux = min(root->right);
		root->item = aux->item;
		root->right = remove_node(root->right, aux->item);
	}

	if(is_empty(root))
    {
		return root;
	}

	root->h = h(root);
    int balance = balance_factor(root);

    // Left Left
	if(balance > 1 && balance_factor(root->left) >= 0)
    {
		return rotate_right(root);
	}
	// Right Right
	if(balance < -1 && balance_factor(root->right) <= 0)
    {
		return rotate_left(root);
	}
	// Left Right
	if(balance > 1 && balance_factor(root->left) < 0)
	{
		root->left =  rotate_left(root->left);
		return rotate_right(root);
	}
	// Right Left
	if (balance < -1 && balance_factor(root->right) > 0)
    {
		root->right = rotate_right(root->right);
		return rotate_left(root);
	}

	return root;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int h(BT *bt)
{
    if (bt == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(h(bt->left), h(bt->right));
    }
}

int is_balanced(BT *bt)
{
    int bf = h(bt->left) - h(bt->right);
    return ((-1 < bf) && (bf <= 1));
}

int balance_factor(BT *bt)
{
    if (bt == NULL)
        return 0;

    else if ((bt->left != NULL) && (bt->right != NULL))
    {
        return (h(bt->left) - h(bt->right));
    }
    else if (bt->left != NULL && bt->right == NULL)
    {
        return (1 + h(bt->left));
    }
    else
    {
        return (h(bt->right) - 1);
    }
}

BT *rotate_left(BT *bt)
{
    BT *subtree = bt->right;
    BT *left_subtree = subtree->left;

    subtree->left = bt;
    bt->right = left_subtree;

    bt->h = max(h(bt->left), h(bt->right)) + 1;
    subtree->h = max(h(subtree->left), h(subtree->right)) + 1;

    return subtree;
}

BT *rotate_right(BT *bt)
{
    BT *subtree = bt->left;
    BT *right_subtree = subtree->right;

    subtree->right = bt;
    bt->left = right_subtree;

    bt->h = max(h(bt->left), h(bt->right)) + 1;
    subtree->h = max(h(subtree->left), h(subtree->right)) + 1;
}