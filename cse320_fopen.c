#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "cse320_functions.h"

FILE* cse320_fopen(char *filename, char *mode){
  
  char buf[30] = "Too many opened files\n";
  char buf2[25] = "File does not exist\n";

  sem_wait(&mutex);
  //addr_count = 25;  

  if(files_count + 1 > 25){
    errno = ENOMEM;
    write(STDOUT_FILENO, buf, 25);

    sem_post(&mutex);

    exit(-1);
  }

  FILE* fp = NULL;
  if((fp = fopen(filename, mode)) == NULL){
    write(STDOUT_FILENO, buf2, 25);
  }else{

    //check if same file exists, if so return it
    int j, used;
    for(j = 0;j < files_count;j++){

      if(!strcmp(filename, files_struct[j].filename)){
	fp = files_struct[j].fp;
	files_struct[j].ref_count++;
	used = 1;
      }


    }
    
    if(!used){
      
      files_struct[files_count].filename = filename; 
      files_struct[files_count].ref_count++;
      files_struct[files_count].fp = fp;
      files_count++;
    }

  }  
  
  sem_post(&mutex);

  return fp;
}
