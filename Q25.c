/**
Name:q25.c
Author:Thouseef Ahmed
Description:Program to create three child processes. The parent should wait for a particular child
Date:30th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    pid1 = fork();
    
    if (pid1 < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        pid2 = fork();
        
        if (pid2 < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) {
            printf("Child 2 (PID: %d) is running...\n", getpid());
            sleep(4);
            printf("Child 2 (PID: %d) is exiting...\n", getpid());
            exit(2);
        } else {
            printf("Child 1 (PID: %d) is running...\n", getpid());
            sleep(2);
            printf("Child 1 (PID: %d) is exiting...\n", getpid());
            exit(1);
        }
    } else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) {
            printf("Child 3 (PID: %d) is running...\n", getpid());
            sleep(3);
            printf("Child 3 (PID: %d) is exiting...\n", getpid());
            exit(3);
        } else {
            printf("Parent (PID: %d) created three children.\n", getpid());

            printf("Parent (PID: %d) waiting for child 1 (PID: %d) to finish...\n", getpid(), pid1);
            if (waitpid(pid1, &status, 0) == -1) {
                perror("waitpid failed");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(status)) {
                printf("Child 1 (PID: %d) exited with status %d\n", pid1, WEXITSTATUS(status));
            }

            printf("Parent (PID: %d) waiting for child 2 (PID: %d) to finish...\n", getpid(), pid2);
            if (waitpid(pid2, &status, 0) == -1) {
                perror("waitpid failed");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(status)) {
                printf("Child 2 (PID: %d) exited with status %d\n", pid2, WEXITSTATUS(status));
            }

            printf("Parent (PID: %d) waiting for child 3 (PID: %d) to finish...\n", getpid(), pid2);
            if (waitpid(pid2, &status, 0) == -1) {
                perror("waitpid failed");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(status)) {
                printf("Child 3 (PID: %d) exited with status %d\n", pid2, WEXITSTATUS(status));
            }
        }
    }

    return 0;
}

/**Output:
Parent (PID: 5346) created three children.
Parent (PID: 5346) waiting for child 1 (PID: 5347) to finish...
Child 3 (PID: 5348) is running...
Child 1 (PID: 5347) is running...
Child 2 (PID: 5349) is running...
Child 1 (PID: 5347) is exiting...
Child 1 (PID: 5347) exited with status 1
Parent (PID: 5346) waiting for child 2 (PID: 5348) to finish...
Child 3 (PID: 5348) is exiting...
Child 2 (PID: 5348) exited with status 3
Parent (PID: 5346) waiting for child 3 (PID: 5348) to finish...
waitpid failed: No child processes
Child 2 (PID: 5349) is exiting...
**/
