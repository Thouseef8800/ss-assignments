/**
Name:Q5.c
Author:Thouseef
Description:Program to create five new files with infinite loop
Date:22nd August 2024
**/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, i;

    while (1) {
        for (i = 0; i < 5; i++) {
            char filename[20];
            sprintf(filename, "file%d.txt", i);
            fd = open(filename, O_CREAT | O_WRONLY, 0644);
            if (fd == -1) {
                perror("open");
                return 1;
            }
            close(fd);
        }
    }

    return 0;
}
