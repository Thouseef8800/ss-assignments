/**
Name:Q3.c
Author:Thouseef
DEscription:Program to create a file and print the file descriptor value
Date:23th August 2024
**/
#include <fcntl.h>    // For creat()
#include <stdio.h>    // For printf()
#include <unistd.h>   // For close()

int main(){
    const char *filepath = "Q3.txt";
    int permi = 0644;

    int p = creat(filepath, permi);

    if (p == -1) {
        perror("creat");
        return 1;
    } else {
        printf("File created successfully. File descriptor: %d\n", p);
    }

    close(p);

    return 0;
}
/**
File created successfully. File descriptor: 3
**/
