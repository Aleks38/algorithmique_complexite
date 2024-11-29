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
        int minIndex = i;
        for (int j = i + 1; j < arrayLength; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            const int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

/////////////// 3 /////////////////////
/// Tri à fusion
void merge(int arr[], const int left, const int mid, const int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], const int left, const int right) {
    if (left < right) {
        const int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/////////////// 4 /////////////////////
/// Tri rapide
///

int partition(int *tab, int left, int right);

void quickSort(int tab[], const int left, const int right) {
    if (left < right) {
        const int pivot = partition(tab, left, right);
        quickSort(tab, left, pivot - 1);
        quickSort(tab, pivot + 1, right);
    }
}

int partition(int tab[], const int left, const int right) {
    const int pivot = tab[right];
    int i = (left - 1);
    for (int j = left; j <= right - 1; j++) {
        if (tab[j] < pivot) {
            i++;
            const int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }
    const int temp = tab[i + 1];
    tab[i + 1] = tab[right];
    tab[right] = temp;
    return (i + 1);
}


int main(void) {
    int arrBubble[] = {1, 3, 5, 7, 8, 9, 2};
    const int arrayLengthBubble = *(&arrBubble + 1) - arrBubble;

    bubbleSort(arrBubble, arrayLengthBubble);
    printf("\nBubble sort array is: ");
    for (int i = 0; i < arrayLengthBubble; i++) {
        printf("%d ", arrBubble[i]);
    }

    int arrSelection[] = {1, 3, 5, 7, 8, 9, 2};
    const int arrayLengthSelection = *(&arrSelection + 1) - arrSelection;

    selectionSort(arrSelection, arrayLengthSelection);
    printf("\nSelection sort array is: ");
    for (int i = 0; i < arrayLengthSelection; i++) {
        printf("%d ", arrSelection[i]);
    }

    int arrMerge[] = {1, 3, 5, 7, 8, 9, 2};
    const int arrayLengthMerge = *(&arrMerge + 1) - arrMerge;

    quickSort(arrMerge, 0, arrayLengthMerge - 1);
    printf("\nMerge sort array is: ");
    for (int i = 0; i < arrayLengthMerge; i++) {
        printf("%d ", arrMerge[i]);
    }


    int arrQuick[] = {1, 3, 5, 7, 8, 9, 2};
    const int arrayLengthQuick = *(&arrQuick + 1) - arrQuick;

    quickSort(arrQuick, 0, arrayLengthQuick - 1);
    printf("\nQuick sort array is: ");
    for (int i = 0; i < arrayLengthQuick; i++) {
        printf("%d ", arrQuick[i]);
    }

    return 0;
}
