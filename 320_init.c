#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include "cse320_functions.h"

extern sem_t mutex;
int addr_count = 0;
int files_count = 0;
extern addr_in_use addr_struct[25];

void cse320_init(){

  sem_init(&mutex, 0, 1);


  return;

}
