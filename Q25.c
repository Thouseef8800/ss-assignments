/**
Name:q25.c
Author:Thouseef
Description:Program to create three child processes. The parent should wait for a particular child
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2, child3;

    child1 = fork();
    if (child1 == 0) {
        printf("Child 1 (PID: %d) is running\n", getpid());
        sleep(2);
        exit(0);
    }

    child2 = fork();
    if (child2 == 0) {
        printf("Child 2 (PID: %d) is running\n", getpid());
        sleep(4);
        exit(0);
    }

    child3 = fork();
    if (child3 == 0) {
        printf("Child 3 (PID: %d) is running\n", getpid());
        sleep(6);
        exit(0);
    }

    printf("Parent is waiting for Child 2 (PID: %d)\n", child2);
    waitpid(child2, NULL, 0);

    printf("Child 2 (PID: %d) has finished. Parent continues.\n", child2);

    waitpid(child1, NULL, 0);
    waitpid(child3, NULL, 0);

    printf("All children have finished. Parent process (PID: %d) exiting.\n", getpid());

    return 0;
}
/**
Output:
Child 1 (PID: 4422) is running
Parent is waiting for Child 2 (PID: 4423)
Child 2 (PID: 4423) is running
Child 3 (PID: 4424) is running
Child 2 (PID: 4423) has finished. Parent continues.
All children have finished. Parent process (PID: 4421) exiting.
**/
