//MT2024159
#include <fcntl.h>    
#include <stdio.h>    
#include <unistd.h>   

int main() {
 
    const char *filepath = "Q4.txt"
    int p = open(filepath, O_RDWR | O_EXCL);

    if (p  == -1) {
        perror("open");
        return 1;
    } else {
        printf("File opened successfully. File descriptor: %d\n", p);
      }
    close(p);

    return 0;
}
