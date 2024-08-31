/**
Name:16a.c
Author:Thouseef
Description:To implement write lock.
Date:30/08/2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file_desc;
    struct flock file_lock;

    file_desc = open("Q16.txt", O_WRONLY | O_CREAT, 0666);
    if (file_desc == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file_lock.l_type = F_WRLCK;
    file_lock.l_whence = SEEK_SET;
    file_lock.l_start = 0;
    file_lock.l_len = 0;
    file_lock.l_pid = getpid();

    if (fcntl(file_desc, F_SETLKW, &file_lock) == -1) {
        perror("Error acquiring write lock");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    printf("Write lock acquired. Writing to the file...\n");

    if (write(file_desc, "hello thouseef\n", 12) == -1) {
        perror("Error writing to file");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    sleep(10);

    file_lock.l_type = F_UNLCK;
    if (fcntl(file_desc, F_SETLK, &file_lock) == -1) {
        perror("Error releasing write lock");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    printf("Write lock released.\n");

    close(file_desc);
    return 0;
}
/**
Output:Write lock acquired. Writing to the file...
Write lock released.
**/
