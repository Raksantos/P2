#include <stdio.h>
#include <stdlib.h>
#include <search.h>

int linear_search(int *array, int size_array, int element)
{
    int i;//contador de posições
    for(i = 0; i < size_array; i++){//enquanto o i não tiver o tamanho do array, isto é, o tamanho do elemento, adiciona 1
        if(element == array[i]){
            return i;//retorna a posição encontrada
        }//se e encontrar alguém em alguma posição
    }
    return -1;//se não encontrar ninguém, retorna uma posição inválida
}

int ordered_search(int *array, int size_array, int element){
    int i;//cria contador 
    for(i = 0; i<size_array; i++){//enquanto não chegar no final do array, retorna 0
        if(element == array[i]){//se encontrar um elemento com o valor igual no array
            return i;//retorna a posição
        }
        else{//caso não encontre nessa interação
            if(element < array[i]){//verifica se o elemento desejado é menor, pois como está ordenado, caso isso aconteça o elemento não está presente na lista
            //tornando assim a busca mais eficiente e encerrando o processo em menos passos
                return -1;//retorna que o elemento não foi encontrado
            }
        }
    }
    return -1;//retorna que o elemento não foi encontrado
}

int binary_search(int *array, int size_array, int element)
{   
    int i, begin, middle, end;//variáveis auxiliares
    begin = 0;
    end = size_array - 1;
    while(begin <= end){//enquanto o início e o fim não conhecidirem 
        middle = (begin + end)/2;//calcula o novo meio a cada interação
        if(element < array[middle]){//se o elemento tiver valor menor que o elemento no meio do array
            end = middle - 1;//puxa a posição final da busca para uma posição antes do meio atual
        }
        else{
            if(element > array[middle]){//se o elemento tiver valor melhor que o elemento na metade atual do array
                begin = middle + 1;//puxa o início para uma posição depois do meio atual
            }
            else{//se o elemento não for menor nem maior que o elemento encontrado, ele é igual
                return middle;//retorna o meio encontrado que é o elemento
            }
        }
    }
    return -1;//caso o elemento não seja encontrado, retorna que o elemento não foi encontrado
}

int main()
{
    int array1[7] = {23, 4, 67, -8, 54, 90, 21};
    int array2[7] = {-8, 4, 21, 23, 54, 67, 90};

    int linear = linear_search(array1, 7, -8);
    int ordered = ordered_search(array2, 7, 4);
    int binary = binary_search(array2, 7, 90);

    printf("Linear: %d\nOrdenada: %d\nBinaria: %d\n", linear, ordered, binary);
    return 0;
}

