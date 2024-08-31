/**
Name:q29.c
Author:Thouseef
Description:Program to get scheduling policy and modify the scheduling policy.
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void display_policy(int policy_type) {
    switch (policy_type) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Current scheduling policy: Unknown\n");
            break;
    }
}

void apply_policy(int policy_type) {
    struct sched_param sched_parameters;
    sched_parameters.sched_priority = sched_get_priority_max(policy_type);

    if (sched_setscheduler(0, policy_type, &sched_parameters) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed to ");
    display_policy(policy_type);
}

int main() {
    int policy_type;
    
    policy_type = sched_getscheduler(0);
    if (policy_type == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Before changing policy:\n");
    display_policy(policy_type);

    printf("Changing to SCHED_FIFO:\n");
    apply_policy(SCHED_FIFO);

    policy_type = sched_getscheduler(0);
    if (policy_type == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }
    display_policy(policy_type);

    printf("Changing to SCHED_RR:\n");
    apply_policy(SCHED_RR);

    policy_type = sched_getscheduler(0);
    if (policy_type == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }
    display_policy(policy_type);

    return 0;
}
/**
Output:
before changing policy:
Current scheduling policy: SCHED_OTHER
Changing to SCHED_FIFO:
Scheduling policy changed to Current scheduling policy: SCHED_FIFO
Current scheduling policy: SCHED_FIFO
Changing to SCHED_RR:
Scheduling policy changed to Current scheduling policy: SCHED_RR
Current scheduling policy: SCHED_RR

**/
