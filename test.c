#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

  FILE *f = fopen("file.txt", "w");
  if(f == NULL){
    exit(1);
  }

  sleep(2);
  fprintf(f, "print 123\n");

  fclose(f);

  exit(0);

}
