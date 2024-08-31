/**
Name:q1a.c
Author:Thouseef
Description:To create soft link
Date:20th August 2024
**/
#include <stdio.h>
#include <unistd.h>
int main(){
  if(symlink("as.txt","abcde")==-1){
perror("symlink");
return 1;
}
return 0;
}
/**
Output:
Soft link created successfully
**/
