#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void start_daemon() {
    pid_t first_fork = fork();

    if (first_fork < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (first_fork > 0) {
        exit(EXIT_SUCCESS);
    }

    if (setsid() < 0) {
        perror("Setsid failed");
        exit(EXIT_FAILURE);
    }

    pid_t second_fork = fork();

    if (second_fork < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (second_fork > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    if (chdir("/") < 0) {
        perror("Chdir failed");
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    int target_hour = 15;
    int target_minute = 30;

    start_daemon();

    while (1) {
        time_t current_time;
        struct tm *time_info;

        time(&current_time);
        time_info = localtime(&current_time);

        if (time_info->tm_hour == target_hour && time_info->tm_min == target_minute) {
            system("/path/to/your/script.sh");
            sleep(60);
        }

        sleep(30);
    }

    return 0;
}
/**Output:
**/
