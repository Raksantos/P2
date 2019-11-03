#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Bubble Sort

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

//Insertion sort

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

//Selection Sort

void selectionSort(int *array, int size_array)
{
    int i, j, small, change;
    for(i = 0; i < size_array; i++){
        small = i;
        for(j = i + 1; j < size_array; j++){
            if(array[j] < array[small]){
                small = j;
            }
        }
        if(i != small){
            swap(&array[i], &array[small]);
        }
    }
}

//Merge Sort

void merge(int *array, int begin, int middle, int end)
{
    int *temp, p1, p2, size, i, j, k;
    int end1 = 0, end2 = 0;

    size = end - begin + 1;
    p1 = begin;
    p2 = middle+1;

    temp = (int *) malloc(size*sizeof(int));
    
    if(temp != NULL){
        for(i = 0; i < size; i++){
            if(!end1 && !end2){
                if(array[p1] < array[p2]){
                    temp[i] = array[p1];
                    p1++;
                }
                else{
                    temp[i] = array[p2];
                    p2++;
                }
                if(p1 > middle) end1 = 1;
                if(p2 > end) end2 = 1;
            }
            else{
                if(!end1){
                    temp[i] = array[p1];
                    p1++;
                } 
                else{
                    temp[i] = array[p2];
                    p2++;
                }
            }
        }
        for(j = 0, k = begin; j < size; j++, k++){
            array[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *array, int begin, int end)
{
    int middle;
    if(begin < end){
        middle = floor((begin + end)/2);
        mergeSort(array, begin, middle);
        mergeSort(array, middle+1, end);
        merge(array, begin, middle, end);
    }
}

int main()
{
    int array[10] = {10, 7, 9, 8, 3, 6, 4, 5, 2, 1}, i;
    bubbleSort(0, array, 10);
    printf("----- Bubble Sort -----\n");
    for(i = 0; i < 10; i++){
        printf("Posicao %d: %d\n", i, array[i]);
    }

    int array2[10] = {10, 7, 9, 8, 3, 6, 4, 5, 2, 1};
    insertionSort(array2, 10);
    printf("----- Insertion Sort -----\n");
    for(i = 0; i < 10; i++){
        printf("Posicao %d: %d\n", i, array2[i]);
    }

    int array3[10] = {8, 10, 2, 1, 7, 6, 4, 5, 9, 3};
    selectionSort(array3, 10);
    printf("----- Selection Sort -----\n");
    for(i = 0; i < 10; i++){
        printf("Posicao %d: %d\n", i, array3[i]);
    }

    int array4[15] = {8, 10, 2, 1, 7, 6, 4, 5, 9, 3, 15, 14, 13, 12, 11};
    mergeSort(array4, 0, 14);
    printf("----- Merge Sort -----\n");
    for(i = 0; i < 15; i++){
        printf("Posicao %d: %d\n", i, array4[i]);
    }
    return 0;
}