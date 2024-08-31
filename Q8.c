/**
Name:q8.c
Author:Thouseef
DescriptionL:Program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date:22nd August 2024
**/
#include <stdio.h>

int main() {
    FILE *file = fopen("Q8.txt", "r");

    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
