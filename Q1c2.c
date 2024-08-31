/**
Name:Q1c2.c
Author:Thouseef
Description:To create FIFO file type
Date:20th august 2024**/
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>      

int main() {
    const char *fifo_path = "my_fifo1"; 
    if (mkfifo(fifo_path, 0600) == 0) {
        printf("FIFO created successfully at %s\n", fifo_path);
    } else {
        perror("mkfifo");  
    }

    return 0;
}
/**
Output:mkfifo: File exists
**/
