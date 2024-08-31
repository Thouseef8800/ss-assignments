/**
Name:q11.c
Author:Thouseef
Description:Program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
Date:August 27th 2024 
**/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, fd_dup, fd_dup2, fd_fcntl;
    ssize_t bytes_written;
    const char *text = "Appended text\n";

    fd = open("Q11.txt", O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error duplicating file descriptor using dup");
        close(fd);
        return 1;
    }

    fd_dup2 = dup2(fd, 100);
    if (fd_dup2 == -1) {
        perror("Error duplicating file descriptor using dup2");
        close(fd);
        close(fd_dup);
        return 1;
    }

    fd_fcntl = fcntl(fd, F_DUPFD, 200);
    if (fd_fcntl == -1) {
        perror("Error duplicating file descriptor using fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        return 1;
    }

    bytes_written = write(fd, text, 14);
    if (bytes_written == -1) {
        perror("Error writing to file with original descriptor");
    }

    bytes_written = write(fd_dup, text, 14);
    if (bytes_written == -1) {
        perror("Error writing to file with dup descriptor");
    }

    bytes_written = write(fd_dup2, text, 14);
    if (bytes_written == -1) {
        perror("Error writing to file with dup2 descriptor");
    }

    bytes_written = write(fd_fcntl, text, 14);
    if (bytes_written == -1) {
        perror("Error writing to file with fcntl descriptor");
    }

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    return 0;
}
