/**
Name:q17.c
Author:Thouseef
Description:To  simulate online ticket reservation system.
Date:30/08/2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct ticket {
    int ticket_number;
};

int main() {
    int file_desc;
    struct ticket tkt;
    struct flock file_lock;

    file_desc = open("ticket_number.txt", O_RDWR | O_CREAT, 0666);
    if (file_desc == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file_lock.l_type = F_WRLCK;
    file_lock.l_whence = SEEK_SET;
    file_lock.l_start = 0;
    file_lock.l_len = sizeof(struct ticket);
    file_lock.l_pid = getpid();

    if (fcntl(file_desc, F_SETLKW, &file_lock) == -1) {
        perror("Error acquiring write lock");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    if (read(file_desc, &tkt, sizeof(tkt)) == -1) {
        perror("Error reading from file");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    tkt.ticket_number++;
    lseek(file_desc, 0, SEEK_SET);
	sleep(20);
    if (write(file_desc, &tkt, sizeof(tkt)) == -1) {
        perror("Error writing to file");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    printf("Ticket number booked by the user: %d\n", tkt.ticket_number);

    file_lock.l_type = F_UNLCK;
    if (fcntl(file_desc, F_SETLK, &file_lock) == -1) {
        perror("Error releasing write lock");
        close(file_desc);
        exit(EXIT_FAILURE);
    }

    close(file_desc);
    return 0;
}
/**
Output:
Ticket number booked by the user: 5
**/
