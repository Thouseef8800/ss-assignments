/**
Name:18b.c
Author:Thouseef
Description :Read lock in record level.
Date:30/08/2024
**/
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

    memset(&fl, 0, sizeof(fl));
    fl.l_type = F_RDLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = start;
    fl.l_len = RECORD_SIZE;

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("Error locking record for reading");
        close(fd);
        exit(1);
    }

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

    printf("Train number: %d\n", train_number);
    printf("Tickets count: %d\n", tickets_count);

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
Enter the record number (1-based index): 2
Train number: 2
Tickets count: 148
**/
