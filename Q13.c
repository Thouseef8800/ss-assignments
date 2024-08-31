/**
Name:q13.c
Author:Thouseef
Description:Program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not
Date:28th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval tv;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    int retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select()");
        exit(EXIT_FAILURE);
    } else if (retval == 0) {
        printf("No data available within 10 seconds\n");
    } else {
        printf("Data available on STDIN\n");
    }

    return 0;
}
