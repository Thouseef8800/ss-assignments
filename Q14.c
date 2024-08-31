/**
Name:q14.c
Author:Thouseef 
Description:Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date:28th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    if (S_ISDIR(st.st_mode)) {
        printf("%s is a directory\n", argv[1]);
    } else if (S_ISREG(st.st_mode)) {
        printf("%s is a regular file\n", argv[1]);
    } else if (S_ISCHR(st.st_mode)) {
        printf("%s is a character device\n", argv[1]);
    } else if (S_ISBLK(st.st_mode)) {
        printf("%s is a block device\n", argv[1]);
    } else if (S_ISFIFO(st.st_mode)) {
        printf("%s is a FIFO (named pipe)\n", argv[1]);
    } else if (S_ISSOCK(st.st_mode)) {
        printf("%s is a socket\n", argv[1]);
    } else {
        printf("%s is a special file\n", argv[1]);
    }

    return 0;
}
/** Output:
File: text.txt
File type: Regular file
**/
