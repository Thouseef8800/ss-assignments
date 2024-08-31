/**
Name:q23.c
Author:Thouseef
Description:Program to create a Zombie state of the running program
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(10);
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent process (PID: %d) is running...\n", getpid());
        printf("Parent process (PID: %d) is sleeping for 30 seconds...\n", getpid());
        sleep(30);
        printf("Parent process (PID: %d) is exiting...\n", getpid());
    }

    return 0;
}
/** Output:
Parent process (PID: 8014) is running...
Parent process (PID: 8014) is sleeping for 30 seconds...
Child process (PID: 8123) is running...
Child process (PID: 8123) is exiting...
Parent process (PID: 8014) is exiting...
**/
