#ifndef FUNCTION_H
#define FUNCTION_H

sem_t mutex;

void cse320_init();
void* cse320_malloc(size_t size);
void cse320_free(void *ptr);
FILE* cse320_fopen(char *filename, char *mode);
int cse320_fclose(FILE* stream);
void cse320_clean();
pid_t cse320_fork();
void cse320_settimer(int N);

typedef struct addr_in_use{
  void* addr;
  int ref_count;
}addr_in_use;

typedef struct files_in_use{
  char *filename;
  int ref_count;
  FILE* fp;
}files_in_use;

addr_in_use addr_struct[25];
files_in_use files_struct[25];

extern int addr_count;
extern int files_count;

#endif
