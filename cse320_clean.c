#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "cse320_functions.h"

void cse320_clean(){
 
  int j;
 
  sem_wait(&mutex);

  // free all malloc 
  for(j = 0;j < addr_count;j++){

    free(addr_struct[j].addr);

  }

  // fclose all files 
  for(j = 0;j < files_count;j++){

    fclose(files_struct[j].fp);

  }

  sem_post(&mutex);

  return;
}
