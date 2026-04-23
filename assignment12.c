#include <stdio.h>
int findSmallestCommonDivisor(int num1, int num2) {
    int i;
    int smaller = (num1 < num2) ? num1 : num2;
    for (i = 2; i <= smaller; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            return i;
        }
    }
    return 0;
}
int findGCD(int num1, int num2) {
    int temp;
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;
    while (num2 != 0) {
        temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main() {
    int number1, number2, choice, result;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Find the Smallest Common Divisor (other than 1) and the Greatest Common Divisor (GCD)\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter two positive integers:\n");
                printf("Number 1: ");
                scanf("%d", &number1);
                printf("Number 2: ");
                scanf("%d", &number2);
                result = findSmallestCommonDivisor(number1, number2);
                if (result != 0) {
                    printf("Smallest Common Divisor: %d\n", result);
                } else {
                    printf("No common divisor found (other than 1). The numbers are coprime.\n");
                }
                result = findGCD(number1, number2);
                printf("Greatest Common Divisor (GCD): %d\n", result);
                break;
            case 2:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
