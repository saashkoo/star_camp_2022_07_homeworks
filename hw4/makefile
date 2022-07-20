all:
	gcc program.c -E -o program.i
	gcc program.i -S -o program.s
	gcc program.s -c -o program.o
	gcc swap.c -E -o swap.i
	gcc swap.i -S -o swap.s
	gcc swap.s -c -o swap.o
	gcc swap.o program.o -o program
	./program
