#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "cse320_functions.h"
#include "main.h"

int i = 0;
extern sem_t mutex;
int addr_count = 0;
int files_count = 0;
extern addr_in_use addr_struct[25];

int main(int argc, char** argv){

  sem_init(&mutex, 0, 1);

  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, my_thread, NULL);
  pthread_create(&tid2, NULL, my_thread, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);


  printf("%p\n", addr_struct[0].addr);
  printf("%p\n", addr_struct[1].addr);
  printf("%p\n", addr_struct[2].addr);
  exit(0);
}

void *my_thread(void *vargp){
    void *ptr = cse320_malloc(50);
    //printf("%p\n", ptr);

    free(ptr);
  return NULL;
}
