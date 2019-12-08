#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct element{
    int num;
    struct element *next;
};

typedef struct element Element;

typedef struct element* List;

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

void bubble_sort_list(Element *head)
{
	if(!empty_list(head))
		while(bubble_sort_iter(head) > 0);
}

void swap(int *position1, int *position2)
{
    int aux = *position1;
    *position1 = *position2;
    *position2 = aux;
}

List* init_list()
{
    List *li = (List*) malloc(sizeof(List));//aloca espaço de memória pra lista

    if(li != NULL)//se tiver algum dado na lista
        *li = NULL;//esvazia ela fazendo a atribuição

    return li;//retorna a lista vazia
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

int add_end(List *li, int i)
{
    if(li == NULL) return 0; // se a lista não existir, retorna erro
    Element *no = (Element*) malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if(no == NULL) return 0; //se ouver problemas na alocação, retorna 0

    no->num = i;//passa os dados
    no->next = NULL;//faz com que o ponteiro aponte para null, já que é o último elemento
    if((*li) == NULL){
        *li = no;//se a lista for vazia ele vai inserir no início
    }
    //se não for uma lista vazia
    else{
        int i = 1;
        Element *aux = *li;//cria um elemento auxiliar que irá pecorrer a lista, iniciando da cabeça
        while(aux->next != NULL){//enquanto o ponteiro do elemento auxiliar não apontar para null, vai para o próximo
            aux = aux->next; // pecorrendo a lista
            i++;
        }
        aux->next = no; // aponta o último nó da lisa para o novo último nó
    }
}

int linear_search(List* li, int element)
{
    Element *no = *li;
    while(no != NULL){//enquanto o i n�o tiver o tamanho do list, isto �, o tamanho do elemento, adiciona 1
        if(element == no->num){
            return 1;//encontrou o elemento
        }//se e encontrar algu�m em alguma posi��o
        no = no->next;
    }
    return 0;//se n�o encontrar ningu�m, retorna falso
}

int main()
{
    List *li1 = init_list();
    List *li2 = init_list();
    List *list_aux = init_list();
    int i, aux = 0;

    for(i = 0; i < 20; i++){
        scanf("%d", &aux);
        add_end(li1, aux);
    }

    for(i = 0; i < 20; i++){
        scanf("%d", &aux);
        add_end(li2, aux);
    }

    Element *no = *li2;

    aux = 0;

    while(no != NULL){
        if(linear_search(li1, no->num)){
            if(!linear_search(list_aux, no->num)){
                add_end(list_aux, no->num);   
            }
        }
        no = no->next;
    }
    
    no = *list_aux;

    bubble_sort_list(no);

    if(empty_list(no)){
        printf("VAZIO\n");
    }else{
        while(no != NULL){
            printf("%d\n", no->num);
            no = no->next;
        }
    }

    return 0;
}