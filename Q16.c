#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void write_lock(int fd) {
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the entire file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to acquire write lock");
        exit(1);
    } else {
        printf("Write lock acquired\n");
    }
}

void read_lock(int fd) {
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the entire file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to acquire read lock");
        exit(1);
    } else {
        printf("Read lock acquired\n");
    }
}

void unlock(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Unlock the entire file

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("Failed to release lock");
        exit(1);
    } else {
        printf("Lock released\n");
    }
}

int main() {
    int fd = open("Q16.txt", O_RDWR);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    write_lock(fd);
    // Perform write operations here
    unlock(fd);

    read_lock(fd);
    // Perform read operations here
    unlock(fd);

    close(fd);
    return 0;
}
