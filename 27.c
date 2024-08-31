/*
Name:q27.c
Author:Thouseef
Description:Program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *env[] = { NULL };
        execle("/bin/ls", "ls", "-Rl", NULL, env);
        perror("execle failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execv("/bin/ls", args);
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *args[] = { "ls","-Rl", NULL };
        execvp("ls", args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);

    return 0;
}


































































































































