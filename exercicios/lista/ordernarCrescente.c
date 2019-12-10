#include <stdio.h>
#include <stdlib.h>

struct element{
    int num;
    struct element *next;
};

typedef struct element Element;

typedef struct element* List;

int add_end(List *li, int num)
{
    if(li == NULL) return 0; // se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 0

    no->num = num;//passa os dados
    no->next = NULL;//faz com que o ponteiro aponte para null, já que é o último elemento
    if((*li) == NULL){
        *li = no;//se a lista for vazia ele vai inserir no início
    }
    //se não for uma lista vazia
    else{
        Element *aux = *li;//cria um elemento auxiliar que irá pecorrer a lista, iniciando da cabeça
        while(aux->next != NULL){//enquanto o ponteiro do elemento auxiliar não apontar para null, vai para o próximo
            aux = aux->next; // pecorrendo a lista
        }
        aux->next = no; // aponta o último nó da lisa para o novo último nó
    }
}

int sizeof_list(List* li)
{
    if(li == NULL) return 0;//se a lista não tiver conteudo, está vazia

    int count = 0;
    Element *no = *li;// elemento auxiliar
    while(no != NULL){
        count++;//enquanto o elemento não estiver no final da lista, adiciona mais um ao contador
        no = no->next;//pecorre a lista
    }
    return count;
}

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));//aloca espaço de memória pra lista

    if(li != NULL)//se tiver algum dado na lista
        *li = NULL;//esvazia ela fazendo a atribuição

    return li;//retorna a lista vazia
}

int empty_list(Element *head)
{
    return head->next == NULL ? 1 : 0; //se a lista estiver sem conteúdo ou apontando para nenhum canto, está vazia.
}

void swap_nodes(Element *before, Element *first, Element *second)
{
	Element *temp = second->next;

	before->next = second;

	second->next = first;
	first->next  = temp;
}

int swap_list(Element *head, Element *first, Element *second)
{
	if(head->next != NULL)
	{
		Element* temp = head;

		if(head->next != first)
		{
			while(temp->next != first)
			{
				temp = temp->next;
				if(temp->next == NULL) return 0;
			}
		}
		swap_nodes(temp, first, second);
		return 1;
	}
	return -1;
}

int bubble_sort_iter(Element *head)
{
	int sorted = 0;

	Element* temp = head->next;
	while(temp->next != NULL)
	{
		if(temp == NULL)
		{
			return -1;
		}

		if(temp->num > temp->next->num)
		{	
			int a = swap_list(head, temp, temp->next);
			sorted++;
		}
		else temp = temp->next;
	}
	return sorted;
}

void bubble_sort_list(Element *head, List *li)
{
	if(!empty_list(head))
		while(bubble_sort_iter(head) > 0);
    

    Element *aux = head;

    while(aux->next != NULL){
        aux = aux->next;
    }
    if(head->num > aux->num){
        aux->next = head;

        *li = head->next;
        head->next = NULL;
    }
}

int main()
{
    List *li = init_list();

    int x;
    while(scanf("%d", &x) != EOF){
        add_end(li, x);
    }

    Element *no = *li;
    
    bubble_sort_list(no, li);

    no = *li;

    while(no != NULL){
        printf("%d ", no->num);
        no = no->next;
    }

    return 0;
}