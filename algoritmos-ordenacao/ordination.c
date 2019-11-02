#include <stdio.h>
#include <stdlib.h>

void swap(int *position1, int *position2)
{
    int aux = *position1;
    *position1 = *position2;
    *position2 = aux;
}

void bubbleSort(int i, int *array, int size_array)
{
    if(size_array > 0){
    if (i < size_array - 1){
      if(array[i] > array[i + 1]){
        swap(&array[i], &array[i + 1]);
        bubbleSort(i+1, array, size_array);
      }
      else{
        bubbleSort(i+1, array, size_array);
      }
    }
    else{
      bubbleSort(0, array, size_array-1);
    }
  }
}

void insertionSort(int *array, int size_array)
{
    int i, j, aux;
    for(i = 0; i < size_array; i++){
        aux = array[i];
        for(j = i; (j > 0) && (aux < array[j - 1]); j--){
            array[j] = array[j - 1];
        }
        array[j] = aux;
    }
}

int main()
{
    int array[10] = {10, 7, 9, 8, 3, 6, 4, 5, 2, 1}, i;
    bubbleSort(0, array, 10);
    for(i = 0; i < 10; i++){
        printf("Posicao %d: %d\n", i, array[i]);
    }

    int array2[10] = {10, 7, 9, 8, 3, 6, 4, 5, 2, 1};
    insertionSort(array2, 10);
    for(i = 0; i < 10; i++){
        printf("Posicao %d: %d\n", i, array2[i]);
    }
    return 0;
}