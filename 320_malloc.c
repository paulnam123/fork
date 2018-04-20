
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "cse320_functions.h"

void* cse320_malloc(size_t size){
  
  char buf[25] = "Not enough memory.\n";

  void* retval = malloc(size);
  sem_wait(&mutex);
  //addr_count = 25;  

  if(addr_count + 1 > 25){
    errno = ENOMEM;
    write(STDOUT_FILENO, buf, 25);
    free(retval);
    
    sem_post(&mutex);

    exit(-1);

  }else{

    addr_struct[addr_count].addr = retval;
    addr_struct[addr_count].ref_count++;
    addr_count++;

    sem_post(&mutex);
  } 

  return retval;

}
