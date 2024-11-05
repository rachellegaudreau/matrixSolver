CC = gcc
CFLAGS = -Wall -std=c18 -ggdb

matrix : matrix.c
	$(CC) $(CFLAGS) -o matrix matrix.c

test : matrix
	./matrix 2 2 1 2 3 4 1 2 3 4
	./matrix 3 3 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9

clean :
	-rm matrix
