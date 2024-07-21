Pointers

1. Write a function to swap values of two in variables of calling function. (TSRS)
2. Write a function to swap strings of two char arrays of calling functions. (TSRS)
3. Write a function to sort an array of int type values. [ void sort(int *ptr,int size); ]
4. Write a program in C to demonstrate how to handle the pointers in the program.
5. Write a program to find the maximum number between two numbers using a pointer
6. Write a program to calculate the length of the string using a pointer
7. Write a program to count the number of vowels and consonants in a string using a
pointer.
8. Write a program to compute the sum of all elements in an array using pointers.
9. Write a program to print the elements of an array in reverse order.
10. Write a program to print a string in reverse using a pointer.

Solution:-

1. #include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}

2. #include <stdio.h>
#include <string.h>

void swapStrings(char *str1, char *str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);
    swapStrings(str1, str2);
    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);
    return 0;
}

3. #include <stdio.h>

void sort(int *ptr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(ptr + i) > *(ptr + j)) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

4. #include <stdio.h>

int main() {
    int var = 10;
    int *ptr = &var;

    printf("Value of var: %d\n", var);
    printf("Address of var: %p\n", &var);
    printf("Value stored in ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    *ptr = 20;
    printf("New value of var: %d\n", var);

    return 0;
}

5. #include <stdio.h>

int max(int *a, int *b) {
    return (*a > *b) ? *a : *b;
}

int main() {
    int x = 10, y = 20;
    printf("Maximum number between %d and %d is %d\n", x, y, max(&x, &y));
    return 0;
}

6. #include <stdio.h>

int stringLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char str[] = "Hello, World!";
    printf("Length of the string \"%s\" is %d\n", str, stringLength(str));
    return 0;
}

7. #include <stdio.h>
#include <ctype.h>

void countVowelsAndConsonants(char *str, int *vowels, int *consonants) {
    *vowels = *consonants = 0;
    while (*str != '\0') {
        char ch = tolower(*str);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            (*vowels)++;
        } else if (isalpha(ch)) {
            (*consonants)++;
        }
        str++;
    }
}

int main() {
    char str[] = "Hello, World!";
    int vowels, consonants;
    countVowelsAndConsonants(str, &vowels, &consonants);
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    return 0;
}

8. #include <stdio.h>

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of array elements: %d\n", sumArray(arr, size));
    return 0;
}

9. #include <stdio.h>

void printArrayInReverse(int *arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array in reverse order: ");
    printArrayInReverse(arr, size);
    return 0;
}

10. #include <stdio.h>
#include <string.h>

void printStringInReverse(char *str) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", *(str + i));
    }
    printf("\n");
}

int main() {
    char str[] = "Hello, World!";
    printf("String in reverse: ");
    printStringInReverse(str);
    return 0;
}
