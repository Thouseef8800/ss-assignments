/**
Name:q22.c
Author:Thouseef
Description:Program to  open a file, call fork, and then write to the file by both the child as well as the
parent processes
Date:August 29th 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("Q22.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Fail");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        const char *child = "Child writing into the file.\n";
        write(fd, child, strlen(child));
    } else {
        const char *parent = "Parent writing into the file.\n";
        write(fd, parent, strlen(parent));
    }

    close(fd);
    return 0;
}
/**Output:
Parent writing into the file.
Child writing into the file.
**/
