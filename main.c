#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include "main.h"
#include "cse320_functions.h"

int main(int argc, char** argv){
  /*int max = 2;
  cse320_init();

  pthread_t tid[max]; 
  int i = 0;

  for(i = 0;i < max;i++){

    pthread_create(&tid[i], NULL, my_thread, NULL);
    
  }

  for(i = 0;i < max;i++){
  
    pthread_join(tid[i], NULL);

  }

  cse320_clean();*/

  cse320_settimer(5);

  pid_t pid;
  
  //int i;
  //for(i = 0;i < 5;i++){
    if((pid = cse320_fork()) == 0){
      printf("child function\n");
    }else{
      printf("parent function\n");
    }
    /*if((pid = cse320_fork()) == 0){
      printf("child function\n");
    }else{
      printf("parent function\n");
    }*/


    
  //}
  exit(0);
}

void *my_thread(void *vargp){
    //void *ptr = cse320_malloc(50);
    //printf("%p\n", ptr);

    /*FILE *ptr = NULL;

    if(files_count == 1){
      ptr = cse320_fopen("file2.txt", "r");
    }else{
      ptr = cse320_fopen("file.txt", "r");
    }

    //ptr = cse320_fopen("file.txt", "r");

    printf("%p\n", ptr);*/
    
  return NULL;
}
