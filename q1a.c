#include <stdio.h>
#include <unistd.h>
int main(){
  if(symlink("as.txt","abcde")==-1){
perror("symlink");
return 1;
}
return 0;
}
