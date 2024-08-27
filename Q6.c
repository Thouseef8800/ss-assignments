//MT2024159
#include <unistd.h>   
#include <stdio.h>    

#define B_SIZE 1024

int main() {
    char buffer[B_SIZE];
    ssize_t bytesread;

    bytesread = read(STDIN_FILENO, buffer, B_SIZE);

    if (bytesread == -1) {
        perror("read");
        return 1;
    }

    ssize_t byteswritten = write(STDOUT_FILENO, buffer, bytesread);

    if (byteswritten == -1) {
        perror("write");
        return 1;
    }

    return 0;
}
