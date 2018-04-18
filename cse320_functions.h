#ifndef FUNCTION_H
#define FUNCTION_H

//void cse320_malloc();
//void cse320_free();
//void cse320_open();
//void cse320_fclose();
//void cse320_clean();

struct addr_in_use{
  void* addr;
  int ref_count;
};

struct files_in_use{
  char *filename;
  int ref_count;
};

#endif
