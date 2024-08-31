/**
Name:q30.c
Author:Thouseef
Description:Program to run a script at a specific time using a Daemon process.
Date:29th August 2024
**/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char target_time[] = "10:02";
    char script_command[] = "echo 'Running the script!'";

    while (1) {
        time_t now = time(NULL);
        struct tm *ltm = localtime(&now);

        char current_time[6];
        snprintf(current_time, sizeof(current_time), "%02d:%02d", ltm->tm_hour, ltm->tm_min);

        if (strcmp(target_time, current_time) == 0) {
            system(script_command);
            break;
        }

        sleep(60);
    }

    return 0;
}
/**Output:
Running the script!
**/
