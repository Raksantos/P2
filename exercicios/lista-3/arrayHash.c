#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void verifica(int l)
{
    int i, resultado = 0, j = 0;

    for(i = 0; i < l; i++)
    {
        char string[10000];
        fgets(string, 10000, stdin);
        fflush(stdin);
        //printf("Valor da string: %s", string);
        while(string[j] != '\n')
        {
            resultado += (((int)string[j]) - 65);
            resultado += j;
            resultado += i;
            j++;
        }
        j = 0;
        //printf("Fim string: %d\n", resultado);
    }

    printf("%d\n", resultado);
}

int main()
{
    int n, i;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        int l;
        scanf("%d", &l);
        getchar();
        verifica(l);
    }

    return 0;
}