#ifndef FUNCTION_H
#define FUNCTION_H

void* cse320_malloc(size_t size);
//void cse320_free();
//void cse320_open();
//void cse320_fclose();
//void cse320_clean();

typedef struct addr_in_use{
  void* addr;
  int ref_count;
}addr_in_use;

typedef struct files_in_use{
  char *filename;
  int ref_count;
}files_in_use;

addr_in_use addr_struct[25];
files_in_use files_struct[25];

#endif
