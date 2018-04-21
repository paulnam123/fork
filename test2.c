
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){


  FILE *f = fopen("file.txt", "w");
  if(f == NULL){
    exit(1);
  }
  FILE *f2 = fopen("file.txt", "w");
  if(f == NULL){
    exit(1);
  }
  
  int fd1 = fileno(f);
  int fd2 = fileno(f2);

  fclose(f);

  exit(0);

}
