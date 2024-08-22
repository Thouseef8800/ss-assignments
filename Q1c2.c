//MT2024159
#include <sys/types.h>  // For mkfifo()
#include <sys/stat.h>   // For mkfifo()
#include <stdio.h>      // For printf() and perror()

int main() {
    const char *fifo_path = "my_fifo1";  // Specify the path for the FIFO

    // Create the FIFO with read/write permissions for the owner (0600)
    if (mkfifo(fifo_path, 0600) == 0) {
        printf("FIFO created successfully at %s\n", fifo_path);
    } else {
        perror("mkfifo");  // Print an error message if FIFO creation fails
    }

    return 0;
}
