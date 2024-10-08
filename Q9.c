/**
Name:Q9.c
Author:Thouseef
Description:Program to print the following information about a given file.
Date:22nd August 2024
**/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct stat fStat;
    const char *fName = "Q9.txt";

    if (stat(fName, &fStat) < 0) {
        perror("Failed to get file status");
        return 1;
    }

    printf("File: %s\n", fName);
    printf("Inode: %ld\n", fStat.st_ino);
    printf("Number of hard links: %ld\n", fStat.st_nlink);
    printf("UID: %d\n", fStat.st_uid);
    printf("GID: %d\n", fStat.st_gid);
    printf("Size: %ld bytes\n", fStat.st_size);
    printf("Block size: %ld bytes\n", fStat.st_blksize);
    printf("Number of blocks: %ld\n", fStat.st_blocks);
    printf("Time of last access: %s", ctime(&fStat.st_atime));
    printf("Time of last modification: %s", ctime(&fStat.st_mtime));
    printf("Time of last change: %s", ctime(&fStat.st_ctime));

    return 0;
}
/**
File: Q9.txt
Inode: 3953353
Number of hard links: 1
UID: 1000
GID: 1000
Size: 20 bytes
Block size: 4096 bytes
Number of blocks: 8
Time of last access: Sat Aug 31 08:45:25 2024
Time of last modification: Tue Aug 27 10:28:34 2024
Time of last change: Tue Aug 27 10:28:34 2024 
**/
