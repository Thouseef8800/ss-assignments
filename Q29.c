/**
Name:q29.c
Author:Thouseef
Description:Program to get scheduling policy and modify the scheduling policy.
Date:30th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_OTHER: printf("Current Policy: SCHED_OTHER\n"); break;
        case SCHED_FIFO: printf("Current Policy: SCHED_FIFO\n"); break;
        case SCHED_RR: printf("Current Policy: SCHED_RR\n"); break;
        default: printf("Unknown Policy\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <new_policy>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    int new_policy = atoi(argv[2]);
    struct sched_param param;
    int current_policy;

    current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    print_policy(current_policy);

    if (new_policy == 1) new_policy = SCHED_FIFO;
    else if (new_policy == 2) new_policy = SCHED_RR;
    else {
        fprintf(stderr, "Invalid policy\n");
        return 1;
    }

    param.sched_priority = sched_get_priority_max(new_policy);

    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    printf("Policy changed successfully.\n");

    current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    print_policy(current_policy);

    return 0;
}
/**Output:
**/
