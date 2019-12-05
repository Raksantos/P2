#include <stdio.h>
#include <string.h>

int main()
{
    char texto[256];

    scanf("%[^\n]s", texto);

    printf("%s\n", texto);
    return 0;
}