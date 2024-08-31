/**
Name:q15.c
Author:Thouseef
Description:Program to display the environmental variable of the user
Date:27th August 2024
**/
#include <stdio.h>

extern char **environ;

int main() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
    return 0;
}
