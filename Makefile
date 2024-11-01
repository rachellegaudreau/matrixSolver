CC = gcc
CFLAGS = -Wall -std=c18 -ggdb

test : matrix
	./matrix 2 2 1 2 3 4 1 2 3 4
	./matrix 3 3 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9
	./matrix 5 5 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

matrix : matrix.c
	$(CC) $(CFLAGS) -o matrix matrix.c

clean :
	-rm matrix
