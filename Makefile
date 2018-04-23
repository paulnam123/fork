part1:
	gcc -g -Wall part1.c -o part1
	gcc -g -Wall test.c -o test
part3:
	gcc -g -Wall main.c cse320_settimer.c cse320_fork.c -o part3
clean:
	rm -f part1
	rm -f test
	rm -f part2
	rm -f part3
