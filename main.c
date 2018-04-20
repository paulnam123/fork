#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "main.h"
#include "cse320_functions.h"

int main(int argc, char** argv){

  cse320_init();
 
  /*pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, my_thread, NULL);
  pthread_create(&tid2, NULL, my_thread, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);*/

  pthread_t tid[25]; 
  int i = 0;

  for(i = 0;i < 25;i++){

    pthread_create(&tid[i], NULL, my_thread, NULL);
    
  }

  for(i = 0;i < 25;i++){
  
    pthread_join(tid[i], NULL);

  }

  for(i = 0;i < 25;i++){
    
    free(addr_struct[i].addr);
  }

  //printf("%d\n", addr_count);
  //printf("%d\n", addr_struct[1].ref_count);
  exit(0);
}

void *my_thread(void *vargp){
    void *ptr = cse320_malloc(50);
    printf("%p\n", ptr);
    //printf("%d\n", addr_count);
  return NULL;
}
