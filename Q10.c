/**
Name:Q10.c
Author:Thouseef
Description:Program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
Date:August 27th 2024
**/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    ssize_t bytes_written;
    off_t offset;
    char buffer1[10] = "SYEDTHOUSE";
    char buffer2[10] = "9550842648";

    fd = open("Q10.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    bytes_written = write(fd, buffer1, 10);
    if (bytes_written != 10) {
        perror("Error writing first 10 bytes");
        close(fd);
        return 1;
    }

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    }
    printf("lseek returned: %ld\n", offset);

    bytes_written = write(fd, buffer2, 10);
    if (bytes_written != 10) {
        perror("Error writing second 10 bytes");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}
/** Output:lseek moved the file pointer to: 223 **/
