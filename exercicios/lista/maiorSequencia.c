#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    int num;
    struct element *next;
};

typedef struct element Element;

typedef struct element *List;

List *init_list()
{
    List *li = (List *)malloc(sizeof(List)); //aloca espaço de memória pra lista

    if (li != NULL) //se tiver algum dado na lista
        *li = NULL; //esvazia ela fazendo a atribuição

    return li; //retorna a lista vazia
}

int add_end(List *li, char num)
{
    if (li == NULL)
        return 0;                                     // se a lista não existir, retorna erro
    Element *no = (Element *)malloc(sizeof(Element)); //aloca espaço para o novo elemento

    if (no == NULL)
        return 0; //se ouver problemas na alocação, retorna 0

    no->num = (int)num; //passa os dados
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

void free_list(List *li)
{
    if (li != NULL)
    {                //se a lista não estiver vazia
        Element *no; //cria elemento auxiliar
        while ((*li) != NULL)
        {                      //enquanto a lista não estiver vazia
            no = *li;          //auxilar recebe o valor do nó
            *li = (*li)->next; //cabeça da lista apontara para o próximo elemento
            free(no);          //libera os dados do nó
        }
        free(li); //ao acabar de pecorrer a lista, libera a memória da lista
    }
}

void verfica()
{
    char entrada[256];
    int i, j, begin = 0, end = 0, aux_begin = 0, aux_end = 0, diferenca_aux = 0, diferenca = 0;

    fgets(entrada, 256, stdin);

    int aux = strlen(entrada);

    if (entrada[0] == '0' && aux == 1)
    {
        return;
    }

    List *li = init_list();
    for (i = 0; entrada[i] != '\n'; i++)
    {
        add_end(li, entrada[i]);
    }

    Element *no = *li;

    i = 0;
    while (no != NULL)
    {
        if (no->num == 48)
        {
            aux_begin = i;
            Element *aux = no;
            for (j = i; aux->num != 49 && aux->next != NULL; j++)
            {
                aux_end = j;
                aux = aux->next;
            }
            diferenca_aux = aux_end - aux_begin;
            if (diferenca_aux > diferenca)
            {
                diferenca = diferenca_aux;
                begin = aux_begin;
                end = aux_end;
            }
        }
        i++;
        no = no->next;
    }

    printf("%d %d\n", begin, end);
    diferenca = 0;
    begin = 0;
    end = 0;

    free_list(li);
    verfica();
}

int main()
{

    verfica();

    return 0;
}