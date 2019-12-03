#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *position1, int *position2)
{
    int aux = *position1;
    *position1 = *position2;
    *position2 = aux;
}


int partitionate(int *array, int begin, int end)
{
    int left, right, pivot, aux;
    left = begin;
    right = end;
    pivot = array[begin];
    while(left < right){
        while(array[left] <= pivot){
            left++;
        }
        while(array[right] > pivot){
            right--;
        }
        if(left < right){
            swap(&array[left], &array[right]);
        }
    }
    array[begin] = array[right];
    array[right] = pivot;
    return right;
}

void quickSort(int *array, int begin, int end)
{
    int pivot;
    if (begin < end){
        pivot = partitionate(array, begin, end);
        quickSort(array, begin, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

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

int main()
{
    int array1[20], array2[20], array3[20], i, j=0, aux;

    for(i = 0; i < 20; i++){
        scanf("%d", &array1[i]);
    }

    for(i = 0; i < 20; i++){
        scanf("%d", &array2[i]);
    }

    for(i = 0; i < 20; i++){
        if(linear_search(array1, 20, array2[i]) != -1){
            if(linear_search(array3, j, array2[i]) == -1){
                array3[j] = array2[i];
                j++;
            }
        }
    }
    if(j == 0){
        printf("VAZIO\n");
    }else{
        quickSort(array3, 0, j - 1);

        for(i = 0; i < j; i++){
            printf("%d\n", array3[i]);
        }
    }

    return 0;
}