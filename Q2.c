//MT2024159
#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
      printf("Running yeah... PID: %d\n", getpid());
      sleep(5);  
    }
    return 0;
}
