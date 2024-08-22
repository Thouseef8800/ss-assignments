#include <stdio.h>
#include <unistd.h>
int main(){
  if(link("Q1b1.txt","hardlink")==-1){
perror("symlink");
return 1;
}
return 0;
}
