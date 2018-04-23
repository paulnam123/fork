#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <semaphore.h>
#include <signal.h>
#include "cse320_functions.h"
#include "cse320_fork.h"

void cse320_settimer(int n){

  time = n;
  
  struct itimerval interval;

  interval.it_value.tv_sec = n;
  interval.it_value.tv_usec = 0;
  interval.it_interval = interval.it_value;
  if(setitimer(ITIMER_REAL, &interval, NULL) == -1){
    exit(-1);
  }

  return;
}
