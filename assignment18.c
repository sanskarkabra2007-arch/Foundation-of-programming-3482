#include <stdio.h>
int main() {
    char str1[100], str2[100], rev[100];
    int i, j, length = 0, flag = 1, found = 0;
    printf("Enter a string: ");
    scanf("%s", str1);
    printf("Enter another string for equality check: ");
    scanf("%s", str2);
    for(i = 0; str1[i] != '\0'; i++) {
        length++;
    }
    printf("Length of string = %d\n", length);
    for(i = 0; i < length; i++) {
        rev[i] = str1[length - i - 1];
    }
    rev[i] = '\0';
    printf("Reversed string = %s\n", rev);
    for(i = 0; i < length; i++) {
        if(str1[i] != rev[i]) {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
        printf("The string is a Palindrome\n");
    else
        printf("The string is not a Palindrome\n");
    i = 0;
    flag = 1;
    while(str1[i] != '\0' || str2[i] != '\0') {
        if(str1[i] != str2[i]) {
            flag = 0;
            break;
        }
        i++;
    }
    if(flag == 1)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n");
    for(i = 0; str1[i] != '\0'; i++) {
        j = 0;
        while(str2[j] != '\0' && str1[i + j] == str2[j]) {
            j++;
        }
        if(str2[j] == '\0') {
            found = 1;
            break;
        }
    }
    if(found == 1)
        printf("Substring found in main string\n");
    else
        printf("Substring not found\n");
    return 0;
}
