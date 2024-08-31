/**
Name:q20.c
Author:Thouseef
Description:Find out the priority of your running program. Modify the priority with nice command.
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    
    int current_priority = getpriority(PRIO_PROCESS, pid);
    printf("Current priority of the process (PID: %d): %d\n", pid, current_priority);

    int change = 1;
    int new_priority = nice(change);
    
    current_priority = getpriority(PRIO_PROCESS, pid);
    printf("New priority of the process (PID: %d): %d\n", pid, current_priority);

    return 0;
}
/**
Output:
Current priority of the process (PID: 29280): 0
New priority of the process (PID: 29280): 1
**/
