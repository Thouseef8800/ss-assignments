/**
Name:q24.c
Author:Thouseef
Description:Program to create an orphan process.
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(10);
        printf("Child process (PID: %d) is still running after parent exit...\n", getpid());
    } else {
        printf("Parent process (PID: %d) is exiting...\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return 0;
}
/**Output:
Parent process (PID: 4120) is exiting...
Child process (PID: 4899) is running...
Child process (PID: 4899) is still running after parent exit...
**/
