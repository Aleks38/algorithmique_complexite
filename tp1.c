//
// Created by Alexy Da Silva on 30/10/2024.
//
#include <stdio.h>

//////////////////////////////////////////
/////////////  TP1  //////////////////////
//////////////////////////////////////////

//////////////// 1 /////////////////////
/// Tri à bulles
void bubbleSort(int arr[], const int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        for (int j = 0; j < arrayLength - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/////////////// 2 /////////////////////
/// Tri par sélection
void selectionSort(int arr[], const int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        int min = arr[i];
        for (int j = i + 1; j < arrayLength; j++) {
            if (arr[j] < min) {
                min = arr[j];
                const int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/////////////// 3 /////////////////////
/// Tri à fusion
void mergeSort(int arr[], const int arrayLength) {
}

/////////////// 4 /////////////////////
/// Tri rapide
void quickSort(int tab[], int tmp[]) {
}


int main(void) {
    int arr[] = {1, 3, 5, 7, 8, 9, 2};
    const int arrayLength = *(&arr + 1) - arr;

    // bubbleSort(arr, arrayLength);
    // printf("Bubble sort array is: ");
    // for (int i = 0; i < arrayLength; i++) {
    //     printf("%d ", arr[i]);
    // }

    selectionSort(arr, arrayLength);
    printf("\nSelection sort array is: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}
