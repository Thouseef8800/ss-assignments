/**
Name:Q2.c
Author:Thouseef
Description:Program to execute in an infinite loop at the background
Date:23th August 2024
**/
#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
      printf("Running yeah... PID: %d\n", getpid());
      sleep(5);  
    }
    return 0;
}
/**
Running yeah... PID: 5151
Running yeah... PID: 5151
Running yeah... PID: 5151
**/
