#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include "part1.h"

int main(int argc, char** argv){

  printf("Please type help to see how to use this program\n");
  
  signal(SIGINT, sigint_handler);

  while(1){

    char input[255];
    //char *list[100];
    char **list = malloc(100 * sizeof(char));
    char *filename = NULL;

    char *token = NULL;
    int count = 0;

    printf("What would you like to do?\n");

    //input from user
    fgets(input, 50, stdin);

    // if exit command, exit the program
    if(!strcmp(input, "exit\n")){
      free(list);
      exit(0);
    }else if(!strcmp(input, "help\n")){
      // print text description
      // ***************************
      printf("Commands:\n");
      printf("run X (-flag) : Runs a program with the name X, with option of adding flags.\n");
      printf("exit : Exits this program.\n");
      printf("help : Opens up the help text description.\n");
      continue;
    }

    token = strtok(input, " \n");
    char *command = token;

    token = strtok(NULL, " \n");
    while(token != NULL){
      list[count] = token;
      token = strtok(NULL, " \n");
      count++;
    }
    if(count <= 1){
      list[1] = 0x0;
    }
  
    filename = list[0];

    if(!strcmp(command, "run")){
      
      // block signals when app running
      sigset_t mask, prev;

      sigemptyset(&mask);
      sigaddset(&mask, SIGINT);
      sigaddset(&mask, SIGKILL);

      sigprocmask(SIG_BLOCK, &mask, &prev);

      pid_t pid;
      int status;
  
      if((pid = Fork()) == 0){
	// change from argv to flags?
	if(execve(filename, list, NULL) == -1){
	  if(execvp(filename, list) == -1){
	    printf("Application does not exist.\n");
	    free(list);
	    exit(-1);
	  }
	}

      }else{
	/*if(wait(&status) == -1){
	  unix_error("Wait error\n");
	  exit(1);
        }*/
	waitpid(pid, &status, 0);
      }
      // maybe wait for errno?
      sigprocmask(SIG_SETMASK, &prev, NULL);

    }else{
      printf("The command or program does not exist. Please try again.\n");
    }

    free(list);

  }

}

// fork wrapper from textbook
pid_t Fork(void){
  pid_t pid;

  if((pid = fork()) < 0){
    unix_error("Fork error\n");
  }

  return pid;
}

// unix_error from textbook
void unix_error(char *msg){
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(0);
}

void sigint_handler(int sig){
  return;
}
