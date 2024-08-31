/**
Name:18a.c
Author:Thouseef
Description:IMplementing record level locking using write lock.
Date:30/08/2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define RECORD_SIZE 7
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define RECORD_SIZE 7

int main() {
    const char *filename = "records.txt";
    int fd;
    struct flock fl;
    int record_index;
    off_t start;
    char buffer[RECORD_SIZE + 1] = {0};
    int train_number;
    int tickets_count;
    int new_tickets_count;
    int found = 0;

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    printf("Enter the record number (1-based index): ");
    scanf("%d", &record_index);

    start = (record_index - 1) * RECORD_SIZE;
    lseek(fd, start, SEEK_SET);

    if (read(fd, buffer, RECORD_SIZE) == -1) {
        perror("Error reading record");
        close(fd);
        exit(1);
    }

    if (sscanf(buffer, "%d %d", &train_number, &tickets_count) == 2) {
        found = 1;
    }

    if (!found) {
        printf("Record not found.\n");
        close(fd);
        exit(1);
    }

    memset(&fl, 0, sizeof(fl));
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = start;
    fl.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error locking record");
        close(fd);
        exit(1);
    }

    printf("Current tickets count for train %d: %d\n", train_number, tickets_count);

    if (tickets_count > 0) {
        tickets_count--;
        snprintf(buffer, sizeof(buffer), "%d %d\n", train_number, tickets_count);
        lseek(fd, start, SEEK_SET);
        if (write(fd, buffer, RECORD_SIZE) == -1) {
            perror("Error writing to record");
            close(fd);
            exit(1);
        }
        printf("Record updated successfully. New tickets count: %d\n", tickets_count);
    } else {
        printf("No tickets available.\n");
    }

    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("Error unlocking record");
        close(fd);
        exit(1);
    }

    close(fd);

    return 0;
}
/**
Output:
Enter the record number (1-based index): 1
Current tickets count for train 1: 93
Record updated successfully. New tickets count: 92
**/
