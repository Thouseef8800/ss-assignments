/**
Name:q26.c
Author:Thouseef
Description:Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program.
Date:30th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;

    if (argc < 3) {
        printf("Usage: %s <executable> <argument>\n", argv[0]);
        return 1;
    }

    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        char *args[] = {argv[1], argv[2], NULL};
        execvp(args[0], args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process (PID: %d) waiting for child (PID: %d) to finish...\n", getpid(), pid);
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
/**Output:
Parent process (PID: 6581) waiting for child (PID: 6582) to finish...
Hello, Thouseef!
Child process exited with status 0
**/
