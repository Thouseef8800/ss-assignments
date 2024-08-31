/**
Name:q28.c
Author:Thouseef
Description:Program to get maximum and minimum real time priority.
Date:30th August 2024
**/
#include <stdio.h>
#include <sched.h>

int main() {
    int policy = SCHED_FIFO;

    int max_priority = sched_get_priority_max(policy);
    int min_priority = sched_get_priority_min(policy);

    if (max_priority == -1 || min_priority == -1) {
        perror("Error getting priority");
        return 1;
    }

    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
/**Output:
Maximum real-time priority: 99
Minimum real-time priority: 1
**/
