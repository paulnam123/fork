#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "main.h"

void main(int argc, char** argv){
  
  char input[50];
  char *list[20];
  char *filename = NULL;

  char *token = NULL;
  int count = 0;

  while(1){

    printf("Ask user what to do\n");

    //input from user
    fgets(input, 50, stdin);

    // if exit command, exit the program
    if(!strcmp(input, "exit\n")){
      exit(0);
    }else if(!strcmp(input, "help\n")){
      // print text description
      // ***************************
    }

    token = strtok(input, " ");

    while(token != NULL){
      list[count] = token;
      token = strtok(NULL, " \n");
      count++;
    }
  
    char *command = list[0];
    char *filename = list[1];

    if(!strcmp(command, "run")){

      pid_t pid;
      int status;
  
      if(pid = Fork() == 0){
	// change from argv to flags?
	execvp(filename, argv);
      }else{
	while(wait(&status) == -1){
	  unix_error("Wait error\n");
	  exit(1);
        }
      }

    }else{
      printf("The command or program does not exist. Please try again.\n");
    }
 
    // check

  }

}

// fork wrapper from textbook
pid_t Fork(void){
  pid_t pid;

  if((pid = fork()) < 0){
    unix_error("Fork error");
  }

  return pid;
}

// unix_error from textbook
void unix_error(char *msg){
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(0);
}
