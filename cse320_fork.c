#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include "cse320_functions.h"
#include "cse320_fork.h"

pid_t cse320_fork(){

  alarm_received = 0;

  pid_t pid;
  int status;

  signal(SIGALRM, sigalrm_handler);

  if((pid = fork()) == 0){

  }else{
    // in parent    
    while(!alarm_received){
      // wait for alarm
    }
      
    while((pid = waitpid(-1, &status, 0)) != -1){
    
    } 
   
  }


  return pid;
}

void sigalrm_handler(int sig){
 
  alarm_received = 1;

  return;
}
