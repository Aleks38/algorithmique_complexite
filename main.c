#include <stdio.h>
#include <stdlib.h>

int maxNum (int arr[], int arrayLength) {
    int max = arr[0];
    for (int i = 1; i < arrayLength; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int factorielle (int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

char * reverseString (char * str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    char * reversedStr = (char *)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        reversedStr[i] = str[length - i - 1];
    }
    return reversedStr;
}

int main(void)
{
    printf("Hello, World!\n");

    int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 150};
    const int arrayLength = *(&array + 1) - array;

    const int maxNumInt = maxNum(array, arrayLength);
    printf("Max number is: %d\n", maxNumInt);

    const int fact = factorielle(5);
    printf("Factorielle of 5 is: %d\n", fact);

    char str[] = "Hello World!";
    char * reversedStr = reverseString(str);
    printf("Reversed string is: %s\n", reversedStr);

    free(reversedStr);
    return 0;
}
