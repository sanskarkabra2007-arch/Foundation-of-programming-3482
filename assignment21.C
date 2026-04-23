#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourcePtr, *destPtr;
    char ch;
    sourcePtr = fopen("source.txt", "r");
    if (sourcePtr == NULL) {
        printf("Error: Cannot open source file.\n");
        exit(1);
    }
    destPtr = fopen("destination.txt", "w");
    if (destPtr == NULL) {
        printf("Error: Cannot open or create destination file.\n");
        fclose(sourcePtr);
        exit(1);
    }
    while ((ch = fgetc(sourcePtr)) != EOF) {
        fputc(ch, destPtr);
    }
    printf("File copied successfully.\n");
    fclose(sourcePtr);
    fclose(destPtr);
    return 0;
}
