//
// Created by Alexy Da Silva on 30/10/2024.
//

#include <stdbool.h>
#include <stdio.h>

//////////////////////////////////////////
/////////////  TP0  //////////////////////
//////////////////////////////////////////

////////////////// 1 ////////////////////////


// La somme de n éléments d’un tableau itérative
int sumIterative(const int arr[], const int arrayLength) {
    int sum = 0;
    for (int i = 0; i < arrayLength; i++) {
        sum += arr[i];
    }
    return sum;
}

// La somme de n éléments d’un tableau récursive
int sumRecursive(int arr[], const int arrayLength) {
    if (arrayLength == 0) {
        return 0;
    }
    return arr[arrayLength - 1] + sumRecursive(arr, arrayLength - 1);
}

////////////////// 2 ////////////////////////


// factorial => par l'approche itérative
int factorialIterative(const int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// factorial => par l'approche récursive
int factorialRecursive(const int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}


////////////////// 3 ////////////////////////

// Algorithmes de recherche linéaire
int linearSearch(const int arr[], const int arrayLength, const int key) {
    for (int i = 0; i < arrayLength; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Algorithmes de recherche recherche par dichotomie itérative
int binarySearchIterative(const int arr[], const int arrayLength, const int key) {
    int left = 0;
    int right = arrayLength - 1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Algorithmes de recherche recherche par dichotomie recursive
int binarySearchRecursive(int arr[], const int left, const int right, const int key) {
    if (left <= right) {
        const int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, right, key);
        }
        return binarySearchRecursive(arr, left, mid - 1, key);
    }
    return -1;
}


////////////////// 4 ////////////////////////

// Renverser les éléments du tableau de type int[]
void reverseArray(int arr[], const int arrayLength) {
    for (int i = 0; i < arrayLength / 2; i++) {
        const int temp = arr[i];
        arr[i] = arr[arrayLength - i - 1];
        arr[arrayLength - i - 1] = temp;
    }
}

////////////////// 5 ////////////////////////

// Affichez le nieme élément d'une séquence de Fibonacci
int fibonacci(const int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}


////////////////// 6 ////////////////////////
// Renversez un string et affichez si c'est un palindrome
bool isPalindrome(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

////////////////// 7 ////////////////////////
// Dans un string str, trouvez un autre string substring.

int findSubstring(const char *str, const char *substring) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    int subLength = 0;
    while (substring[subLength] != '\0') {
        subLength++;
    }
    for (int i = 0; i < length; i++) {
        if (str[i] == substring[0]) {
            int j = 0;
            while (j < subLength && str[i + j] == substring[j]) {
                j++;
            }
            if (j == subLength) {
                return i;
            }
        }
    }
    return -1;
}

int main(void) {
    int array1 [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int arrayLength1 = *(&array1 + 1) - array1;

    const int sumInt = sumIterative(array1, arrayLength1);
    printf("Sum of the array iterative is: %d\n", sumInt);

    const int sumIntRec = sumRecursive(array1, arrayLength1);
    printf("Sum of the array recursive is: %d\n", sumIntRec);

    const int factInt = factorialIterative(5);
    printf("Factorial iterative of 5 is: %d\n", factInt);

    const int factIntRec = factorialRecursive(5);
    printf("Factorial recursive of 5 is: %d\n", factIntRec);

    const int linearSearchInt = linearSearch(array1, arrayLength1, 5);
    printf("Linear search of 5 is: %d\n", linearSearchInt);

    const int binarySearchInt = binarySearchIterative(array1, arrayLength1, 5);
    printf("Binary search iterative of 5 is: %d\n", binarySearchInt);

    const int binarySearchIntRec = binarySearchRecursive(array1, 0, arrayLength1 - 1, 5);
    printf("Binary search recursive of 5 is: %d\n", binarySearchIntRec);

    int array2 [] = {22, 33, 5, 66,7};
    const int arrayLength2 = *(&array2 + 1) - array2;

    reverseArray(array2, arrayLength2);
    printf("Reversed array is: ");
    for (int i = 0; i < arrayLength2; i++) {
        printf("%d ", array2[i]);
    }

    const int fib = fibonacci(6);
    printf("\nFibonacci of 5 is: %d\n", fib);

    const bool isPal = isPalindrome("madam");
    printf("Is kayak palindrome: %s\n", isPal ? "true" : "false");

    const bool isPal2 = isPalindrome("sieste");
    printf("Is sieste palindrome: %s\n", isPal2 ? "true" : "false");

    const char str[] = "I am here";
    const char subStr[] = "her";
    const int subStrIndex = findSubstring(str, subStr);
    printf("Substring index is: %d\n", subStrIndex);

    return 0;
}