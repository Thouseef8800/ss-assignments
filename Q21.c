/**
Name:q21.c
Author:Thouseef
Description:Program to  call fork and print the parent and child process id.
Date:August 27th 2024
**/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
/** Output:
Parent process: PID = 8722, Child PID = 8723
Child process: PID = 8723, Parent PID = 8722
**/
