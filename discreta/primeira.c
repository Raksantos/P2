#include <stdio.h>
#include <math.h>

int primo(int x);

int main()
{
    int x;
    scanf("%d", &x);

    if(primo(x)){
        printf("É primo\n");
    }else{
        printf("Não é primo\n");
    }
    
    return 0;
}

int primo(int x)
{
    int i;

    for(i = x - 1; i >= sqrt(x); i--){
        if(x % i == 0){
            return 0;
        }
    }

    return 1;
}