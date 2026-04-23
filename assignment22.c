#include <stdio.h>
#include <string.h>
int main() {
    char str1[100], str2[100], temp[100];
    int choice;

    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    while(1) {
        printf("\n*** MENU ***\n");
        printf("1. Calculate Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Length of first string: %zu\n", strlen(str1));
                printf("Length of second string: %zu\n", strlen(str2));
                break;
            case 2:
                strcpy(temp, str2);
                printf("String 2 copied to a temporary string: %s\n", temp);
                break;
            case 3:
                printf("Original strings will be concatenated.\n");
                strcat(str1 , str2);
                printf("Concatenated string: %s \n",  str1);
                break;
            case 4:
                if (strcmp(str1, str2) == 0) {
                    printf("Strings are equal.\n");
                } else {
                    printf("Strings are not equal.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}
