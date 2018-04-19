#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "cse320_functions.h"
#include "main.h"

int i = 0;
//sem_t mutex;
extern addr_in_use addr_struct[25];

int main(int argc, char** argv){

  //addr_in_use *temp = addr_struct;
  //addr_struct[0].ref_count = 5;
  //int x = addr_struct[0].ref_count;
  //sem_init(&mutex, 0, 1);
  //int y = addr_struct[1].ref_count;

  //printf("%d\n", y);

  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, my_thread, NULL);
  pthread_create(&tid2, NULL, my_thread, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  //printf("%i\n", i);

  exit(0);
}

void *my_thread(void *vargp){
  int j;
  for(j = 0;j < 100000;j++){
    //sem_wait(&mutex);
    i++;
    //sem_post(&mutex);
  }
  return NULL;
}
