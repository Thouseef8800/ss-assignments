/**
Name:q7.c
Author:Thouseef
Description:Program to copy file1 into file2
Date:25th August 2024
**/
#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char ch;

    sourceFile = fopen("Q7a.txt", "r");
    if (sourceFile == NULL) {
        printf("Cannot open Q7a.txt.\n");
        return 1;
    }

    destinationFile = fopen("Q7b.txt", "w");
    if (destinationFile == NULL) {
        printf("Cannot open Q7b.txt.\n");
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
/**Output:
File copied successfully.
**/
