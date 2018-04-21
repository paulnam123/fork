#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "cse320_functions.h"

int cse320_fclose(FILE* stream){
  
  int retval = 0;

  char buf[30] = "Close: Illegal filename\n";
  char buf2[30] = "Close: Ref count is zero\n";

  sem_wait(&mutex);
  
  int j, found = 0;
  for(j = 0;j < files_count;j++){

    if(stream == files_struct[j].fp){

      if(files_struct[j].ref_count > 0){

        retval = fclose(stream);
        files_struct[j].ref_count--;

	found = 1;

        break;
      }else{
	errno = EINVAL;
	write(STDOUT_FILENO, buf2, 30);

	sem_post(&mutex);

	exit(-1);
      }
    }
  }

  if(!found){

    errno = ENOENT;
    write(STDOUT_FILENO, buf, 30);

    sem_post(&mutex);

    exit(-1);
  }

  sem_post(&mutex);

  return retval;
}
