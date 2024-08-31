/**
Name:16b.c
Author:Thouseef
Description:To implement read lock.
Date:29/08/2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file_desc;
    struct flock file_lock;

    file_desc = open("Q16.txt", O_RDONLY);
    if (file_desc == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file_lock.l_type = F_RDLCK;
    file_lock.l_whence = SEEK_SET;
    file_lock.l_start = 0;
    file_lock.l_len = 0;
    file_lock.l_pid = getpid();

    if (fcntl(file_desc, F_SETLKW, &file_lock) == -1) {
        perror("Error acquiring read lock");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    printf("Read lock acquired. Reading from the file...\n");

    char buffer[100];
    if (read(file_desc, buffer, sizeof(buffer)) == -1) {
        perror("Error reading from file");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    printf("File content: %s\n", buffer);

    sleep(10);

    file_lock.l_type = F_UNLCK;
    if (fcntl(file_desc, F_SETLK, &file_lock) == -1) {
        perror("Error releasing read lock");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    printf("Read lock released.\n");

    close(file_desc);
    return 0;
}
/**
Output:
Read lock acquired. Reading from the file...
File content: hello Thouseef
2955084264875696819529550842648756968195295508426487569681952955084264875696819529550842
Read lock released.
**/

