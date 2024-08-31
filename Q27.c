/*
Name:q27.c
Author:Thouseef
Description:Program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date:29th August 2024
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *env[] = { NULL };
        execle("/bin/ls", "ls", "-Rl", NULL, env);
        perror("execle failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execv("/bin/ls", args);
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    pid = fork();
    if (pid == 0) {
        char *args[] = { "ls","-Rl", NULL };
        execvp("ls", args);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }
    wait(NULL);

    return 0;
}
/**total 620
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     1 Aug 30 09:38 26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16344 Aug 30 10:46 27
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1352 Aug 30 10:46 27.c
lrwxrwxrwx 1 thouseef-ahmed-syed thouseef-ahmed-syed     6 Aug 22 08:14 abcde -> as.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:01 a.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    12 Aug 22 08:13 as.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file0.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file1.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file2.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file3.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file4.txt
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink.txt
prw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:08 my_fifo
prw------- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:21 my_fifo1
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   917 Aug 27 11:02 Q10.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16224 Aug 27 11:02 Q10.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 27 11:02 Q10.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1587 Aug 27 15:31 Q11.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 27 15:31 Q11.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    88 Aug 27 15:31 Q11.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   635 Aug 29 06:38 Q12.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 29 06:38 Q12.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    26 Aug 29 06:29 Q12.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   573 Aug 29 06:34 Q13.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:38 Q13.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   974 Aug 29 06:47 Q14.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16200 Aug 29 06:48 Q14.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   181 Aug 29 07:03 Q15.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 07:03 Q15.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1408 Aug 29 10:15 Q16.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16320 Aug 29 10:16 Q16.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     5 Aug 29 10:15 Q16.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1334 Aug 29 10:41 Q17.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   685 Aug 29 10:42 Q19.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 10:42 Q19.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16008 Aug 22 08:14 q1a
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   131 Aug 22 08:14 q1a.c
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 Q1b1.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16000 Aug 22 08:54 Q1b2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   133 Aug 22 08:54 Q1b2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 09:21 Q1c2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   522 Aug 22 09:20 Q1c2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 10:16 Q2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   777 Aug 29 18:57 Q20.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 29 18:55 Q20.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   642 Aug 29 19:00 Q21.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 29 19:00 Q21.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   925 Aug 29 19:11 Q22.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 29 19:12 Q22.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    59 Aug 29 19:12 Q22.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1044 Aug 29 19:14 Q23.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:14 Q23.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   833 Aug 29 19:16 Q24.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:16 Q24.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  3205 Aug 30 09:31 Q25.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 09:31 Q25.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1242 Aug 30 10:29 Q26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 10:29 Q26.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   174 Aug 27 08:02 Q2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:44 Q3
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   418 Aug 27 08:04 Q3.c
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 10:44 Q3.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:55 Q4
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   363 Aug 27 08:06 Q4.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 22 10:58 Q4.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   432 Aug 29 06:41 Q5.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:42 Q5.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 22 11:15 Q6
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   436 Aug 27 08:07 Q6.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:20 Q7a.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:23 Q7b.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   614 Aug 27 10:19 Q7.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 27 10:23 Q7.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   313 Aug 27 10:10 Q8.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:12 Q8.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    89 Aug 27 10:12 Q8.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   876 Aug 27 10:31 Q9.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 27 10:31 Q9.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 27 10:28 Q9.txt
.:
total 620
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     1 Aug 30 09:38 26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16344 Aug 30 10:46 27
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1352 Aug 30 10:46 27.c
lrwxrwxrwx 1 thouseef-ahmed-syed thouseef-ahmed-syed     6 Aug 22 08:14 abcde -> as.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:01 a.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    12 Aug 22 08:13 as.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file0.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file1.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file2.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file3.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file4.txt
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink.txt
prw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:08 my_fifo
prw------- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:21 my_fifo1
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   917 Aug 27 11:02 Q10.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16224 Aug 27 11:02 Q10.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 27 11:02 Q10.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1587 Aug 27 15:31 Q11.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 27 15:31 Q11.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    88 Aug 27 15:31 Q11.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   635 Aug 29 06:38 Q12.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 29 06:38 Q12.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    26 Aug 29 06:29 Q12.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   573 Aug 29 06:34 Q13.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:38 Q13.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   974 Aug 29 06:47 Q14.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16200 Aug 29 06:48 Q14.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   181 Aug 29 07:03 Q15.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 07:03 Q15.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1408 Aug 29 10:15 Q16.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16320 Aug 29 10:16 Q16.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     5 Aug 29 10:15 Q16.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1334 Aug 29 10:41 Q17.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   685 Aug 29 10:42 Q19.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 10:42 Q19.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16008 Aug 22 08:14 q1a
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   131 Aug 22 08:14 q1a.c
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 Q1b1.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16000 Aug 22 08:54 Q1b2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   133 Aug 22 08:54 Q1b2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 09:21 Q1c2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   522 Aug 22 09:20 Q1c2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 10:16 Q2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   777 Aug 29 18:57 Q20.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 29 18:55 Q20.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   642 Aug 29 19:00 Q21.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 29 19:00 Q21.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   925 Aug 29 19:11 Q22.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 29 19:12 Q22.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    59 Aug 29 19:12 Q22.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1044 Aug 29 19:14 Q23.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:14 Q23.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   833 Aug 29 19:16 Q24.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:16 Q24.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  3205 Aug 30 09:31 Q25.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 09:31 Q25.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1242 Aug 30 10:29 Q26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 10:29 Q26.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   174 Aug 27 08:02 Q2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:44 Q3
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   418 Aug 27 08:04 Q3.c
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 10:44 Q3.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:55 Q4
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   363 Aug 27 08:06 Q4.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 22 10:58 Q4.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   432 Aug 29 06:41 Q5.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:42 Q5.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 22 11:15 Q6
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   436 Aug 27 08:07 Q6.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:20 Q7a.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:23 Q7b.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   614 Aug 27 10:19 Q7.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 27 10:23 Q7.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   313 Aug 27 10:10 Q8.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:12 Q8.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    89 Aug 27 10:12 Q8.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   876 Aug 27 10:31 Q9.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 27 10:31 Q9.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 27 10:28 Q9.txt
.:
total 620
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     1 Aug 30 09:38 26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16344 Aug 30 10:46 27
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1352 Aug 30 10:46 27.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   917 Aug 27 11:02 Q10.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16224 Aug 27 11:02 Q10.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 27 11:02 Q10.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1587 Aug 27 15:31 Q11.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 27 15:31 Q11.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    88 Aug 27 15:31 Q11.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   635 Aug 29 06:38 Q12.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 29 06:38 Q12.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    26 Aug 29 06:29 Q12.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   573 Aug 29 06:34 Q13.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:38 Q13.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   974 Aug 29 06:47 Q14.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16200 Aug 29 06:48 Q14.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   181 Aug 29 07:03 Q15.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 07:03 Q15.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1408 Aug 29 10:15 Q16.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16320 Aug 29 10:16 Q16.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     5 Aug 29 10:15 Q16.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1334 Aug 29 10:41 Q17.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   685 Aug 29 10:42 Q19.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 10:42 Q19.out
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 Q1b1.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16000 Aug 22 08:54 Q1b2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   133 Aug 22 08:54 Q1b2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 09:21 Q1c2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   522 Aug 22 09:20 Q1c2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 10:16 Q2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   174 Aug 27 08:02 Q2.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   777 Aug 29 18:57 Q20.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 29 18:55 Q20.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   642 Aug 29 19:00 Q21.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 29 19:00 Q21.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   925 Aug 29 19:11 Q22.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 29 19:12 Q22.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    59 Aug 29 19:12 Q22.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1044 Aug 29 19:14 Q23.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:14 Q23.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   833 Aug 29 19:16 Q24.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:16 Q24.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  3205 Aug 30 09:31 Q25.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 09:31 Q25.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1242 Aug 30 10:29 Q26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 10:29 Q26.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:44 Q3
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   418 Aug 27 08:04 Q3.c
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 10:44 Q3.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:55 Q4
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   363 Aug 27 08:06 Q4.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 22 10:58 Q4.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   432 Aug 29 06:41 Q5.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:42 Q5.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 22 11:15 Q6
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   436 Aug 27 08:07 Q6.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   614 Aug 27 10:19 Q7.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 27 10:23 Q7.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:20 Q7a.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:23 Q7b.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   313 Aug 27 10:10 Q8.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:12 Q8.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    89 Aug 27 10:12 Q8.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   876 Aug 27 10:31 Q9.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 27 10:31 Q9.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 27 10:28 Q9.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:01 a.out
lrwxrwxrwx 1 thouseef-ahmed-syed thouseef-ahmed-syed     6 Aug 22 08:14 abcde -> as.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    12 Aug 22 08:13 as.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file0.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file1.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file2.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file3.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file4.txt
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink.txt
prw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:08 my_fifo
prw------- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:21 my_fifo1
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16008 Aug 22 08:14 q1a
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   131 Aug 22 08:14 q1a.c
.:
total 620
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     1 Aug 30 09:38 26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16344 Aug 30 10:46 27
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1352 Aug 30 10:46 27.c
lrwxrwxrwx 1 thouseef-ahmed-syed thouseef-ahmed-syed     6 Aug 22 08:14 abcde -> as.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:01 a.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    12 Aug 22 08:13 as.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file0.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file1.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file2.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file3.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file4.txt
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink.txt
prw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:08 my_fifo
prw------- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:21 my_fifo1
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   917 Aug 27 11:02 Q10.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16224 Aug 27 11:02 Q10.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 27 11:02 Q10.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1587 Aug 27 15:31 Q11.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 27 15:31 Q11.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    88 Aug 27 15:31 Q11.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   635 Aug 29 06:38 Q12.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 29 06:38 Q12.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    26 Aug 29 06:29 Q12.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   573 Aug 29 06:34 Q13.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:38 Q13.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   974 Aug 29 06:47 Q14.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16200 Aug 29 06:48 Q14.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   181 Aug 29 07:03 Q15.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 07:03 Q15.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1408 Aug 29 10:15 Q16.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16320 Aug 29 10:16 Q16.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     5 Aug 29 10:15 Q16.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1334 Aug 29 10:41 Q17.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   685 Aug 29 10:42 Q19.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 10:42 Q19.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16008 Aug 22 08:14 q1a
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   131 Aug 22 08:14 q1a.c
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 Q1b1.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16000 Aug 22 08:54 Q1b2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   133 Aug 22 08:54 Q1b2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 09:21 Q1c2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   522 Aug 22 09:20 Q1c2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 10:16 Q2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   777 Aug 29 18:57 Q20.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 29 18:55 Q20.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   642 Aug 29 19:00 Q21.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 29 19:00 Q21.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   925 Aug 29 19:11 Q22.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 29 19:12 Q22.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    59 Aug 29 19:12 Q22.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1044 Aug 29 19:14 Q23.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:14 Q23.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   833 Aug 29 19:16 Q24.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:16 Q24.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  3205 Aug 30 09:31 Q25.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 09:31 Q25.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1242 Aug 30 10:29 Q26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 10:29 Q26.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   174 Aug 27 08:02 Q2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:44 Q3
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   418 Aug 27 08:04 Q3.c
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 10:44 Q3.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:55 Q4
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   363 Aug 27 08:06 Q4.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 22 10:58 Q4.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   432 Aug 29 06:41 Q5.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:42 Q5.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 22 11:15 Q6
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   436 Aug 27 08:07 Q6.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:20 Q7a.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:23 Q7b.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   614 Aug 27 10:19 Q7.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 27 10:23 Q7.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   313 Aug 27 10:10 Q8.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:12 Q8.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    89 Aug 27 10:12 Q8.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   876 Aug 27 10:31 Q9.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 27 10:31 Q9.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 27 10:28 Q9.txt
.:
total 620
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     1 Aug 30 09:38 26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16344 Aug 30 10:46 27
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1352 Aug 30 10:46 27.c
lrwxrwxrwx 1 thouseef-ahmed-syed thouseef-ahmed-syed     6 Aug 22 08:14 abcde -> as.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:01 a.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    12 Aug 22 08:13 as.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file0.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file1.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file2.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file3.txt
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 29 06:42 file4.txt
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 hardlink.txt
prw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:08 my_fifo
prw------- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 09:21 my_fifo1
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   917 Aug 27 11:02 Q10.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16224 Aug 27 11:02 Q10.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 27 11:02 Q10.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1587 Aug 27 15:31 Q11.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 27 15:31 Q11.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    88 Aug 27 15:31 Q11.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   635 Aug 29 06:38 Q12.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 29 06:38 Q12.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    26 Aug 29 06:29 Q12.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   573 Aug 29 06:34 Q13.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:38 Q13.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   974 Aug 29 06:47 Q14.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16200 Aug 29 06:48 Q14.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   181 Aug 29 07:03 Q15.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 07:03 Q15.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1408 Aug 29 10:15 Q16.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16320 Aug 29 10:16 Q16.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     5 Aug 29 10:15 Q16.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1334 Aug 29 10:41 Q17.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   685 Aug 29 10:42 Q19.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16032 Aug 29 10:42 Q19.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16008 Aug 22 08:14 q1a
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   131 Aug 22 08:14 q1a.c
-rw-rw-r-- 3 thouseef-ahmed-syed thouseef-ahmed-syed    30 Aug 22 08:36 Q1b1.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16000 Aug 22 08:54 Q1b2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   133 Aug 22 08:54 Q1b2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 09:21 Q1c2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   522 Aug 22 09:20 Q1c2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16048 Aug 22 10:16 Q2
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   777 Aug 29 18:57 Q20.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 29 18:55 Q20.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   642 Aug 29 19:00 Q21.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 29 19:00 Q21.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   925 Aug 29 19:11 Q22.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16208 Aug 29 19:12 Q22.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    59 Aug 29 19:12 Q22.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1044 Aug 29 19:14 Q23.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:14 Q23.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   833 Aug 29 19:16 Q24.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16168 Aug 29 19:16 Q24.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  3205 Aug 30 09:31 Q25.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 09:31 Q25.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed  1242 Aug 30 10:29 Q26.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16264 Aug 30 10:29 Q26.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   174 Aug 27 08:02 Q2.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:44 Q3
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   418 Aug 27 08:04 Q3.c
-rw-r--r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed     0 Aug 22 10:44 Q3.txt
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16088 Aug 22 10:55 Q4
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   363 Aug 27 08:06 Q4.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 22 10:58 Q4.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   432 Aug 29 06:41 Q5.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 29 06:42 Q5.out
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16096 Aug 22 11:15 Q6
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   436 Aug 27 08:07 Q6.c
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:20 Q7a.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    10 Aug 27 10:23 Q7b.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   614 Aug 27 10:19 Q7.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16128 Aug 27 10:23 Q7.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   313 Aug 27 10:10 Q8.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16176 Aug 27 10:12 Q8.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    89 Aug 27 10:12 Q8.txt
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed   876 Aug 27 10:31 Q9.c
-rwxrwxr-x 1 thouseef-ahmed-syed thouseef-ahmed-syed 16136 Aug 27 10:31 Q9.out
-rw-rw-r-- 1 thouseef-ahmed-syed thouseef-ahmed-syed    20 Aug 27 10:28 Q9.txt **/

































































































































