/**
Name:Q1b2.c
Author:Thouseef
Description:Creating hardlink.
Date:20th August 2024"
**/
#include <stdio.h>
#include <unistd.h>
int main(){
  if(link("Q1b1.txt","hardlink")==-1){
perror("symlink");
return 1;
}
return 0;
}
/**
Output:
Hard link created successfully
**/
