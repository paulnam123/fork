# Homework #4

Part 1:

To run the application, use the command "make part1" then "./part1." You can use the help command to see how to run the application.



Part 2:

In your Makefile, compile with your main application file, cse320_malloc.c, cse320_free.c, cse320_fopen.c, cse320_fclose.c, cse320_clean.c, cse320_init.c, and -lpthread.

In your main application, make sure to #include <semaphore.h>. 

Before calling the part 2 functions, call cse320_init() in your main application, which initializes the semaphore for thread testing.


Part 3:

In your Makefile, compile with your main application file, cse320_fork.c, and cse320_settimer.c.

Before calling cse320_fork(), make sure to call cse320_settimer(n), where n is the number of seconds, to initialize the SIGALRM timer.
