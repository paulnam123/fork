#ifndef MAIN_H
#define MAIN_H

pid_t Fork(void);

void unix_error(char *msg);

void sigint_handler(int sig);

#endif
