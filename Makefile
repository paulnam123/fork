all:
	gcc -g main.c -o part1
	gcc -g test.c -o test
clean:
	rm -f part1
	rm -f test
