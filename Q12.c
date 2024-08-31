/**
Name:q12.c
Author:Thouseef
Description:Program to find out the opening mode of a file.
Date:August 29th 2024
**/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, mode;
    char *filename = "Q12.txt";

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    mode = fcntl(fd, F_GETFL);
    close(fd);

    printf("Opening mode of %s: ", filename);
    if (mode & O_RDONLY) {
        printf("r");
    }
    if (mode & O_WRONLY) {
        printf("w");
    }
    if (mode & O_RDWR) {
        printf("r+");
    }
    if (mode & O_APPEND) {
        printf("a");
    }
    if (mode & O_CREAT) {
        printf("x");
    }
    printf("\n");

    return 0;
}
/** Output:File is opened in read-write mode.
O_APPEND flag is set.
**/
