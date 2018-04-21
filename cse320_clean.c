#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "cse320_functions.h"

void cse320_clean(){
  
  char buf[30] = "Free: Illegal Address\n";
  char buf2[30] = "Free: Double Free Attempt\n";

  sem_wait(&mutex);
  
  int j, found = 0;

  for(j = 0;j < addr_count;j++){

    if(addr_struct[j].addr == ptr){
      if(addr_struct[j].ref_count == 0){
        errno = EADDRNOTAVAIL;
	write(STDOUT_FILENO, buf2, 30);	

	sem_post(&mutex);

        exit(-1);
      }else if(addr_struct[j].ref_count > 0){
	addr_struct[j].ref_count--;
        free(ptr);
        found = 1;
        break;
      }
    }

  }

  if(!found){
    errno = EFAULT;
    write(STDOUT_FILENO, buf, 30);
    
    sem_post(&mutex);

    exit(-1);
  }

  sem_post(&mutex);

  return;
