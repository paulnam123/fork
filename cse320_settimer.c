#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <semaphore.h>
#include <signal.h>
#include "cse320_functions.h"

void cse320_settimer(int n){
  
  struct itimerval interval;


  interval.it_value.tv_sec = n;
  interval.it_value.tv_usec = (n * 1000) % 1000000;
  interval.it_interval = interval.it_value;
  if(setitimer(ITIMER_REAL, &interval, NULL) == -1){
    exit(-1);
  }

  return;
}
