#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element_list{
    int num;
    struct element_list *next;
};

typedef struct element_list Element;

typedef struct element_list* List;

struct element{
    struct element *next;
    struct element_list** list;
};

typedef struct element* Stack;

typedef struct element ElementStack;

Stack* init_stack()
{
    Stack *pi = (Stack*) malloc(sizeof(Stack));

    if(pi != NULL){
        *pi = NULL;
    }

    return pi;
}

int size_stack(Stack* pi)
{
    if(pi == NULL) return 0;
    int cont = 0;
    ElementStack *no = *pi;
    while(no != NULL){
        no = no->next;
        cont++;
    }

    return cont;
}

int empty_stack(Stack* pi)
{
    return *pi == NULL ? 1 : 0;
}

int push(Stack* pi)
{
    if(pi == NULL) return 0;
    ElementStack *no = (ElementStack*) malloc(sizeof(ElementStack));

    if(no == NULL) return 0;

    if((*pi) == NULL){
        no->next = NULL;
        *pi = no;
    }

    else{
        no->next = *pi;
        *pi = no;
    }

    no->list = NULL;

    return 1;
}

void free_list(List* li)
{
    if(li != NULL){//se a lista não estiver vazia
        Element *no = *li;//cria elemento auxiliar

        printf("%d", no->num);

        *li = (*li)->next;

        free(no);

        while((*li) != NULL){//enquanto a lista não estiver vazia
            no = *li;//auxilar recebe o valor do nó
            printf(" %d", no->num);
            *li = (*li)->next;//cabeça da lista apontara para o próximo elemento
            free(no);//libera os dados do nó
        }
        printf("\n");
        free(li);//ao acabar de pecorrer a lista, libera a memória da lista
    }
}

int pop(Stack* pi)
{
    if(pi == NULL) return 0;

    if(empty_stack(pi)){
        printf("EMPTY STACK\n");
        return 0;
    }

    ElementStack *no = *pi;
    
    List *li = no->list;

    free_list(li);

    *pi = no->next;

    free(no);

    return 1;
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

int add_end(List *li, int num)
{
    if (li == NULL)return 0;

    Element *no = (Element *)malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if (no == NULL)
        return 0; //se ouver problemas na alocação, retorna 0

    no->num = num; //passa os dados
    no->next = NULL;    //faz com que o ponteiro aponte para null, já que é o último elemento
    if ((*li) == NULL)
    {
        *li = no; //se a lista for vazia ele vai inserir no início
    }
    //se não for uma lista vazia
    else
    {
        Element *aux = *li; //cria um elemento auxiliar que irá pecorrer a lista, iniciando da cabeça
        while (aux->next != NULL)
        {                    //enquanto o ponteiro do elemento auxiliar não apontar para null, vai para o próximo
            aux = aux->next; // pecorrendo a lista
        }
        aux->next = no; // aponta o último nó da lisa para o novo último nó
    }
}

int remove_beginning(List* li)
{
    if(li == NULL || (*li) == NULL){//se lista não existir ou lista vazia, retorna 0
        return 0;
    }
    else{
        Element *no = *li;//cria elemento auxiliar que vai receber a lista
        *li = no->next;//faz a cabeça apontar para o segundo elemento da lista
        free(no);//remove o primeiro elemento
        return 1;
    }
}

void nova_lista(Stack *pi)
{
    int i, entrNum;

    push(pi);

    List *li = init_list();

    //fgets(entrada, 500, stdin);

    char entrada = ' ';

    while(entrada != '\n')
    {
        scanf("%d", &entrNum);
        add_end(li, entrNum);
        scanf("%c", &entrada);
    }

    (*pi)->list = li;
}

void recursiva(Stack* pi)
{
    char entrada[10];
    scanf("%[^\n]s", entrada);
    getchar();

    int aux = strlen(entrada);

    if(entrada[0] == 'P' && entrada[1] == 'U' && entrada[2] == 'S' && entrada[3] == 'H' && aux == 4){
        nova_lista(pi);
        recursiva(pi);
    }else if(entrada[0] == 'P' && entrada[1] == 'O' && entrada[2] == 'P' && aux == 3){
        pop(pi);
        recursiva(pi);
    }
}

int main()
{
    Stack* pi = init_stack();
    recursiva(pi);
    return 0;
}
