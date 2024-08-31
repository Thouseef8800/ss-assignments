/**
Name:q11.c
Author:Thouseef
Description:Program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
Date:August 27th 2024 
**/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void check_file(const char *filename) {
    char buffer[1024];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("File content:\n");
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
    close(fd);
}

int main() {
    const char *filename = "Q11.txt";
    const char *text = "Program to use dup and dup2.\n";
    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (write(fd, text, strlen(text)) < 0) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    int fd_dup = dup(fd);
    if (fd_dup < 0) {
        perror("dup");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if (write(fd_dup, "Added with dup", 15) < 0) {
        perror("write dup");
        close(fd);
        close(fd_dup);
        exit(EXIT_FAILURE);
    }
    int fd_dup2 = dup2(fd, 100);
    if (fd_dup2 < 0) {
        perror("dup2");
        close(fd);
        close(fd_dup);
        exit(EXIT_FAILURE);
    }
    if (write(fd_dup2, "Added with dup2\n", 17) < 0) {
        perror("write dup2");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        exit(EXIT_FAILURE);
    }
    int fd_fcntl = fcntl(fd, F_DUPFD, 0);
    if (fd_fcntl < 0) {
        perror("fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        exit(EXIT_FAILURE);
    }
    if (write(fd_fcntl, "Added with fcntl\n", 18) < 0) {
        perror("write fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        close(fd_fcntl);
        exit(EXIT_FAILURE);
    }
    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);
    
    check_file(filename);
    
    return 0;
}
/** Output:File content:
MT2024159
Hi 
thouseef ahmed 
	
Appended text
Appended text
Appended text
Appended text
Appended text
Appended text
Appended text
Appended text
Program to use dup and dup2.

**/
