#ifndef PART_1_H
#define PART_1_H

pid_t Fork(void);

void unix_error(char *msg);

void sigint_handler(int sig);

#endif
