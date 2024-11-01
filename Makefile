CC = gcc
CFLAGS = -Wall -std=c18 -ggdb

test : matrix
	./matrix 3 3 <testEntriesMedium.txt

matrix : matrix.c
	$(CC) $(CFLAGS) -o matrix matrix.c

clean :
	-rm matrix
