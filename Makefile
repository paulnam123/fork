all:
	gcc -g -Wall part1.c -o part1
	gcc -g -Wall test.c -o test
clean:
	rm -f part1
	rm -f test
