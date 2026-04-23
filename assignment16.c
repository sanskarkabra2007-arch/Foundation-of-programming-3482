#include <stdio.h>

int main() {
    int N;
    int arr[100];
    int even_arr[100];
    int odd_arr[100];
    int even_count = 0;
    int odd_count = 0;
    int i;

    // Input the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &N);

    // Input the integers
    printf("Enter integers: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Partition the numbers into even and odd arrays
    for (i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            even_arr[even_count] = arr[i];
            even_count++;
        } else {
            odd_arr[odd_count] = arr[i];
            odd_count++;
        }
    }

    // Display the even numbers
    printf("Even numbers are: ");
    for (i = 0; i < even_count; i++) {
        printf("%d ", even_arr[i]);
    }
    printf("\n");

    // Display the odd numbers
    printf("Odd numbers are: ");
    for (i = 0; i < odd_count; i++) {
        printf("%d ", odd_arr[i]);
    }
    printf("\n");

    return 0;
}
