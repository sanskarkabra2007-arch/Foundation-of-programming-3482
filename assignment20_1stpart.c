#include <stdio.h>
void swapByValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("After swapping without pointers (inside function): a = %d, b = %d\n", a, b);
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    swapByValue(num1, num2);
    return 0;
}
