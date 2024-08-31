/**
Name:q19.c
Author:Thouseef
Description:Write a program to find out time taken to execute getpid system call
Date:29th August 2024
**/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#if defined(__i386__)
static __inline__ uint64_t rdtsc(void) {
    uint64_t x;
    __asm__ volatile ("rdtsc" : "=A" (x));
    return x;
}
#elif defined(__x86_64__)
static __inline__ uint64_t rdtsc(void) {
    uint32_t hi, lo;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)lo) | (((uint64_t)hi) << 32);
}
#else
#error "Unsupported architecture"
#endif

int main() {
    uint64_t start, end;
    pid_t pid;

    start = rdtsc();
    pid = getpid();
    end = rdtsc();

    printf("Time taken to execute getpid(): %lu cycles\n", (end - start));
    printf("Process ID: %d\n", pid);

    return 0;
}
/**Output:
Time taken to execute getpid(): 12925 clock cycles
**/
